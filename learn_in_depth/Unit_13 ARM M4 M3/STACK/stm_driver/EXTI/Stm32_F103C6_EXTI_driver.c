#include "../ARM2_CPU_MODES/stm_driver/inc/Stm32_F103C6_EXTI_driver.h"
#include "../ARM2_CPU_MODES/stm_driver/inc/Stm32_F103C6_gpio_driver.h"


/*  ****************
 *   Variables
 *  ****************  */



// Array of 15 elements of pointers to function 
void (* GP_IRQ_CallBack[15])(void);



/*  ****************
 *   Macros
 *  ****************  */


#define AFIO_GPIO_EXTI_Mapping(x)		(	(x==GPIOA)?0:\
											(x==GPIOB)?1:\
											(x==GPIOC)?2:\
											(x==GPIOD)?3:0    )



/*  ****************
 *   Functions
 *  ****************  */


void Enable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Enable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Enable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Enable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Enable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Enable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Enable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Enable;
		break;
	}
}


void Disable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Disable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Disable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Disable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Disable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Disable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Disable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Disable;
		break;
	}
}



void Update_EXTI(EXTI_PinConfig_t *EXTI_Config)
{
	// 1- Configure GPIO to be AF input --> Floating input from data sheet

	GPIO_PinConfig_t PinCfg;
	PinCfg.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_Pin;
	PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_Port, &PinCfg);

	// ----------------------------------------------------------

	// 2- Update AFIO to route between EXTI line with PORT A,B,C,D

	uint8_t AFIO_EXTICR_index = EXTI_Config->EXTI_PIN.EXTI_lineNumber / 4;

	uint8_t AFIO_EXTICR_ShiftPosition =  (EXTI_Config->EXTI_PIN.EXTI_lineNumber % 4) * 4; // 15 exti for every port 


	// Clear the four bit to write on
	AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0xF << AFIO_EXTICR_ShiftPosition);

	AFIO->EXTICR[AFIO_EXTICR_index] |= ((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_Port) & 0XF) << AFIO_EXTICR_ShiftPosition);

	// ----------------------------------------------------------


	// 3- Update Rising or falling edge

	// First clear them then writing
	EXTI->RTSR &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_lineNumber);
	EXTI->FTSR &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_lineNumber);

	// Update them
	if(EXTI_Config->TriggerCase == EXTI_Trigger_RISING)
	{
		EXTI->RTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_lineNumber);
	}else if(EXTI_Config->TriggerCase == EXTI_Trigger_FALLING)
	{
		EXTI->FTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_lineNumber);
	}else if(EXTI_Config->TriggerCase == EXTI_Trigger_RISINGANDFALLING)
	{
		EXTI->RTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_lineNumber);
		EXTI->FTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_lineNumber);
	}


	// ----------------------------------------------------------


	// 4- Update IRQ handling CallBack


	GP_IRQ_CallBack[EXTI_Config->EXTI_PIN.EXTI_lineNumber] = EXTI_Config->P_IRQ_CallBack;


	// ----------------------------------------------------------


	// 5- Enable or disable IRQ EXTI & NVIC


	if(EXTI_Config->IRQ_Enable == EXTI_IRQ_Enable)
	{
		EXTI->IMR |= (1<<EXTI_Config->EXTI_PIN.EXTI_lineNumber);
		Enable_NVIC(EXTI_Config->EXTI_PIN.EXTI_lineNumber);
	}else
	{
		EXTI->IMR &= ~(1<<EXTI_Config->EXTI_PIN.EXTI_lineNumber);
		Disable_NVIC(EXTI_Config->EXTI_PIN.EXTI_lineNumber);
	}


}


/**================================================================
 * @Fn					- MCAL_EXTI_GPIO_DeInit
 * @brief 				- Reset EXTI registers and NVIC corresponding to IRQ Mask
 * @param [in] 			- None
 * @retval 				- None
 * Note					- None
 *
 */

