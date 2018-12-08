################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../DIO.c \
../Interrupt.c \
../Keybad.c \
../LCD.c \
../PWM_Timer0.c \
../PubFun.c \
../SPI.c \
../Safe_Config.c \
../SevnSegm.c \
../Timer.c \
../Timer1.c \
../UART.c \
../main.c 

OBJS += \
./ADC.o \
./DIO.o \
./Interrupt.o \
./Keybad.o \
./LCD.o \
./PWM_Timer0.o \
./PubFun.o \
./SPI.o \
./Safe_Config.o \
./SevnSegm.o \
./Timer.o \
./Timer1.o \
./UART.o \
./main.o 

C_DEPS += \
./ADC.d \
./DIO.d \
./Interrupt.d \
./Keybad.d \
./LCD.d \
./PWM_Timer0.d \
./PubFun.d \
./SPI.d \
./Safe_Config.d \
./SevnSegm.d \
./Timer.d \
./Timer1.d \
./UART.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


