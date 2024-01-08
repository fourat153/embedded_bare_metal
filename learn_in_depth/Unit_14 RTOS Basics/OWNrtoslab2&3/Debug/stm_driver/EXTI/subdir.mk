################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm_driver/EXTI/Stm32_F103C6_EXTI_driver.c 

OBJS += \
./stm_driver/EXTI/Stm32_F103C6_EXTI_driver.o 

C_DEPS += \
./stm_driver/EXTI/Stm32_F103C6_EXTI_driver.d 


# Each subdirectory must supply rules for building sources it contributes
stm_driver/EXTI/%.o stm_driver/EXTI/%.su stm_driver/EXTI/%.cyclo: ../stm_driver/EXTI/%.c stm_driver/EXTI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -c -I"C:/Users/mm77/Desktop/lean/embedded_diplom/learn_in_depth/Unit_14 RTOS Basics/OWNrtoslab2&3" -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-stm_driver-2f-EXTI

clean-stm_driver-2f-EXTI:
	-$(RM) ./stm_driver/EXTI/Stm32_F103C6_EXTI_driver.cyclo ./stm_driver/EXTI/Stm32_F103C6_EXTI_driver.d ./stm_driver/EXTI/Stm32_F103C6_EXTI_driver.o ./stm_driver/EXTI/Stm32_F103C6_EXTI_driver.su

.PHONY: clean-stm_driver-2f-EXTI

