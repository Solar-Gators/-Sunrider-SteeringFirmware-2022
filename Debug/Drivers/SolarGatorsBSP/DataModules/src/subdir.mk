################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Drivers/SolarGatorsBSP/DataModules/src/FrontLights.cpp \
../Drivers/SolarGatorsBSP/DataModules/src/Mitsuba.cpp \
../Drivers/SolarGatorsBSP/DataModules/src/OrionBMS.cpp \
../Drivers/SolarGatorsBSP/DataModules/src/Proton1.cpp \
../Drivers/SolarGatorsBSP/DataModules/src/Steering.cpp \
../Drivers/SolarGatorsBSP/DataModules/src/SteeringController.cpp 

OBJS += \
./Drivers/SolarGatorsBSP/DataModules/src/FrontLights.o \
./Drivers/SolarGatorsBSP/DataModules/src/Mitsuba.o \
./Drivers/SolarGatorsBSP/DataModules/src/OrionBMS.o \
./Drivers/SolarGatorsBSP/DataModules/src/Proton1.o \
./Drivers/SolarGatorsBSP/DataModules/src/Steering.o \
./Drivers/SolarGatorsBSP/DataModules/src/SteeringController.o 

CPP_DEPS += \
./Drivers/SolarGatorsBSP/DataModules/src/FrontLights.d \
./Drivers/SolarGatorsBSP/DataModules/src/Mitsuba.d \
./Drivers/SolarGatorsBSP/DataModules/src/OrionBMS.d \
./Drivers/SolarGatorsBSP/DataModules/src/Proton1.d \
./Drivers/SolarGatorsBSP/DataModules/src/Steering.d \
./Drivers/SolarGatorsBSP/DataModules/src/SteeringController.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/SolarGatorsBSP/DataModules/src/%.o: ../Drivers/SolarGatorsBSP/DataModules/src/%.cpp Drivers/SolarGatorsBSP/DataModules/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m0 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F072xB -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -I"C:/Users/georg/STM32CubeIDE/SolarGators/OpenTelem_Aux/Drivers/SolarGatorsBSP/Drivers/inc" -I"C:/Users/georg/STM32CubeIDE/SolarGators/OpenTelem_Aux/Drivers/SolarGatorsBSP/DataModules/inc" -I"C:/Users/georg/STM32CubeIDE/SolarGators/OpenTelem_Aux/Drivers/SolarGatorsBSP/etl/include" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-SolarGatorsBSP-2f-DataModules-2f-src

clean-Drivers-2f-SolarGatorsBSP-2f-DataModules-2f-src:
	-$(RM) ./Drivers/SolarGatorsBSP/DataModules/src/FrontLights.d ./Drivers/SolarGatorsBSP/DataModules/src/FrontLights.o ./Drivers/SolarGatorsBSP/DataModules/src/Mitsuba.d ./Drivers/SolarGatorsBSP/DataModules/src/Mitsuba.o ./Drivers/SolarGatorsBSP/DataModules/src/OrionBMS.d ./Drivers/SolarGatorsBSP/DataModules/src/OrionBMS.o ./Drivers/SolarGatorsBSP/DataModules/src/Proton1.d ./Drivers/SolarGatorsBSP/DataModules/src/Proton1.o ./Drivers/SolarGatorsBSP/DataModules/src/Steering.d ./Drivers/SolarGatorsBSP/DataModules/src/Steering.o ./Drivers/SolarGatorsBSP/DataModules/src/SteeringController.d ./Drivers/SolarGatorsBSP/DataModules/src/SteeringController.o

.PHONY: clean-Drivers-2f-SolarGatorsBSP-2f-DataModules-2f-src

