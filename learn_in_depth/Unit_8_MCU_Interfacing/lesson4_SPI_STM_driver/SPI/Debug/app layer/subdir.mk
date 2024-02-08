################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app\ layer/test_spi_polling.c 

OBJS += \
./app\ layer/test_spi_polling.o 

C_DEPS += \
./app\ layer/test_spi_polling.d 


# Each subdirectory must supply rules for building sources it contributes
app\ layer/test_spi_polling.o: C:/Users/ahmed/Desktop/github/embedded_diploma/embedded_diplom/learn_in_depth/Unit_8_MCU_Interfacing/lesson4_SPI_STM_driver/SPI/app\ layer/test_spi_polling.c app\ layer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F103C4Tx -DSTM32F1 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"app layer/test_spi_polling.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-app-20-layer

clean-app-20-layer:
	-$(RM) ./app\ layer/test_spi_polling.cyclo ./app\ layer/test_spi_polling.d ./app\ layer/test_spi_polling.o ./app\ layer/test_spi_polling.su

.PHONY: clean-app-20-layer

