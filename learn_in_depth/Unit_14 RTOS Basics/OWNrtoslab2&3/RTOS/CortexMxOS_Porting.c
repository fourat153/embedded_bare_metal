#include "../RTOS/inc/CortexMxOS_Porting.h"

// Enabling all faults for possible errors (Accessing memories etc.)

void HardFault_Handler()
{
	while(1);
}

void MemManage_Handler()
{
	while(1);
}

void BusFault_Handler()
{
	while(1);
}

void UsageFault_Handler()
{
	while(1);
}





// Consider it as C function, but don't push anything in stack, it is assembly, force the compiler to not add anything
__attribute ((naked))  void SVC_Handler()
{
	// Check EXC_Return to see if you were MSP or PSP
	__asm("tst lr,#4 \n\t"
			"ITE EQ \n\t"
			"mrseq r0,MSP \n\t"
			"mrsne r0,PSP \n\t"
			"B OS_SVC_Services");
}


void Trigger_OS_PendSV()
{
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
}



void HW_Init()
{
	// Initialize clock tree (RCC --> SysTick Timer & CPU) 8MHz
	// 8 MHz (By default)
	// 1 count = 0.125 us
	// X count -> 1ms
	// X = 8000 counts

	// Decrease priority of pendSV to be less than or equal systick timer
	// systick = 14

	__NVIC_SetPriority(PendSV_IRQn, 15);


}




void Start_Ticker()
{
	// 8 MHz (By default)
	// 1 count = 0.125 us
	// X count -> 1ms
	// X = 8000 counts

	SysTick_Config(8000);

}


uint8_t SystTickIndication;

void SysTick_Handler(void)
{
	SystTickIndication ^= 1;
	// Decide what Next (To determine Pcurrent, Pnext)
	Decide_WhatNextTask();
	// Trigger PendSv(Switch Context & Restore)
	Trigger_OS_PendSV();
}
