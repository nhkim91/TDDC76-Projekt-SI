################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/alien.cpp \
../src/attack_up.cpp \
../src/bullet.cpp \
../src/flying_objects_test.cpp \
../src/help.cpp \
../src/highscore.cpp \
../src/level_1.cpp \
../src/level_2.cpp \
../src/life.cpp \
../src/main.cpp \
../src/meteorite.cpp \
../src/player.cpp \
../src/power_up.cpp \
../src/shield.cpp \
../src/slow_motion.cpp \
../src/space_invader.cpp 

OBJS += \
./src/alien.o \
./src/attack_up.o \
./src/bullet.o \
./src/flying_objects_test.o \
./src/help.o \
./src/highscore.o \
./src/level_1.o \
./src/level_2.o \
./src/life.o \
./src/main.o \
./src/meteorite.o \
./src/player.o \
./src/power_up.o \
./src/shield.o \
./src/slow_motion.o \
./src/space_invader.o 

CPP_DEPS += \
./src/alien.d \
./src/attack_up.d \
./src/bullet.d \
./src/flying_objects_test.d \
./src/help.d \
./src/highscore.d \
./src/level_1.d \
./src/level_2.d \
./src/life.d \
./src/main.d \
./src/meteorite.d \
./src/player.d \
./src/power_up.d \
./src/shield.d \
./src/slow_motion.d \
./src/space_invader.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


