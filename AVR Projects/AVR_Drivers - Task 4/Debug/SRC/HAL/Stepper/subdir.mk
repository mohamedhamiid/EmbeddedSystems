################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/HAL/Stepper/Stepper.c 

OBJS += \
./SRC/HAL/Stepper/Stepper.o 

C_DEPS += \
./SRC/HAL/Stepper/Stepper.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/HAL/Stepper/%.o: ../SRC/HAL/Stepper/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


