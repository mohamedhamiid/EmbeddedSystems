################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/APP/draft.c \
../SRC/APP/main.c \
../SRC/APP/main2.c \
../SRC/APP/semicolon.c 

OBJS += \
./SRC/APP/draft.o \
./SRC/APP/main.o \
./SRC/APP/main2.o \
./SRC/APP/semicolon.o 

C_DEPS += \
./SRC/APP/draft.d \
./SRC/APP/main.d \
./SRC/APP/main2.d \
./SRC/APP/semicolon.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/APP/%.o: ../SRC/APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


