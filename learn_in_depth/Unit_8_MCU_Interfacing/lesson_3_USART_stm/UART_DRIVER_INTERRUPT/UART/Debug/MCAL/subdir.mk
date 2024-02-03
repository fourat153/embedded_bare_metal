################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/stm32f103c6tx_EXTI.c \
../MCAL/stm32f103c6tx_GPIO.c \
../MCAL/stm32f103c6tx_RCC.c \
../MCAL/stm32f103c6tx_UASRT.c 

OBJS += \
./MCAL/stm32f103c6tx_EXTI.o \
./MCAL/stm32f103c6tx_GPIO.o \
./MCAL/stm32f103c6tx_RCC.o \
./MCAL/stm32f103c6tx_UASRT.o 

C_DEPS += \
./MCAL/stm32f103c6tx_EXTI.d \
./MCAL/stm32f103c6tx_GPIO.d \
./MCAL/stm32f103c6tx_RCC.d \
./MCAL/stm32f103c6tx_UASRT.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/stm32f103c6tx_EXTI.o: C:/Users/ahmed/Desktop/github/embedded_diploma/embedded_diplom/learn_in_depth/Unit_8_MCU_Interfacing/lesson_3_USART_stm/UART_DRIVER_INTERRUPT/UART/MCAL/stm32f103c6tx_EXTI.c MCAL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F103C4Tx -DSTM32F1 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/stm32f103c6tx_GPIO.o: C:/Users/ahmed/Desktop/github/embedded_diploma/embedded_diplom/learn_in_depth/Unit_8_MCU_Interfacing/lesson_3_USART_stm/UART_DRIVER_INTERRUPT/UART/MCAL/stm32f103c6tx_GPIO.c MCAL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F103C4Tx -DSTM32F1 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/stm32f103c6tx_RCC.o: C:/Users/ahmed/Desktop/github/embedded_diploma/embedded_diplom/learn_in_depth/Unit_8_MCU_Interfacing/lesson_3_USART_stm/UART_DRIVER_INTERRUPT/UART/MCAL/stm32f103c6tx_RCC.c MCAL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F103C4Tx -DSTM32F1 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/stm32f103c6tx_UASRT.o: C:/Users/ahmed/Desktop/github/embedded_diploma/embedded_diplom/learn_in_depth/Unit_8_MCU_Interfacing/lesson_3_USART_stm/UART_DRIVER_INTERRUPT/UART/MCAL/stm32f103c6tx_UASRT.c MCAL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F103C4Tx -DSTM32F1 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL

clean-MCAL:
	-$(RM) ./MCAL/stm32f103c6tx_EXTI.cyclo ./MCAL/stm32f103c6tx_EXTI.d ./MCAL/stm32f103c6tx_EXTI.o ./MCAL/stm32f103c6tx_EXTI.su ./MCAL/stm32f103c6tx_GPIO.cyclo ./MCAL/stm32f103c6tx_GPIO.d ./MCAL/stm32f103c6tx_GPIO.o ./MCAL/stm32f103c6tx_GPIO.su ./MCAL/stm32f103c6tx_RCC.cyclo ./MCAL/stm32f103c6tx_RCC.d ./MCAL/stm32f103c6tx_RCC.o ./MCAL/stm32f103c6tx_RCC.su ./MCAL/stm32f103c6tx_UASRT.cyclo ./MCAL/stm32f103c6tx_UASRT.d ./MCAL/stm32f103c6tx_UASRT.o ./MCAL/stm32f103c6tx_UASRT.su

.PHONY: clean-MCAL

