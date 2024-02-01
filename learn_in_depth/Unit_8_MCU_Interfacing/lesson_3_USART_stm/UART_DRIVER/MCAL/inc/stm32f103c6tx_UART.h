/*
 * stm32f103c6tx_RCC.h
 *
 *  Created on: Jan 30, 2024
 *      Author: ahmed
 */

#ifndef INC_STM32F103C6TX_UART_H_
#define INC_STM32F103C6TX_UART_H_
/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */

#include "stm32f103c6tx.h"
#include "stm32f103c6tx_GPIO.h"
#include "stm32f103c6tx_RCC.h"

/* ================================================================ */
/* ============= User type definitions (structures) =============== */
/* ================================================================ */

typedef struct
{
	uint8_t		USART_Mode;			// Specifies TX/RX Enable/Disable
									// This parameters must be set based on @Ref UART_Mode_define

	uint32	BaudRate;			// This member to configure the Baud Rate
									// This parameters must be set based on @Ref UART_BaudRate_define

	uint8_t		Payload_Length;		// Specifies the number of data bits transmitted or received in a frame
									// This parameters must be set based on @Ref UART_Payload_Length_define

	uint8_t		Parity;				// Specifies the parity mode
									// This parameters must be set based on @Ref UART_Parity_define

	uint8_t		StopBits;			// Specifies the number of stop bits
									// This parameters must be set based on @Ref UART_StopBits_define

	uint8_t		HwFlowCtl;			// Specifies whether the hardware flow control mode is enabled or disabled
									// This parameters must be set based on @Ref UART_HwFlowCtl_define

	uint8_t		IRQ_Enable;			// enable or disable the interrupt
									// This parameters must be set based on @Ref UART_IRQ_define

	void (* P_IRQ_CallBack)(void);	// Set the C Function() which will be called once the IRQ Happen
}USART_Config_t;

/* ================================================================ */
/* =============== Macros Configuration References ================ */
/* ================================================================ */

// @Ref UART_Mode_define
#define UART_Mode_RX				(uint32)(1<<2)	// bit 2 RE: transmitter is enabled
#define UART_Mode_TX				(uint32)(1<<3)	// bit 3 TE: transmitter is enabled
#define UART_Mode_TX_RX				(uint32)(1<<3 | 1<<2)

// @Ref UART_BaudRate_define
#define UART_BaudRate_2400			2400
#define UART_BaudRate_9600			9600
#define UART_BaudRate_19200			19200
#define UART_BaudRate_57600			57600
#define UART_BaudRate_115200		115200
#define UART_BaudRate_230400		230400
#define UART_BaudRate_460800		460800
#define UART_BaudRate_921600		921600
#define UART_BaudRate_225000		2250000
#define UART_BaudRate_4500000		4500000

// @Ref UART_Payload_Legth_define
#define UART_Payload_Length_8B		(uint32)(0)
#define UART_Payload_Length_9B		(uint32)(1<<12) 	// Bit 12 M: Word length

// @Ref UART_Parity_define
#define UART_Parity_NONE			(uint32)(0)
#define UART_Parity_EVEN			((uint32)(1<<10)) 		// Bit 10 PCE: Parity control enable
#define UART_Parity_ODD				((uint32)(1<<10 | 1<<9)) 	// Bit 9 PS: Parity selection

// @Ref UART_StopBits_define
#define UART_StopBits_half			(uint32)(1<<12) 	// Bits 13:12 STOP: STOP bits
#define UART_StopBits_1				(uint32)(0)	  	// Bits 13:12 STOP: STOP bits
#define UART_StopBits_1_half		(uint32)(3<<12)	// Bits 13:12 STOP: STOP bits
#define UART_StopBits_2				(uint32)(2<<12)	// Bits 13:12 STOP: STOP bits

// @Ref UART_HwFlowCtl_define
#define UART_HwFlowCtl_NONE			(uint32)(0)
#define UART_HwFlowCtl_RTS			(uint32)(1<<8)	// Bit 8 RTSE: RTS enable
#define UART_HwFlowCtl_CTS			(uint32)(1<<9) 	// Bit 9 CTSE: CTS enable
#define UART_HwFlowCtl_RTS_CTS		(uint32)(1<<8 | 1<<9)

// @Ref UART_IRQ_Enable_define
#define UART_IRQ_Enable_NONE		(uint32)(0)
#define UART_IRQ_Enable_TXE			(uint32)(1<<7)	// Bit 7 TXEIE: TXE interrupt enable // Transmit data register empty
#define UART_IRQ_Enable_TC			(uint32)(1<<6)	// Bit 6 TCIE: Transmission complete interrupt enable // Transmission complete
#define UART_IRQ_Enable_RXNEIE		(uint32)(1<<5)	// Bit 5 RXNEIE: RXNE interrupt enable // Received data ready to be read
#define UART_IRQ_Enable_PE			(uint32)(1<<8)	// Bit 8 PEIE: PE interrupt enable // Parity error

typedef enum
{
	disable,
	enable
}Polling_Mechanism_t;



/* ================================================================ */
/* ===================== BaudRate Calculation ===================== */
/* ================================================================ */

// USARTDIV = fclk / (16 * Baudrate)
// USARTDIV_MUL100 = uint32((100 * fclk ) / ( 16 * Baudrate) == (25 * fclk) / (4 * Baudrate))
// DIV_Mantissa_MUL100 = Integer Part (USARTDIV) * 100
// DIV_Mantissa = Integer Part (USARTDIV)
// DIV_Fraction = (( USARTDIV_MUL100 - DIV_Mantissa_MUL100 ) *16) / 100

#define USARTDIV(_PCLK_, _BAUD_)				(uint32) (_PCLK_/(16 * _BAUD_ ))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)			(uint32) ((25 * _PCLK_ ) / (4 * _BAUD_))
#define Mantissa_MUL100(_PCLK_, _BAUD_)			(uint32) (USARTDIV(_PCLK_, _BAUD_) * 100)
#define Mantissa(_PCLK_, _BAUD_)				(uint32) (USARTDIV(_PCLK_, _BAUD_ ))
#define DIV_Fraction(_PCLK_, _BAUD_)			(uint32) (((USARTDIV_MUL100(_PCLK_, _BAUD_) - Mantissa_MUL100(_PCLK_, _BAUD_) )*16) / 100)
#define UART_BRR_Register(_PCLK_, _BAUD_)		(( Mantissa (_PCLK_, _BAUD_ ) ) << 4 )|((DIV_Fraction(_PCLK_, _BAUD_)) & 0xF )
/* ================================================================ */
/* =========== APIs Supported by "MCAL USART DRIVER" ============== */
/* ================================================================ */

void MCAL_UART_Init(USART_Typedef_t* USARTx, USART_Config_t* UART_Config);
void MCAL_UART_DeInit(USART_Typedef_t* USARTx);

void MCAL_UART_GPIO_Set_Pins(USART_Typedef_t* USARTx);

void MCAL_UART_SendData(USART_Typedef_t* USARTx, uint16_t* pTxBuffer, Polling_Mechanism_t PollingEn);
void MCAL_UART_ReceiveData(USART_Typedef_t* USARTx, uint16_t* pRxBuffer, Polling_Mechanism_t PollingEn);

void MCAL_UART_WAIT_TC(USART_Typedef_t* USARTx);



#endif /* INC_STM32F103C6TX_RCC_H_ */
