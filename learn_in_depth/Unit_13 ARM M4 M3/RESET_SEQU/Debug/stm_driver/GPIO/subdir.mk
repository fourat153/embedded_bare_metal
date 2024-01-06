################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm_driver/GPIO/Stm32_F103C6_gpio_driver.c 

OBJS += \
./stm_driver/GPIO/Stm32_F103C6_gpio_driver.o 

C_DEPS += \
./stm_driver/GPIO/Stm32_F103C6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
stm_driver/GPIO/%.o stm_driver/GPIO/%.su stm_driver/GPIO/%.cyclo: ../stm_driver/GPIO/%.c stm_driver/GPIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -c -I"C:/Users/mm77/Desktop/lean/embedded_diplom/learn_in_depth/Unit_13 ARM M4 M3/INLINE_ASSEMBLY" -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-stm_driver-2f-GPIO

clean-stm_driver-2f-GPIO:
	-$(RM) ./stm_driver/GPIO/Stm32_F103C6_gpio_driver.cyclo ./stm_driver/GPIO/Stm32_F103C6_gpio_driver.d ./stm_driver/GPIO/Stm32_F103C6_gpio_driver.o ./stm_driver/GPIO/Stm32_F103C6_gpio_driver.su

.PHONY: clean-stm_driver-2f-GPIO

