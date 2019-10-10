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
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

FLAGS = -Wall -Werror -g -O0 -std=c99

ifeq ($(PLATFORM),HOST)
	CC = gcc
	ARCH:=$(arch)
	OS := $(uname)
	TARGET = c1m2
	
else
	LINKER_FILE = msp432p401r.lds
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs
	TARGET = c1m2
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m \
		 -mfloat-abi=hard -mfpu=fpv4-sp-d16
endif


OBJS = $(SOURCES:.c=.o)
%.o : %.c
	$(CC) -D$(PLATFORM) $(INCLUDES) -c $< $(CFLAGS) $(FLAGS) -o $@

PREES = $(SOURCES:.c=.i)
%.i : %.c
	$(CC) -D$(PLATFORM) $(INCLUDES) -E $< $(CFLAGS) $(FLAGS) -o $@

ASMBS = $(SOURCES:.c=.asm)
%.asm : %.c
	$(CC) -D$(PLATFORM) $(INCLUDES) -S $< $(CFLAGS) $(FLAGS) -o $@

DEPS = $(SOURCES:.c=.d)
%.d : %.c
	$(CC) -D$(PLATFORM) $(INCLUDES) -M $< $(CFLAGS) $(FLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build:  $(TARGET).out $(ASMBS) $(PREES) $(DEPS)

$(TARGET).out: $(OBJS)
	$(CC) -D$(PLATFORM) $(INCLUDES) $(OBJS) $(CFLAGS) $(LDFLAGS) $(FLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map $(ASMBS) $(PREES) $(DEPS) 
