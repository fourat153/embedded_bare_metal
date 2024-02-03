################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app\ layer/test_uart_polling.c 

OBJS += \
./app\ layer/test_uart_polling.o 

C_DEPS += \
./app\ layer/test_uart_polling.d 


# Each subdirectory must supply rules for building sources it contributes
app\ layer/test_uart_polling.o: ../app\ layer/test_uart_polling.c app\ layer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F103C4Tx -DSTM32F1 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"app layer/test_uart_polling.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-app-20-layer

clean-app-20-layer:
	-$(RM) ./app\ layer/test_uart_polling.cyclo ./app\ layer/test_uart_polling.d ./app\ layer/test_uart_polling.o ./app\ layer/test_uart_polling.su

.PHONY: clean-app-20-layer

