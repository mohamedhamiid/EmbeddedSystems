################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/MCAL/DIO/DIO.c \
../SRC/MCAL/DIO/DIO_cfg.c 

OBJS += \
./SRC/MCAL/DIO/DIO.o \
./SRC/MCAL/DIO/DIO_cfg.o 

C_DEPS += \
./SRC/MCAL/DIO/DIO.d \
./SRC/MCAL/DIO/DIO_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/MCAL/DIO/%.o: ../SRC/MCAL/DIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


