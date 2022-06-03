################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Drivers/SolarGatorsBSP/etl/examples/ArmTimerCallbacks\ -\ C++/RTE/Device/STM32F401RETx/startup_stm32f401xe.s 

C_SRCS += \
../Drivers/SolarGatorsBSP/etl/examples/ArmTimerCallbacks\ -\ C++/RTE/Device/STM32F401RETx/system_stm32f4xx.c 

S_DEPS += \
./Drivers/SolarGatorsBSP/etl/examples/ArmTimerCallbacks\ -\ C++/RTE/Device/STM32F401RETx/startup_stm32f401xe.d 

C_DEPS += \
./Drivers/SolarGatorsBSP/etl/examples/ArmTimerCallbacks\ -\ C++/RTE/Device/STM32F401RETx/system_stm32f4xx.d 

OBJS += \
./Drivers/SolarGatorsBSP/etl/examples/ArmTimerCallbacks\ -\ C++/RTE/Device/STM32F401RETx/startup_stm32f401xe.o \
./Drivers/SolarGatorsBSP/etl/examples/ArmTimerCallbacks\ -\ C++/RTE/Device/STM32F401RETx/system_stm32f4xx.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/SolarGatorsBSP/etl/examples/ArmTimerCallbacks\ -\ C++/RTE/Device/STM32F401RETx/startup_stm32f401xe.o: ../Drivers/SolarGatorsBSP/etl/examples/ArmTimerCallbacks\ -\ C++/RTE/Device/STM32F401RETx/startup_stm32f401xe.s Drivers/SolarGatorsBSP/etl/examples/ArmTimerCallbacks\ -\ C++/RTE/Device/STM32F401RETx/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m0 -g3 -DDEBUG -c -I"C:/Users/georg/STM32CubeIDE/SolarGators/OpenTelem_Aux/Drivers/SolarGatorsBSP/Drivers/inc" -I"C:/Users/georg/STM32CubeIDE/SolarGators/OpenTelem_Aux/Drivers/SolarGatorsBSP/DataModules/inc" -x assembler-with-cpp -MMD -MP -MF"Drivers/SolarGatorsBSP/etl/examples/ArmTimerCallbacks - C++/RTE/Device/STM32F401RETx/startup_stm32f401xe.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"
Drivers/SolarGatorsBSP/etl/examples/ArmTimerCallbacks\ -\ C++/RTE/Device/STM32F401RETx/system_stm32f4xx.o: ../Drivers/SolarGatorsBSP/etl/examples/ArmTimerCallbacks\ -\ C++/RTE/Device/STM32F401RETx/system_stm32f4xx.c Drivers/SolarGatorsBSP/etl/examples/ArmTimerCallbacks\ -\ C++/RTE/Device/STM32F401RETx/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F072xB -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -I"C:/Users/georg/STM32CubeIDE/SolarGators/OpenTelem_Aux/Drivers/SolarGatorsBSP/DataModules/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/SolarGatorsBSP/etl/examples/ArmTimerCallbacks - C++/RTE/Device/STM32F401RETx/system_stm32f4xx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-SolarGatorsBSP-2f-etl-2f-examples-2f-ArmTimerCallbacks-20--2d--20-C-2b--2b--2f-RTE-2f-Device-2f-STM32F401RETx

clean-Drivers-2f-SolarGatorsBSP-2f-etl-2f-examples-2f-ArmTimerCallbacks-20--2d--20-C-2b--2b--2f-RTE-2f-Device-2f-STM32F401RETx:
	-$(RM) ./Drivers/SolarGatorsBSP/etl/examples/ArmTimerCallbacks\ -\ C++/RTE/Device/STM32F401RETx/startup_stm32f401xe.d ./Drivers/SolarGatorsBSP/etl/examples/ArmTimerCallbacks\ -\ C++/RTE/Device/STM32F401RETx/startup_stm32f401xe.o ./Drivers/SolarGatorsBSP/etl/examples/ArmTimerCallbacks\ -\ C++/RTE/Device/STM32F401RETx/system_stm32f4xx.d ./Drivers/SolarGatorsBSP/etl/examples/ArmTimerCallbacks\ -\ C++/RTE/Device/STM32F401RETx/system_stm32f4xx.o

.PHONY: clean-Drivers-2f-SolarGatorsBSP-2f-etl-2f-examples-2f-ArmTimerCallbacks-20--2d--20-C-2b--2b--2f-RTE-2f-Device-2f-STM32F401RETx

