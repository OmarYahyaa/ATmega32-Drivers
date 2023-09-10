################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/HKEYPAD/HKEYPAD_program.c 

OBJS += \
./HAL/HKEYPAD/HKEYPAD_program.o 

C_DEPS += \
./HAL/HKEYPAD/HKEYPAD_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/HKEYPAD/%.o: ../HAL/HKEYPAD/%.c HAL/HKEYPAD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\IMT\03- Microcontroller Interfacing AVR\GitHub\ATmega32-Drivers\ATmega32_COTS\HAL\HBUZZER" -I"C:\IMT\03- Microcontroller Interfacing AVR\GitHub\ATmega32-Drivers\ATmega32_COTS\MCAL\MADC" -I"C:\IMT\03- Microcontroller Interfacing AVR\GitHub\ATmega32-Drivers\ATmega32_COTS\MCAL\MEXTI" -I"C:\IMT\03- Microcontroller Interfacing AVR\GitHub\ATmega32-Drivers\ATmega32_COTS\MCAL\MGIE" -I"C:\IMT\03- Microcontroller Interfacing AVR\GitHub\ATmega32-Drivers\ATmega32_COTS\HAL\HDCMOTOR" -I"C:\IMT\03- Microcontroller Interfacing AVR\GitHub\ATmega32-Drivers\ATmega32_COTS\HAL\HKEYPAD" -I"C:\IMT\03- Microcontroller Interfacing AVR\GitHub\ATmega32-Drivers\ATmega32_COTS\HAL\HLCD" -I"C:\IMT\03- Microcontroller Interfacing AVR\GitHub\ATmega32-Drivers\ATmega32_COTS\HAL\HLED" -I"C:\IMT\03- Microcontroller Interfacing AVR\GitHub\ATmega32-Drivers\ATmega32_COTS\HAL\HLM35" -I"C:\IMT\03- Microcontroller Interfacing AVR\GitHub\ATmega32-Drivers\ATmega32_COTS\HAL\HMSSD" -I"C:\IMT\03- Microcontroller Interfacing AVR\GitHub\ATmega32-Drivers\ATmega32_COTS\HAL\HPB" -I"C:\IMT\03- Microcontroller Interfacing AVR\GitHub\ATmega32-Drivers\ATmega32_COTS\HAL\HSSD" -I"C:\IMT\03- Microcontroller Interfacing AVR\GitHub\ATmega32-Drivers\ATmega32_COTS\LIB" -I"C:\IMT\03- Microcontroller Interfacing AVR\GitHub\ATmega32-Drivers\ATmega32_COTS\MCAL\MDIO" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


