################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTOS/CortexMxOS_Porting.c \
../RTOS/My_RTOS_FIFO.c \
../RTOS/Schedular.c 

OBJS += \
./RTOS/CortexMxOS_Porting.o \
./RTOS/My_RTOS_FIFO.o \
./RTOS/Schedular.o 

C_DEPS += \
./RTOS/CortexMxOS_Porting.d \
./RTOS/My_RTOS_FIFO.d \
./RTOS/Schedular.d 


# Each subdirectory must supply rules for building sources it contributes
RTOS/%.o RTOS/%.su RTOS/%.cyclo: ../RTOS/%.c RTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -c -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-RTOS

clean-RTOS:
	-$(RM) ./RTOS/CortexMxOS_Porting.cyclo ./RTOS/CortexMxOS_Porting.d ./RTOS/CortexMxOS_Porting.o ./RTOS/CortexMxOS_Porting.su ./RTOS/My_RTOS_FIFO.cyclo ./RTOS/My_RTOS_FIFO.d ./RTOS/My_RTOS_FIFO.o ./RTOS/My_RTOS_FIFO.su ./RTOS/Schedular.cyclo ./RTOS/Schedular.d ./RTOS/Schedular.o ./RTOS/Schedular.su

.PHONY: clean-RTOS

