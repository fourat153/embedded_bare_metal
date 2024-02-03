/*
 * test_uart_polling.c
 *
 *  Created on: Feb 1, 2024
 *      Author: ahmed
 */


#include "../../UART/MCAL/inc/stm32f103c6tx.h"
#include "../../UART/MCAL/inc/stm32f103c6tx_GPIO.h"
#include "../../UART/MCAL/inc/stm32f103c6tx_EXTI.h"
#include "../../UART/MCAL/inc/stm32f103c6tx_UART.h"


/* ========= Global variables ========== */
uint16_t  data  ;

/* ========== Prototypes ========= */
static void clock_init(void);
void callback_uart(void) ;

/* =========== Main Program ========== */
void USART_Test_1_Debugging_Using_interrupt(void)
{
	/* Initializing the clock */
	clock_init();

	/* Configuration of USART1 */
	USART_Config_t USART1_Config;

	USART1_Config.BaudRate = UART_BaudRate_115200;
	USART1_Config.HwFlowCtl = UART_HwFlowCtl_NONE;
	USART1_Config.IRQ_Enable = UART_IRQ_Enable_RXNEIE ;
	USART1_Config.P_IRQ_CallBack = callback_uart;
	USART1_Config.Parity = UART_Parity_NONE;
	USART1_Config.Payload_Length = UART_Payload_Length_8B;
	USART1_Config.StopBits = UART_StopBits_1;
	USART1_Config.USART_Mode = UART_Mode_TX_RX;


	MCAL_UART_Init(USART1, &USART1_Config);
	MCAL_UART_GPIO_Set_Pins(USART1);

	while(1)
	{

	}
}

/* ======== clock Initialize definition ======= */
static void clock_init(void)
{
	/* Enable clock GPIOA */
	RCC_GPIOA_CLK_EN();

	/* Enable clock GPIOB */
	RCC_GPIOB_CLK_EN();

	/* Enable Clock For AFIO */
	RCC_AFIO_CLK_EN();
}
void callback_uart(void)
{
	MCAL_UART_SendData(USART1, &data, enable);

    MCAL_UART_ReceiveData(USART1, &data, enable);
}
