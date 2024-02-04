/*
 * stm32f103c6tx_RCC.h
 *
 *  Created on: Jan 30, 2024
 *      Author: ahmed
 */

#ifndef INC_STM32F103C6TX_RCC_H_
#define INC_STM32F103C6TX_RCC_H_

#include "stm32f103c6tx.h"
#include "stm32f103c6tx_GPIO.h"

#define HSE_CLK 		(uint32)16000000
#define HSI_RC_CLK 		(uint32)8000000

uint32 MCAL_RCC_GetSYS_CLKFreq(void);

uint32 MCAL_RCC_GetHCLKFreq(void);

uint32 MCAL_RCC_GetPCLK1Freq(void);
uint32 MCAL_RCC_GetPCLK2Freq(void);


#endif /* INC_STM32F103C6TX_RCC_H_ */
