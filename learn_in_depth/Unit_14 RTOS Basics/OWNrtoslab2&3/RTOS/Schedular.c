#include "../RTOS/inc/Schedular.h"
#include "../RTOS/inc/My_RTOS_FIFO.h"
#include "../CMSIS_V5/ARMCM3.h"

#include "string.h"


FIFO_Buffer_t ReadyQueue;
Task_Config *ReadyQueueFIFO[100];

Task_Config MYRTOS_IdleTask;


// OS states (in .c not .h to not being seen by the user)

struct{
	Task_Config* OS_Tasks[100];  // Tasks(schedular) table (Can hold up to 100 tasks)
	uint32_t _S_MSP;   // Pointed to the start of the SRAM (From startup)
	uint32_t _E_MSP;   // Then this will act as the size of the stack
	uint32_t PSP_Task_Locator;
	uint32_t ActiveTasksNum;
	Task_Config* CurrentTaskExecuted;
	Task_Config* NextTaskTobeExecuted;
	enum{
		OS_Suspend,
		OS_Running
	}OS_Modes_ID;
}OS_Control;



typedef enum{
	SVC_ActivateTask,
	SVC_TerminateTask,
	SVC_TaskWaitingTime
}SVC_ID;


// (Handler Mode)
void BubbleSort_SchedularTable()
{
	unsigned int i,j,n;
	Task_Config* TempTask;

	n = OS_Control.ActiveTasksNum;

	for(i=0 ; i<n-1 ; i++)
	{
		for(j=0 ; j<n-i-1 ; j++)
		{
			// Higher priority first
			if(OS_Control.OS_Tasks[j]->Priority > OS_Control.OS_Tasks[j+1]->Priority)
			{
				TempTask = OS_Control.OS_Tasks[j];
				OS_Control.OS_Tasks[j] = OS_Control.OS_Tasks[j+1];
				OS_Control.OS_Tasks[j+1] = TempTask;
			}
		}
	}



}


// (Handler Mode)
void MYRTOS_Update_SchedulerTable()
{
	Task_Config* TempTaskDequeue = NULL;
	Task_Config *P_Task = NULL ,*P_nextTask = NULL;
	int i = 0;

	// Update Scheduler table

	// 1- Bubble Sort Sch_Table in OS_Control --> OS_Tasks[100]
	//    based on priority (high then low)
	BubbleSort_SchedularTable();

	// 2- Free Ready Queue
	while(FIFO_Deqeue(&ReadyQueue, &TempTaskDequeue /*Pointer to pointer*/) != FIFO_Empty);


	// 3- Update Ready Queue
	while(i<OS_Control.ActiveTasksNum)
	{
		P_Task = OS_Control.OS_Tasks[i];
		P_nextTask = OS_Control.OS_Tasks[i+1];

		if(P_Task->Task_State != Suspend){

			// If we reached the end of the available Tasks
			// Then add the last one to the ready Queue and update its state
			// Because if we assumed its priority = 7, then the next one would be empty which is suspend(0) by default
			// Then we can't rely on the comparison of priority only

			if(P_nextTask->Task_State == Suspend)
			{
				FIFO_Enqeue(&ReadyQueue, P_Task);
				P_Task->Task_State = Ready;
				break;
			}

			// If the task is higher priority than the next one
			// Then add it to the readyQueue and break

			if(P_Task->Priority < P_nextTask->Priority)
			{
				FIFO_Enqeue(&ReadyQueue, P_Task);
				P_Task->Task_State = Ready;
				break;
			}else if(P_Task->Priority == P_nextTask->Priority)
			{
				// In case of same priority (Round robin)
				// Then push P_Task, and make P_Task = P_nextTask, and P_nextTask++
				FIFO_Enqeue(&ReadyQueue, P_Task);
				P_Task->Task_State = Ready;
				// NO BREAK TO KEEP ADDING EQUAL "P" TASKS
			}else{
				// Bubble Sort failed, can't happen
				break;
			}
		}


		i++;
	}

}



