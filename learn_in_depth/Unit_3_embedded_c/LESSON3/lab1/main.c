#include <stdint.h>
#define RCC_BASE     0x40021000
#define GPIOA_BASE   0x40010800
#define RCCAPB2ENR   *(volatile uint32_t * ) (RCC_BASE + 0X18) 
#define GPIOA_CRH    *(volatile uint32_t * ) (GPIOA_BASE + 0X04)
#define GPIO_ODR     *(volatile uint32_t * ) (GPIOA_BASE + 0X0C)

#define RCC_IOPAEN   ( 1<<2)
#define GPIOA13      (1 << 13)

typedef union main
{
    uint32_t allfild ; 
    struct 
    {
      uint32_t reserved : 13;
      uint32_t  pin_13: 1 ;
    }pins;

}ODR_t;

volatile  ODR_t * ODR = (volatile ODR_t * )(GPIOA_BASE + 0X0C) ;
int main() 
{
RCCAPB2ENR |= RCC_IOPAEN;
GPIOA_CRH &= 0xFF0FFFFF;
GPIOA_CRH |= 0x00200000;
while (1)
{
    ODR->pins.pin_13 = 1; 
    for (int i = 0 ; i < 500 ; i++ ); 
    ODR->pins.pin_13 = 0; 
    for (int i = 0 ; i < 500 ; i++ ); 
}
 

return 0 ; 
}

