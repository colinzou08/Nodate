# Makefile for STM32 Ada tests.

CPP 		:= g++
GNATMAKE 	:= gnatmake
GNATBIND	:= gnatbind
GNATLINK	:= gnatlink
MAKEDIR 	:= mkdir -p
RM 			:= rm -f

BIN_OUTPUT 	:= rcc_test
ADAFLAGS 	:= -aI../core/spec -aI../core/body -aI../core/spec/stm32f0 -aI../core/body/stm32f0 -D obj/ -g

CPP_ROOT := ../../cpp
INCLUDES := -I. -I $(CPP_ROOT)/tests
CPPFLAGS := -std=c++11 -g3 -DSTM32F0=1


all: mkdir rcc_test interrupts_test gpio_test eventful

mkdir:
	mkdir -p bin
	mkdir -p obj

rcc_test:
	$(GNATMAKE) $(ADAFLAGS) -c rcc_test
	$(CPP) -c -o obj/stm32.o $(CPP_ROOT)/recorders/stm32.cpp $(CPPFLAGS) $(INCLUDES)
	$(CPP) -c -o obj/common.o $(CPP_ROOT)/tests/common.cpp $(CPPFLAGS) $(INCLUDES)
	$(GNATBIND) obj/rcc_test
	$(GNATLINK) -g -o bin/rcc_test --LINK=g++ obj/rcc_test obj/common.o obj/stm32.o
	
interrupts_test:
	$(GNATMAKE) $(ADAFLAGS) -c interrupts_test
	$(CPP) -c -o obj/stm32.o $(CPP_ROOT)/recorders/stm32.cpp $(CPPFLAGS) $(INCLUDES)
	$(CPP) -c -o obj/common.o $(CPP_ROOT)/tests/common.cpp $(CPPFLAGS) $(INCLUDES)
	$(GNATBIND) obj/interrupts_test
	$(GNATLINK) -g -o bin/interrupts_test --LINK=g++ obj/interrupts_test obj/common.o obj/stm32.o
	
gpio_test:
	$(GNATMAKE) $(ADAFLAGS) -c gpio_test
	$(CPP) -c -o obj/stm32.o $(CPP_ROOT)/recorders/stm32.cpp $(CPPFLAGS) $(INCLUDES)
	$(CPP) -c -o obj/common.o $(CPP_ROOT)/tests/common.cpp $(CPPFLAGS) $(INCLUDES)
	$(GNATBIND) obj/gpio_test
	$(GNATLINK) -g -o bin/gpio_test --LINK=g++ obj/gpio_test obj/common.o obj/stm32.o
	
eventful:
	#g++ -o bin/eventful eventful.cpp common.cpp $(SOURCE_ROOT)/rcc.cpp \
												# $(SOURCE_ROOT)/gpio.cpp \
												# $(SOURCE_ROOT)/interrupts.cpp \
												# $(FLAGS) $(INCLUDES)