// (Handler Mode)
void Decide_WhatNextTask()
{
	// If ready Queue && OS_Control->CurrentTask != Suspend
	// Then make the current task run again till termination
	if((ReadyQueue.counter == 0) && (OS_Control.CurrentTaskExecuted->Task_State != Suspend))
	{
		OS_Control.CurrentTaskExecuted->Task_State = Running;
		FIFO_Enqeue(&ReadyQueue, OS_Control.CurrentTaskExecuted);
		// Make the current task next also, to run it again, if context switch happened
		OS_Control.NextTaskTobeExecuted = OS_Control.CurrentTaskExecuted;
	}else{
		FIFO_Deqeue(&ReadyQueue, &OS_Control.NextTaskTobeExecuted);
		OS_Control.NextTaskTobeExecuted->Task_State = Running;
		// Update readyQueue to maintain round robin (if same priority)
		if((OS_Control.CurrentTaskExecuted->Priority == OS_Control.NextTaskTobeExecuted->Priority) && (OS_Control.CurrentTaskExecuted != Suspend))
		{
			FIFO_Enqeue(&ReadyQueue, OS_Control.CurrentTaskExecuted);
			OS_Control.CurrentTaskExecuted->Task_State = Ready;
		}
	}
}



// To execute specific OS service(Handler Mode)
void OS_SVC_Services(int* StackFramePointer)
{
	// OS_SVC_Set stack --> r0 = argument 0 = StackFramePointer
	// OS_SVC_Set stack --> r0,r1,r2,r3,r12,lr,pc,xpsr

	unsigned char SVC_Number;

	SVC_Number = *((unsigned char*)(((unsigned char*)StackFramePointer[6]) - 2));


	switch(SVC_Number)
	{
	case SVC_ActivateTask:
	case SVC_TerminateTask:
		// Update Scheduler table & Ready Queue
		MYRTOS_Update_SchedulerTable();

		// if OS is in running state
		if(OS_Control.OS_Modes_ID == OS_Running)
		{
			// Idle task would be called manually
			if(strcmp(OS_Control.CurrentTaskExecuted->TaskName,"idleTask")!=0)
			{
				// Decide what next(Enqueue/Dequeue)
				Decide_WhatNextTask();

				// Trigger OS_PendSV (Switch Context/Restore)
				Trigger_OS_PendSV();

			}
		}

		break;

	case SVC_TaskWaitingTime:
		break;
	}

}



