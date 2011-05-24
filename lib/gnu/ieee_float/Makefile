#Generated from .//gnu/ieee_float/Makefile.in
all: all-ack

all-ack:
all-gnu:

makefiles: Makefile
Makedepend-ack Makedepend-gnu: 
	sh ../.././generate.sh .//gnu/ieee_float ../.././obj-ack/ ../.././obj-gcc/

Makefile: Makefile.in Makedepend-ack Makedepend-gnu
	sh ../.././generate.sh .//gnu/ieee_float ../.././obj-ack/ ../.././obj-gcc/
	@echo
	@echo *Attention*
	@echo Makefile is regenerated... rerun command to see changes
	@echo *Attention*
	@echo

depend: depend-ack
all-gnu: ../.././obj-gcc//libc.a

../.././obj-gcc//libc.a: ../.././obj-gcc//.//gnu/ieee_float/frexp.o
../.././obj-gcc//libc.a: ../.././obj-gcc//.//gnu/ieee_float/isinf.o
../.././obj-gcc//libc.a: ../.././obj-gcc//.//gnu/ieee_float/isnan.o
../.././obj-gcc//libc.a: ../.././obj-gcc//.//gnu/ieee_float/ldexp.o
../.././obj-gcc//libc.a: ../.././obj-gcc//.//gnu/ieee_float/modf.o
../.././obj-gcc//libc.a: ../.././obj-gcc//.//gnu/ieee_float/fphook.o

../.././obj-gcc//libc.a:
	ar cr ../.././obj-gcc//libc.a $?

../.././obj-gcc//.//gnu/ieee_float/frexp.o: frexp.c
	arm-elf-gcc -O -I.. -nostartfiles -nodefaultlibs -O0 -mcpu=arm920t -mtune=arm920t -c -o ../.././obj-gcc//.//gnu/ieee_float/frexp.o frexp.c

../.././obj-gcc//.//gnu/ieee_float/isinf.o: isinf.c
	arm-elf-gcc -O -I.. -nostartfiles -nodefaultlibs -O0 -mcpu=arm920t -mtune=arm920t -c -o ../.././obj-gcc//.//gnu/ieee_float/isinf.o isinf.c

../.././obj-gcc//.//gnu/ieee_float/isnan.o: isnan.c
	arm-elf-gcc -O -I.. -nostartfiles -nodefaultlibs -O0 -mcpu=arm920t -mtune=arm920t -c -o ../.././obj-gcc//.//gnu/ieee_float/isnan.o isnan.c

../.././obj-gcc//.//gnu/ieee_float/ldexp.o: ldexp.c
	arm-elf-gcc -O -I.. -nostartfiles -nodefaultlibs -O0 -mcpu=arm920t -mtune=arm920t -c -o ../.././obj-gcc//.//gnu/ieee_float/ldexp.o ldexp.c

../.././obj-gcc//.//gnu/ieee_float/modf.o: modf.c
	arm-elf-gcc -O -I.. -nostartfiles -nodefaultlibs -O0 -mcpu=arm920t -mtune=arm920t -c -o ../.././obj-gcc//.//gnu/ieee_float/modf.o modf.c

../.././obj-gcc//.//gnu/ieee_float/fphook.o: fphook.c
	arm-elf-gcc -O -I.. -nostartfiles -nodefaultlibs -O0 -mcpu=arm920t -mtune=arm920t -c -o ../.././obj-gcc//.//gnu/ieee_float/fphook.o fphook.c




clean::
	rm -f ../.././obj-gcc//.//gnu/ieee_float/*

include Makedepend-ack
include .depend-ack

include Makedepend-gnu
include .depend-gnu
