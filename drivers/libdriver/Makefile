# Makefile for driver library

# Directories
u = ../../
i = $u/include
s = $i/sys
b = $i/ibm
m = $i/minix

# Programs, flags, etc.
#CC = exec cc
#CFLAGS = -I$i $(CPROFILE)
#LDFLAGS = -i
#LIBS = -lsys
CFLAGS=-O0 -mcpu=arm920t -mtune=arm920t -mstructure-size-boundary=32 -fpack-struct -fno-builtin -I$i
CC=arm-elf-gcc
LIBS=-Wl,--start-group ../lib/obj-gnu/*.a  /usr/local/arm-elf/lib/gcc/arm-elf/4.4.1/*.a -Wl,--end-group -nostartfiles -nodefaultlibs 
BUILDDIR=../obj-ARM

DRIVER = libdriver.a
OBJECTS = driver.o drvlib.o mq.o

all build:	$(DRIVER)
$(DRIVER): $(OBJECTS)	
	ar cr $(BUILDDIR)/$@.a $(OBJECTS)
# $(CC) -c $@ $(LDFLAGS) $(OBJ) $(LIBS)

clean:
	rm -f $(DRIVER) *.o *.bak $(BUILDDIR)/$(DRIVER).a

depend: 
	mkdep "$(CC) -E $(CPPFLAGS)" *.c > .depend

# Include generated dependencies.
#include .depend

