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
#include sources.mk

ifeq ($(PLATFORM),HOST)
	CC = gcc
	ARCH:=$(arch)
	OS := $(uname)
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	TARGET = c1m2
	LDFLAS =  
	SRCS = main.c \
	       memory.c 
	INCLUDES = -I ../include/common
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
		 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wall -Werror -g -O0 -std=c99
	SRCS = main.c \
	       interrupts_msp432p401r_gcc.c \
	       memory.c \
	       startup_msp432p401r_gcc.c \
	       system_msp432p401r.c
	
	INCLUDES = -I ../include/CMSIS -I ../include/common -I ../include/msp432
endif


OBJS = $(SRCS:.c=.o)
%.o : %.c
	$(CC) -D$(PLATFORM) $(INCLUDES) -c $< $(CFLAGS) -o $@

PREES = $(SRCS:.c=.i)
%.i : %.c
	$(CC) -D$(PLATFORM) $(INCLUDES) -E $< $(CFLAGS) -o $@

ASMBS = $(SRCS:.c=.asm)
%.asm : %.c
	$(CC) -D$(PLATFORM) $(INCLUDES) -S $< $(CFLAGS) -o $@

DEPS = $(SRCS:.c=.d)
%.d : %.c
	$(CC) -D$(PLATFORM) $(INCLUDES) -M $< $(CFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build:  $(TARGET).out $(ASMBS) $(PREES) $(DEPS)

$(TARGET).out: $(OBJS)
	$(CC) -D$(PLATFORM) $(INCLUDES) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map $(ASMBS) $(PREES) $(DEPS)
