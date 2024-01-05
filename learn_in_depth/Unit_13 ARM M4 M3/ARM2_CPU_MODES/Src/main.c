/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "../stm_driver/inc/Stm32_F103C6_EXTI_driver.h"
#include "../stm_driver/inc/Stm32_F103C6_gpio_driver.h"


uint16_t IRQ_Flag = 0;

void EXTI9_CallBack(void)
{
	IRQ_Flag = 1;

}

int main(void)
{

	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();


	EXTI_PinConfig_t EXTI_Cfg;
	EXTI_Cfg.EXTI_PIN = EXTI9PB9;
	EXTI_Cfg.TriggerCase = EXTI_Trigger_RISING;
	EXTI_Cfg.P_IRQ_CallBack = EXTI9_CallBack;
	EXTI_Cfg.IRQ_Enable = EXTI_IRQ_Enable;

	MCAL_EXTI_GPIO_Init(&EXTI_Cfg);

	IRQ_Flag = 1;

	while(1)
	{
		if(IRQ_Flag)
		{

			IRQ_Flag = 0;
		}


	}
}

