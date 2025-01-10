#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile for both host and MSP432 platforms
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      <FILE>.i - Builds <FILE>.i object file
#      <FILE>.asm - Builds <FILE>.asm object file
#      build - Builds and links all source files
#      compile-all - Builds all source files
#      clean - removes all generated files
#
# Platform Overrides:
#      PLATFORM - Platform (MSP32, HOST)
#      
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = MSP432 

# Architectures Specific Flags
ifeq ($(PLATFORM), MSP432)
	LINKER_FILE = ../msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
        CC = arm-none-eabi-gcc
	OBJDUMP = arm-none-eabi-objdump
	SIZE = arm-none-eabi-size
else
	CC = gcc
	OBJDUMP = objdump
	SIZE = size
endif


# Compiler Flags and Defines


ifeq ($(PLATFORM), MSP432)
	CFLAGS = -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS) -g -O0
	LDFLAGS = -Wl,-Map=c1m2.map -T $(LINKER_FILE)
else
	CFLAGS = -g -O0
	LDFLAGS = -Wl,-Map=c1m2.map
endif

CPPFLAGS = -D$(PLATFORM) -Wall -Werror -std=c99

OBJS = $(SOURCES:.c=.o)

%.i : %.c
	$(CC) $< $(CPPFLAGS) $(INCLUDES) -E > $@

%.asm : %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -S $@

%.o : %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -o $@

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) -c $^ $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -o $@ 

.PHONY: build
build: ./c1m2.out

./c1m2.out : $(OBJS)
	$(CC) $^ $(CPPFLAGS) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o c1m2.out 
	$(SIZE) -Atd $@

.PHONY: clean
clean:
	rm -f *.o *.s *.out *.map *.asm *.i


