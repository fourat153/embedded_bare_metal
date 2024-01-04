#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

typedef volatile unsigned int vuint32_t ;


// register address
#define GPIOA_BASE  0x40010800
#define GPIOA_CRH   *(vuint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR   *(vuint32_t *)(GPIOA_BASE + 0x0C)

#define RCC_BASE    0x40021000
#define RCC_APB2ENR *(vuint32_t *)(RCC_BASE + 0x18)
#define RCC_CFGR    *(vuint32_t *)(RCC_BASE + 0x04)


int main(void)
{
    RCC_APB2ENR |= (1<<2);      // Enable Clock for GPIOA
    RCC_CFGR    |= (0b100<<8);  // Set APB1 Prescale related to the clock tree to \2
    RCC_CFGR    |= (0b101<<11); // Set APB2 Prescale related to the clock tree to \4

    //Init GPIOA
    GPIOA_CRH &= 0xFF0FFFFF;
    GPIOA_CRH |= 0x00200000;
    while(1)
    {
        GPIOA_ODR |= 1<<13 ; // turn on 
        for (int i = 0; i < 5000; i++); // mimic delay
        GPIOA_ODR &= ~(1<<13) ; //turn off
        for (int i = 0; i < 5000; i++); // mimic delay
    }
}
