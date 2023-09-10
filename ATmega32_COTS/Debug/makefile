################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/MGIE/subdir.mk
-include MCAL/MEXTI/subdir.mk
-include MCAL/MDIO/subdir.mk
-include MCAL/MADC/subdir.mk
-include LIB/subdir.mk
-include HAL/HSSD/subdir.mk
-include HAL/HPB/subdir.mk
-include HAL/HMSSD/subdir.mk
-include HAL/HLM35/subdir.mk
-include HAL/HLED/subdir.mk
-include HAL/HLCD/subdir.mk
-include HAL/HKEYPAD/subdir.mk
-include HAL/HDCMOTOR/subdir.mk
-include HAL/HBUZZER/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := ATmega32_COTS
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ATmega32_COTS.lss \

FLASH_IMAGE += \
ATmega32_COTS.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: ATmega32_COTS.elf secondary-outputs

# Tool invocations
ATmega32_COTS.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ATmega32_COTS.map -mmcu=atmega32 -o "ATmega32_COTS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ATmega32_COTS.lss: ATmega32_COTS.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ATmega32_COTS.elf  >"ATmega32_COTS.lss"
	@echo 'Finished building: $@'
	@echo ' '

ATmega32_COTS.hex: ATmega32_COTS.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ATmega32_COTS.elf  "ATmega32_COTS.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ATmega32_COTS.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ATmega32_COTS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ATmega32_COTS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
