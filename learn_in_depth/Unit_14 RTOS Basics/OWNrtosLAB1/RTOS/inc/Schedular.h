#ifndef INC_SCHEDULAR_H_
#define INC_SCHEDULAR_H_

#include "CortexMxOS_Porting.h"
//#include "My_RTOS_FIFO.h"


typedef enum
{
	NO_ERROR,
	ReadyQueue_Init_Error,
	Task_Exceeded_Stack_Size

}MYRTOS_errorID;


typedef struct{
	uint32_t Stack_Size;		// Entered by the user
	uint8_t Priority;
	void (*P_TaskEntry)(void);   // A pointer to the C function that this task is linked to
	uint32_t _S_PSP_Task;    // Start of this task stack (Not entered by the user, calculate by OS)
	uint32_t _E_PSP_Task;	  // (Not entered by the user)
	uint32_t *Current_PSP;    // Current_PSP points to the location that currently pointed by PSP of this task (Not entered by the user)
	char TaskName[30];    // Useful in debugging
	enum{
		Suspend,
		Waiting,
		Ready,
		Running
	}Task_State;   				// (Not entered by the user)


	struct{
		enum{
			Blocking_Disable,
			Blocking_Enable
		}Block_Timing;
		uint32_t Ticks_Count;   // Blocked in suspend state
	}Time_Waiting;
}Task_Config;


// APIs
MYRTOS_errorID MYRTOS_Init(void);
MYRTOS_errorID MYRTOS_Create_Task(Task_Config* taskReference);


#endif /* INC_SCHEDULAR_H_ */
