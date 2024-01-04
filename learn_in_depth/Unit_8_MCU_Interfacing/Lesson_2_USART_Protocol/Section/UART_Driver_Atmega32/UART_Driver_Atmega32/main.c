#include "ATmega32_GPIO_Driver.h"
#include "ATmega32_USART_Driver.h"
#include "HAL/LCD/LCD.h"

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

uint8_t data = 0;

int main(void)
{
	LCD_INIT();
	MCAL_USART_Init();
	
	MCAL_USART_Send('M');
	MCAL_USART_Send('I');
	MCAL_USART_Send('N');
	MCAL_USART_Send('A');
    
	while (1) 
    {
		LCD_GOTOXY(0,0);
		data = MCAL_USART_Receive();
		LCD_WRITE_CHAR(data);
    }
	
	return 0;
}

