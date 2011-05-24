# Makefile for kernel

include ../etc/make.conf

# Directories
u = ..
i = $u/include
l = $u/lib/obj-gnu
s = system
a = ./arch/$(ARCH)

# Programs, flags, etc.
CC =	arm-elf-gcc
LD =	$(CC)
MAP = kernel.map
HEX  = kernel.hex
ELF = kernel.elf
LNK   = linkerscript

INCLUDES= -I $a/include
#CFLAGS=-g -O0 -mcpu=arm920t -mtune=arm920t -fno-builtin -mstructure-size-boundary=32 -fpack-struct $(INCLUDES)
CFLAGS=-g -O0 -mcpu=arm920t -mtune=arm920t -fno-builtin $(INCLUDES)  
LDFLAGS = -Wl,-Map,$(MAP),-T,$(LNK) -nostartfiles -nodefaultlibs 
LIBS =  -Wl,--start-group ../lib/obj-gcc/*.a  /usr/local/arm-elf/lib/gcc/arm-elf/4.4.1/*.a $(ARCHLIB) -Wl,--end-group 
# first-stage, arch-dependent startup code
HEAD =	$a/kcrt0.o
OBJS =	start.o table.o main.o proc.o system.o clock.o utility.o debug.o profile.o interrupt.o
SYSTEM = system.a
ARCHLIB = $a/$(ARCH).a

# What to make.
all: build 
kernel build install: $(OBJS) 
	cd system && $(MAKE) $@
	cd $a && $(MAKE) $@
	$(LD) $(CFLAGS)  $(LDFLAGS) $(HEAD) $(OBJS) $(SYSTEM) $(LIBS) -o $(ELF)

clean:
	cd system && $(MAKE) -$(MAKEFLAGS) $@
	cd $a && $(MAKE) -$(MAKEFLAGS) $@
	rm -f *.a *.o *~ *.bak kernel *.hex *.map

depend: 
	cd system && $(MAKE) -$(MAKEFLAGS) $@
	cd $a && $(MAKE) $@
	mkdep "$(CC) -E $(CPPFLAGS)" *.c > .depend

# How to build it
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<