// Will be used in context switching
__attribute ((naked)) void PendSV_Handler()
{
	// Switch context & Restore


	/************************************
	 * Save context for the current task
	 ***********************************/

	// Get current task "Current PSP from CPU Register after pushing xpsr-->r0"
	// And put this value inside current PSP of the current task
	OS_GET_PSP(OS_Control.CurrentTaskExecuted->Current_PSP);

	// Using this PSP(pointer in the current task) to store (R4 to R11)
	OS_Control.CurrentTaskExecuted->Current_PSP--;
	__asm volatile("mov %0,r4":"=r" (*(OS_Control.CurrentTaskExecuted->Current_PSP)));
	OS_Control.CurrentTaskExecuted->Current_PSP--;
	__asm volatile("mov %0,r5":"=r" (*(OS_Control.CurrentTaskExecuted->Current_PSP)));
	OS_Control.CurrentTaskExecuted->Current_PSP--;
	__asm volatile("mov %0,r6":"=r" (*(OS_Control.CurrentTaskExecuted->Current_PSP)));
	OS_Control.CurrentTaskExecuted->Current_PSP--;
	__asm volatile("mov %0,r7":"=r" (*(OS_Control.CurrentTaskExecuted->Current_PSP)));
	OS_Control.CurrentTaskExecuted->Current_PSP--;
	__asm volatile("mov %0,r8":"=r" (*(OS_Control.CurrentTaskExecuted->Current_PSP)));
	OS_Control.CurrentTaskExecuted->Current_PSP--;
	__asm volatile("mov %0,r9":"=r" (*(OS_Control.CurrentTaskExecuted->Current_PSP)));
	OS_Control.CurrentTaskExecuted->Current_PSP--;
	__asm volatile("mov %0,r10":"=r" (*(OS_Control.CurrentTaskExecuted->Current_PSP)));
	OS_Control.CurrentTaskExecuted->Current_PSP--;
	__asm volatile("mov %0,r11":"=r" (*(OS_Control.CurrentTaskExecuted->Current_PSP)));


	// Save the current value of PSP
	// Already saved in the current PSP of this task


	/************************************
	 * Restore context for the next task
	 ***********************************/


	OS_Control.CurrentTaskExecuted = OS_Control.NextTaskTobeExecuted;
	OS_Control.NextTaskTobeExecuted = NULL;


	__asm volatile("mov r11,%0": : "r" (*(OS_Control.CurrentTaskExecuted->Current_PSP)));
	OS_Control.CurrentTaskExecuted->Current_PSP++;
	__asm volatile("mov r10,%0": : "r" (*(OS_Control.CurrentTaskExecuted->Current_PSP)));
	OS_Control.CurrentTaskExecuted->Current_PSP++;
	__asm volatile("mov r9,%0": : "r" (*(OS_Control.CurrentTaskExecuted->Current_PSP)));
	OS_Control.CurrentTaskExecuted->Current_PSP++;
	__asm volatile("mov r8,%0": : "r" (*(OS_Control.CurrentTaskExecuted->Current_PSP)));
	OS_Control.CurrentTaskExecuted->Current_PSP++;
	__asm volatile("mov r7,%0": : "r" (*(OS_Control.CurrentTaskExecuted->Current_PSP)));
	OS_Control.CurrentTaskExecuted->Current_PSP++;
	__asm volatile("mov r6,%0": : "r" (*(OS_Control.CurrentTaskExecuted->Current_PSP)));
	OS_Control.CurrentTaskExecuted->Current_PSP++;
	__asm volatile("mov r5,%0": : "r" (*(OS_Control.CurrentTaskExecuted->Current_PSP)));
	OS_Control.CurrentTaskExecuted->Current_PSP++;
	__asm volatile("mov r4,%0": : "r" (*(OS_Control.CurrentTaskExecuted->Current_PSP)));
	OS_Control.CurrentTaskExecuted->Current_PSP++;


	// Update PSP to point to the task we want enter
	OS_SET_PSP(OS_Control.CurrentTaskExecuted->Current_PSP);

	__asm volatile("BX LR") ;
}


void MYRTOS_Create_MainStack()
{
	OS_Control._S_MSP = &_estack;
	OS_Control._E_MSP = OS_Control._S_MSP - MainStackSize;
	// Align 8 Bytes space between Main stack and Process stack
	OS_Control.PSP_Task_Locator = (OS_Control._E_MSP - 8);
}

uint8_t idleTaskIndication;

void MyRTOS_Idle_Task()
{
	while(1)
	{
		idleTaskIndication^=1;
		__asm("NOP");
	}
}



MYRTOS_errorID MYRTOS_Init()
{
	MYRTOS_errorID ErrorState = NO_ERROR;

	// Update OS Mode (Suspend)
	OS_Control.OS_Modes_ID = OS_Suspend;

	// Specify the Main stack for the OS
	MYRTOS_Create_MainStack();



	// Create OS Ready Queue
	if((FIFO_Init(&ReadyQueue, ReadyQueueFIFO, 100)) != FIFO_No_Error)
		ErrorState += ReadyQueue_Init_Error;


	// Configure idle task
	strcpy(MYRTOS_IdleTask.TaskName,"idleTask");
	MYRTOS_IdleTask.Priority = 255;    // The least priority
	MYRTOS_IdleTask.P_TaskEntry = MyRTOS_Idle_Task;
	MYRTOS_IdleTask.Stack_Size = 300;  // Bytes

	ErrorState += MYRTOS_Create_Task(&MYRTOS_IdleTask);

	return ErrorState;
}


