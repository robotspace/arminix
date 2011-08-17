# Makefile for terminal driver (TTY)
DRIVER = tty

include ../../etc/make.conf

# directories
u = ../../
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
COMPAT= -Dmain=$(DRIVER)_main \
		-Dkputc=$(DRIVER)_kputc \
		-Ddo_new_kmess=$(DRIVER)_do_new_kmess \
		-Ddo_diagnostics=$(DRIVER)_do_diagnostics



CFLAGS=-O0 -mcpu=arm920t -mtune=arm920t -mstructure-size-boundary=32 -fpack-struct -fno-builtin $(COMPAT) -I $(i)
CPPFLAGS=$(CFLAGS)
CC=arm-elf-gcc
#MAKE=arm-elf-make
MAKE=make

LDFLAGS = -i
LIBS =  -Wl,--start-group ../../lib/obj-gnu/*.a  /usr/local/arm-elf/lib/gcc/arm-elf/4.4.1/*.a -Wl,--end-group -nostartfiles -nodefaultlibs 
OBJ = tty.o console.o pty.o
BUILDDIR=../obj-ARM

# build local binary 
all build:	$(DRIVER)
$(DRIVER):	$(OBJ) 
#	$(CC) -o $@ $(LDFLAGS) $(OBJ) $(LIBS)		
	ar cr $(BUILDDIR)/$@.a $(OBJ)

clean:
	rm -f $(DRIVER) *.o *.bak 

depend: 
	mkdep "$(CC) -E $(CPPFLAGS)" *.c > .depend

# Include generated dependencies.
#include .depend


