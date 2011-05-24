#Generated from .//gnu/end/Makefile.in
all: all-ack

all-ack:
all-gnu:

makefiles: Makefile
Makedepend-ack Makedepend-gnu: 
	sh ../.././generate.sh .//gnu/end ../.././obj-ack/ ../.././obj-gcc/

Makefile: Makefile.in Makedepend-ack Makedepend-gnu
	sh ../.././generate.sh .//gnu/end ../.././obj-ack/ ../.././obj-gcc/
	@echo
	@echo *Attention*
	@echo Makefile is regenerated... rerun command to see changes
	@echo *Attention*
	@echo

depend: depend-ack
all-gnu: ../.././obj-gcc//end.a

../.././obj-gcc//end.a: ../.././obj-gcc//.//gnu/end/gnu_end.o

../.././obj-gcc//end.a:
	ar cr ../.././obj-gcc//end.a $?

../.././obj-gcc//.//gnu/end/gnu_end.o: gnu_end.gs
	arm-elf-gcc  -nostartfiles -nodefaultlibs -O0 -mcpu=arm920t -mtune=arm920t -c -o ../.././obj-gcc//.//gnu/end/gnu_end.o gnu_end.gs




clean::
	rm -f ../.././obj-gcc//.//gnu/end/*

include Makedepend-ack
include .depend-ack

include Makedepend-gnu
include .depend-gnu
