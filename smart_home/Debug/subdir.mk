################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HLCD_Program.c \
../MADC_Programe.c \
../MDIO_Program.c \
../MTimer_Program.c \
../MURT_Program.c \
../Smart_Home.c 

OBJS += \
./HLCD_Program.o \
./MADC_Programe.o \
./MDIO_Program.o \
./MTimer_Program.o \
./MURT_Program.o \
./Smart_Home.o 

C_DEPS += \
./HLCD_Program.d \
./MADC_Programe.d \
./MDIO_Program.d \
./MTimer_Program.d \
./MURT_Program.d \
./Smart_Home.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


