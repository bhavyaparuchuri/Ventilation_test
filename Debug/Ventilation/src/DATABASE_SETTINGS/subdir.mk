################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ventilation/src/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.c 

OBJS += \
./Ventilation/src/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.o 

C_DEPS += \
./Ventilation/src/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.d 


# Each subdirectory must supply rules for building sources it contributes
Ventilation/src/DATABASE_SETTINGS/%.o: ../Ventilation/src/DATABASE_SETTINGS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/TIMERS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/GENERAL" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/MAIN" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SCHEDULER" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


