#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


typedef volatile unsigned int vuint32_t ;


// register address to map the gpio base adress 
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *(vuint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR *(vuint32_t *)(GPIOA_BASE + 0x0C)

// register address to map the clock base  adress 
#define RCC_BASE 0x40021000
#define RCC_APB2ENR *(vuint32_t *)(RCC_BASE + 0x18)



int main(void)
{
	RCC_APB2ENR |= (1<<2); // Enable Clock for GPIOA


	//Init GPIOA
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
	while(1)
	{
		GPIOA_ODR |= 1<<13 ;
		for (int i = 0; i < 5000; i++); // mimic delay 
		GPIOA_ODR &= ~(1<<13) ;
		for (int i = 0; i < 5000; i++); // mimic delay 
	}
}
