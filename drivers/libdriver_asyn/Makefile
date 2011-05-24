# Makefile for driver library
DRIVER=libdriver_asyn
# Directories
u = /usr
i = $u/include
s = $i/sys
b = $i/ibm
m = $i/minix

# Programs, flags, etc.
#CC = exec cc
#CFLAGS = -I$i $(CPROFILE)
#LDFLAGS = -i
#LIBS = -lsys
#LIB = libdriver.a

COMPAT= -Dmain=$(DRIVER)_main \
				-Ddriver_task=$(DRIVER)_driver_task \
				-Dno_name=$(DRIVER)_no_name \
				-Ddo_nop=$(DRIVER)_do_nop \
				-Dnop_ioctl=$(DRIVER)_nop_ioctl \
				-Dnop_signal=$(DRIVER)_nop_signal \
				-Dnop_alarm=$(DRIVER)_nop_alarm \
				-Dnop_prepare=$(DRIVER)_nop_prepare \
				-Dnop_cleanup=$(DRIVER)_nop_cleanup \
				-Dnop_cancel=$(DRIVER)_nop_cancel \
				-Dnop_select=$(DRIVER)_nop_select \
				-Ddo_diocntl=$(DRIVER)_do_diocntl \
				-Dmq_queue=$(DRIVER)_mq_queue
				
CFLAGS=-O0 -mcpu=arm920t -mtune=arm920t -mstructure-size-boundary=32 -fpack-struct -fno-builtin $(COMPAT)
CC=arm-elf-gcc
LIBS=-Wl,--start-group ../lib/obj-gnu/*.a  /usr/local/arm-elf/lib/gcc/arm-elf/4.4.1/*.a -Wl,--end-group -nostartfiles -nodefaultlibs 
BUILDDIR=../obj-ARM

DRIVER = libdriver_asyn
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

