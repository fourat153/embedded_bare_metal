#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


typedef volatile unsigned int vuint32_t ;


// GPIO
#define GPIOA_BASE  0x40010800
#define GPIOA_CRH   *(vuint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR   *(vuint32_t *)(GPIOA_BASE + 0x0C)
#define GPIOx_CRL   *(vuint32_t *)(GPIOA_BASE + 0x00)

// RCC
#define RCC_BASE    0x40021000
#define RCC_APB2ENR *(vuint32_t *)(RCC_BASE + 0x18)
#define RCC_CFGR    *(vuint32_t *)(RCC_BASE + 0x04)
#define RCC_CR      *(vuint32_t *)(RCC_BASE + 0x00)

// EXTI
#define EXTI_BASE   0x40010400
#define EXTI_IMR    *(vuint32_t *)(EXTI_BASE + 0x00)
#define EXTI_RTSR   *(vuint32_t *)(EXTI_BASE + 0x08)
#define EXTI_PR     *(vuint32_t *)(EXTI_BASE + 0x14)
#define NVIC_ISER0  *(vuint32_t *)(0xE000E100)

// AFIO -> alternate function 
#define AFIO_BASE   0x4001000
#define AFIO_EXTICR1 *(vuint32_t *)(AFIO_BASE + 0x08)

void RCC_init(void)
{
    RCC_CFGR    |= (0b10<<0);       // System clock switch to PLL
    RCC_CFGR    |= (0b0110<<18);    // PLL multiplication factor * 8
    RCC_CFGR    |= (0b100<<8);      // Set APB1 Prescale to \2
    RCC_CFGR    |= (0b101<<11);     // Set APB2 Prescale to \4
    RCC_APB2ENR |= (1<<2);          // Enable Clock for GPIOA
    RCC_CR      |= (1<<24);         // PLL Enable
    RCC_APB2ENR |= (1<<0);          // Alternate function IO clock enable
}

void GPIO_init(void)
{
    //Init GPIOA
    GPIOA_CRH &= 0xFF0FFFFF;
    GPIOA_CRH |= 0x00200000;

    GPIOx_CRL |= (1<<2); // Floating input mode 

    AFIO_EXTICR1 = 0x0; // External interrupt configuration register for PA0
}

void EXTI_init(void)
{
    EXTI_IMR |= (1<<0); // Interrupt mask register enable for EXTI0
    EXTI_RTSR |= (1<<0); //  Rising trigger enabled for EXTI0
    NVIC_ISER0 |= (1<<6); // Enable NVIC IRQ 6 (EXTI0)
}

int main(void)
{
    RCC_init();
    GPIO_init();
    EXTI_init();

    while(1);
}

void EXTI0_IRQHandler()
{
    // Toggle LED on pin 13
    GPIOA_ODR ^= (1<<13) ;

    // Clear pending status of EXTI0
    EXTI_PR |= (1<<0);
}
