# Makefile for terminal driver (TTY)
DRIVER = tty

include ../../etc/make.conf

# directories
u = /usr
i = $u/include
s = $i/sys
m = $i/minix
b = $i/ibm
d = ..

# programs, flags, etc.
#MAKE = exec make
#CC =	exec cc
#CPPFLAGS = -I$i 
#CFLAGS = $(CPPFLAGS)

CPPFLAGS=
CFLAGS=-g -O0 -mcpu=arm920t -mtune=arm920t -mstructure-size-boundary=32 -fpack-struct -fno-builtin
CC=arm-elf-gcc
#MAKE=arm-elf-make
MAKE=make

LDFLAGS = -i
LIBS =  -Wl,--start-group ../../lib/obj-gnu/*.a  /usr/local/arm-elf/lib/gcc/arm-elf/4.4.1/*.a -Wl,--end-group -nostartfiles -nodefaultlibs 

#OBJ = tty.o console.o vidcopy.o keyboard.o pty.o rs232.o 
OBJ = tty.o console.o keyboard.o pty.o rs232.o 

# build local binary 
all build:	$(DRIVER)
$(DRIVER):	$(OBJ) 
	$(CC) -o $@ $(LDFLAGS) $(OBJ) $(LIBS)
	install -S 16k $(DRIVER)

# install with other drivers
install:	
	cd keymaps && $(MAKE) -$(MAKEFLAGS) install

#/sbin/$(DRIVER):	$(DRIVER)
#	install -o root -cs $? $@

# clean up local files
clean:
	cd keymaps && $(MAKE) -$(MAKEFLAGS) $@
	rm -f $(DRIVER) *.o *.bak 

depend: 
	mkdep "$(CC) -E $(CPPFLAGS)" *.c > .depend

# Include generated dependencies.
#include .depend


