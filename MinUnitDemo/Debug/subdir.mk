################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Julian\ Brown/Documents/GitHub/testing_testing/Common/LedDriver.c \
../testmain.c 

OBJS += \
./LedDriver.o \
./testmain.o 

C_DEPS += \
./LedDriver.d \
./testmain.d 


# Each subdirectory must supply rules for building sources it contributes
LedDriver.o: C:/Users/Julian\ Brown/Documents/GitHub/testing_testing/Common/LedDriver.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -I"/Common" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"LedDriver.d" -MT"LedDriver.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -I"/Common" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


