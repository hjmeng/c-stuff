################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/factorial.c 

OBJS += \
./src/factorial.o 

C_DEPS += \
./src/factorial.d 


# Each subdirectory must supply rules for building sources it contributes
src/factorial.o: ../src/factorial.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/factorial.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


