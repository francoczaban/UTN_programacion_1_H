################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Employee.c \
../src/Menu.c \
../src/TP2.c \
../src/utn.c 

OBJS += \
./src/Employee.o \
./src/Menu.o \
./src/TP2.o \
./src/utn.o 

C_DEPS += \
./src/Employee.d \
./src/Menu.d \
./src/TP2.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

