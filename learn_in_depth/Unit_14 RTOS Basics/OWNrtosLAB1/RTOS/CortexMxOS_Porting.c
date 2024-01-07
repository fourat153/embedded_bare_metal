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



void HW_Init()
{
	// Initialize clock tree (RCC --> SysTick Timer & CPU) 8MHz
	// 8 MHz (By default)
	// 1 count = 0.125 us
	// X count -> 1ms
	// X = 8000 counts
}
