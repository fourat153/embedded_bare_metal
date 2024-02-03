/*
 * stm32f103c6tx_RCC.h
 *
 *  Created on: Jan 30, 2024
 *      Author: ahmed
 */

#ifndef INC_STM32F103C6TX_RCC_H_
#define INC_STM32F103C6TX_RCC_H_

#define	GET_BIT(reg,n)				(((reg)>>(n))&1)
#define SET_BIT(reg,n)				(reg|=(1<<n))
#define CLR_BIT(reg,n)				(reg&=~(1<<n))
#define TOGGLE_BIT(reg,n)			(reg^=(1<<n))

#define	GET_REG(reg)				(reg)
#define SET_REG(reg)				((reg)=0XFF)
#define CLR_REG(reg)				((reg)=0X00)
#define TOGGLE_REG(reg)				((reg)^=0xFF)
#define ASSIGN_REG(reg,value)		((reg)=(value))

#endif /* INC_STM32F103C6TX_RCC_H_ */
