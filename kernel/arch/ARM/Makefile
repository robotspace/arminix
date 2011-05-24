# Makefile for kernel

include ../../../etc/make.conf

ARCHAR=$(ARCH).a

# objects, excluding first-stage code, which is $(HEAD).
# the HEAD variable is passed as an argument to this Makefile
# by an upper level Makefile.

OBJS=	arch_do_vmctl.o \
	clock.o \
	CP15.o \
	kcrt0.o \
	do_readbios.o \
	do_iopenable.o \
	exception.o \
	exceptions.o \
	klibARM.o \
	memory.o \
	PL190.o \
	protect.o \
	system.o

CPPFLAGS=
CFLAGS=-g -O0 -mcpu=arm920t -mtune=arm920t -mstructure-size-boundary=32 -fpack-struct -fno-builtin -I ./include
CC=arm-elf-gcc
LDFLAGS = -nostartfiles -nodefaultlibs 

build: $(HEAD) $(ARCHAR)

$(ARCHAR): $(OBJS)
	ar cr $@ *.o

depend: 
	mkdep "$(CC) -E $(CPPFLAGS)" *.c *.s > .depend

clean:
	rm -f *.a *.o *~

# How to build it
$(ARCHAR)(exceptions.o): exceptions.c
	$(CC) $(CFLAGS) -c $<

$(ARCHAR)(arch_do_vmctl.o): arch_do_vmctl.c
	$(CC) $(CFLAGS) -c $<

$(ARCHAR)(exception.o): exception.c
	$(CC) $(CFLAGS) -c $<
	
$(ARCHAR)(CP15.o): CP15.s
	$(CC) $(CFLAGS) -c $<

$(ARCHAR)(memory.o): memory.c
	$(CC) $(CFLAGS) -c $<

$(ARCHAR)(protect.o): protect.c
	$(CC) $(CFLAGS) -c $<

$(ARCHAR)(system.o): system.c
	$(CC) $(CFLAGS) -c $<

$(ARCHAR)(kcrt0.o): kcrt0.s
	arm-elf-as $(CFLAGS) -c $<

$(ARCHAR)(do_iopenable.o): do_iopenable.c
	$(CC) $(CFLAGS) -c $<

$(ARCHAR)(do_readbios.o): do_readbios.c
	$(CC) $(CFLAGS) -c $<

$(ARCHAR)(PL190.o): PL190.c
	$(CC) $(CFLAGS) -c $<

$(ARCHAR)(clock.o): clock.c
	$(CC) $(CFLAGS) -c $<

$(ARCHAR)(klibARM.o): klibARM.s
	$(CC) $(CFLAGS) -c $<

.s.o:
	$(CC) $(CFLAGS) -c -o $@ $<

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(HEAD): crt0.o
	cp $< $@

# Include generated dependencies.
#include .depend
