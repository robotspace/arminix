# Makefile for log driver
DRIVER = log

# directories
u = ../../
i = $u/include
s = $i/sys
m = $i/minix
d = ..

# programs, flags, etc.
#MAKE = exec make
#CC =	exec cc
#CFLAGS = -I$i $(CPROFILE)
#LDFLAGS = -i -L../libdriver_asyn
#LIBS = -ldriver  -lsys 
COMPAT= -Dmain=$(DRIVER)_main \

				
CFLAGS=-g -O0 -mcpu=arm920t -mtune=arm920t -mstructure-size-boundary=32 -fpack-struct -fno-builtin $(COMPAT) -I$i
CC=arm-elf-gcc
LIBS=-Wl,--start-group ../lib/obj-gnu/*.a  /usr/local/arm-elf/lib/gcc/arm-elf/4.4.1/*.a -Wl,--end-group -nostartfiles -nodefaultlibs 
BUILDDIR=../obj-ARM
LIB_DEP = $(BUILDDIR)/libdriver_asyn.a

OBJ = log.o diag.o kputc.o

# build local binary
all build:	$(DRIVER)
$(DRIVER):	$(OBJ) $(LIB_DEP)
#	$(CC) -o $@ $(LDFLAGS) $(OBJ) $(LIBS)
#	install -S 32kb $(DRIVER)
	ar cr $(BUILDDIR)/$@.a $(OBJ)

# install with other drivers
install:	$(DRIVER)
	install -o root -cs $< /sbin/$(DRIVER) 

# clean up local files
clean:
	rm -f $(DRIVER) *.o *.bak $(BUILDDIR)/$(DRIVER).a


depend: 
	mkdep "$(CC) -E $(CPPFLAGS)" *.c ../libdriver/*.c > .depend

# Include generated dependencies.
#include .depend