void MYRTOS_Create_Stack(Task_Config* taskReference)
{
	/** Task Frame
	 * 	//// (Automatically pushed by processor)
	 * 	- xpsr
	 * 	- pc (next instrcution to be executed to this task)
	 * 	- lr (Return register which is saved in cpu while task running before switching)
	 * 	- r12
	 * 	- r4
	 * 	- r3
	 * 	- r2
	 * 	- r1
	 * 	- r0
	 *
	 * 	//// (Manually defined to save the value of registers (Manually pushed and restored))
	 * 	r5, r6, r7, r8, r9, r10, r11
	 */
	taskReference->Current_PSP = taskReference->_S_PSP_Task;

	taskReference->Current_PSP--;
	*(taskReference->Current_PSP) = 0x01000000;  // Dummy psr (by default T=1 Thumb2) to avoid bus fault

	taskReference->Current_PSP--;
	*(taskReference->Current_PSP) = (unsigned int)(taskReference->P_TaskEntry);   // PC value

	taskReference->Current_PSP--;
	*(taskReference->Current_PSP) = (unsigned int)(0xFFFFFFFD);   // (Dummy value)As if LR (This function came from interrupt

	// The rest is 13 registers we want to push with 0 for now
	for(int j=0;j<13;j++)
	{
		taskReference->Current_PSP--;
		*(taskReference->Current_PSP) = 0;
	}
}



MYRTOS_errorID MYRTOS_Create_Task(Task_Config* taskReference)
{
	MYRTOS_errorID ErrorState = NO_ERROR;

	// Create its own PS Stack
	taskReference->_S_PSP_Task = OS_Control.PSP_Task_Locator;
	taskReference->_E_PSP_Task = taskReference->_S_PSP_Task -  taskReference->Stack_Size;

	// Check that task size isn't exceeding Process stack size
	if(taskReference->_E_PSP_Task < (uint8_t)(&_eheap))
		return Task_Exceeded_Stack_Size;

	// Align 8 Byte for the next task PS stack
	OS_Control.PSP_Task_Locator = taskReference->_E_PSP_Task - 8;

	// - _S_PSP_Task
	// - Task stack
	// - _E_PSP_Task

	// - _eheap


	// Initialize PS Task Stack
	MYRTOS_Create_Stack(taskReference);

	// Update scheduler table
	OS_Control.OS_Tasks[OS_Control.ActiveTasksNum] = taskReference;
	OS_Control.ActiveTasksNum++;

	// Task state update (Suspend mode)
	taskReference->Task_State = Suspend;

	return ErrorState;

}




void MYRTOS_OS_SVC_Set(SVC_ID ID)
{
	switch(ID)
	{
	case SVC_ActivateTask:
		__asm("svc #0x00");
		break;

	case SVC_TerminateTask:
		__asm("svc #0x01");
		break;

	case SVC_TaskWaitingTime:
		__asm("svc #0x02");
		break;
	}
}




MYRTOS_errorID MYRTOS_Activate_Task(Task_Config* taskReference)
{
	MYRTOS_errorID ErrorState = NO_ERROR;

	// Update task state
	taskReference->Task_State = Waiting;


	// Update Scheduler table
	MYRTOS_OS_SVC_Set(SVC_ActivateTask);



	return ErrorState;
}




MYRTOS_errorID MYRTOS_Terminate_Task(Task_Config* taskReference)
{
	MYRTOS_errorID ErrorState = NO_ERROR;

	taskReference->Task_State = Suspend;







	return ErrorState;
}





void MYRTOS_START_OS()
{
	OS_Control.OS_Modes_ID = OS_Running;
	// Set default "Current task == Idle task"
	OS_Control.CurrentTaskExecuted = &MYRTOS_IdleTask;

	// Activate Idle task
	MYRTOS_Activate_Task(&MYRTOS_IdleTask);


	// Start ticker
	Start_Ticker();

	OS_SET_PSP(OS_Control.CurrentTaskExecuted->Current_PSP);

	// Switch thread mode from MSP to PSP
	OS_SWITCH_SP_to_PSP;
	OS_SWITCH_TO_UNPRIVILIGE;
	MYRTOS_IdleTask.P_TaskEntry();
}
