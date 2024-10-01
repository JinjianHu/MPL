################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Lab3.c \
../source/semihost_hardfault.c 

C_DEPS += \
./source/Lab3.d \
./source/semihost_hardfault.d 

OBJS += \
./source/Lab3.o \
./source/semihost_hardfault.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"D:\Classworks\Microprocessor Lab\MPL\Lab3\board" -I"D:\Classworks\Microprocessor Lab\MPL\Lab3\source" -I"D:\Classworks\Microprocessor Lab\MPL\Lab3\utilities" -I"D:\Classworks\Microprocessor Lab\MPL\Lab3\drivers" -I"D:\Classworks\Microprocessor Lab\MPL\Lab3\component\uart" -I"D:\Classworks\Microprocessor Lab\MPL\Lab3\component\serial_manager" -I"D:\Classworks\Microprocessor Lab\MPL\Lab3\device" -I"D:\Classworks\Microprocessor Lab\MPL\Lab3\CMSIS" -I"D:\Classworks\Microprocessor Lab\MPL\Lab3\component\lists" -I"D:\Classworks\Microprocessor Lab\MPL\Lab3\startup" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/Lab3.d ./source/Lab3.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o

.PHONY: clean-source