void MCAL_EXTI_GPIO_DeInit(void)
{
	// So, we will reset them manually
	EXTI->IMR = 0x00000000;
	EXTI->EMR = 0x00000000;
	EXTI->RTSR = 0x00000000;
	EXTI->FTSR = 0x00000000;
	EXTI->SWIER = 0x00000000;
	EXTI->FTSR = 0x00000000;
	EXTI->PR = 0xFFFFFFFF;			// Cleared by writing one

	// Disable EXTI_IRQ from NVIC
	NVIC_IRQ6_EXTI0_Disable;
	NVIC_IRQ7_EXTI1_Disable;
	NVIC_IRQ8_EXTI2_Disable;
	NVIC_IRQ9_EXTI3_Disable;
	NVIC_IRQ10_EXTI4_Disable;
	NVIC_IRQ23_EXTI5_9_Disable;
	NVIC_IRQ40_EXTI10_15_Disable;
}


/**================================================================
 * @Fn					- MCAL_EXTI_GPIO_Init
 * @brief 				- Initializes EXTI from specific GPIO Pin and specify the Mask/Trigger condition and IRQ_CallBack
 * @param [in] 			- EXTI_Config: set by @ref EXTI_define, @ref EXTI_Trigger_define, and @ref EXTI_IRQ_define
 * @retval 				- None
 * Note					- It is mandatory to enable RCC clock for AFIO and the corresponding GPIO
 *
 */



void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t *EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}


/**================================================================
 * @Fn					- MCAL_EXTI_GPIO_Update
 * @brief 				- Initializes EXTI from specific GPIO Pin and specify the Mask/Trigger condition and IRQ_CallBack
 * @param [in] 			- EXTI_Config: set by @ref EXTI_define, @ref EXTI_Trigger_define, and @ref EXTI_IRQ_define
 * @retval 				- None
 * Note					- It is mandatory to enable RCC clock for AFIO and the corresponding GPIO
 *
 */


void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t *EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}

///////////////////////////////ISR ///////////////////////////////////////////


void EXTI0_IRQHandler(void)
{

	// Clear pending register by writing '1' into the bit
	EXTI->PR |= 1<<0;

	// Call IRQ_CallBack
	GP_IRQ_CallBack[0]();

}


void EXTI1_IRQHandler(void)
{
	// Clear pending register by writing '1' into the bit
	EXTI->PR |= 1<<1;

	// Call IRQ_CallBack
	GP_IRQ_CallBack[1]();
}


void EXTI2_IRQHandler(void)
{
	// Clear pending register by writing '1' into the bit
	EXTI->PR |= 1<<2;

	// Call IRQ_CallBack
	GP_IRQ_CallBack[2]();
}



void EXTI3_IRQHandler(void)
{
	// Clear pending register by writing '1' into the bit
	EXTI->PR |= 1<<3;

	// Call IRQ_CallBack
	GP_IRQ_CallBack[3]();
}



void EXTI4_IRQHandler(void)
{
	// Clear pending register by writing '1' into the bit
	EXTI->PR |= 1<<4;

	// Call IRQ_CallBack
	GP_IRQ_CallBack[4]();
}



void EXTI9_5_IRQHandler(void)
{
	// First we need to know which one of them was pending
	if(EXTI->PR & 1<<5){ EXTI->PR |= 1<<5;  GP_IRQ_CallBack[5]();}
	if(EXTI->PR & 1<<6){ EXTI->PR |= 1<<6;  GP_IRQ_CallBack[6]();}
	if(EXTI->PR & 1<<7){ EXTI->PR |= 1<<7;  GP_IRQ_CallBack[7]();}
	if(EXTI->PR & 1<<8){ EXTI->PR |= 1<<8;  GP_IRQ_CallBack[8]();}
	if(EXTI->PR & 1<<9){ EXTI->PR |= 1<<9;  GP_IRQ_CallBack[9]();}
}



void EXTI15_10_IRQHandler(void)
{
	// First we need to know which one of them was pending
	if(EXTI->PR & 1<<10){ EXTI->PR |= 1<<10;  GP_IRQ_CallBack[10]();}
	if(EXTI->PR & 1<<11){ EXTI->PR |= 1<<11;  GP_IRQ_CallBack[11]();}
	if(EXTI->PR & 1<<12){ EXTI->PR |= 1<<12;  GP_IRQ_CallBack[12]();}
	if(EXTI->PR & 1<<13){ EXTI->PR |= 1<<13;  GP_IRQ_CallBack[13]();}
	if(EXTI->PR & 1<<14){ EXTI->PR |= 1<<14;  GP_IRQ_CallBack[14]();}
	if(EXTI->PR & 1<<15){ EXTI->PR |= 1<<15;  GP_IRQ_CallBack[15]();}
}



