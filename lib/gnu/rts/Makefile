#Generated from .//gnu/rts/Makefile.in
all: all-ack

all-ack:
all-gnu:

makefiles: Makefile
Makedepend-ack Makedepend-gnu: 
	sh ../.././generate.sh .//gnu/rts ../.././obj-ack/ ../.././obj-gcc/

Makefile: Makefile.in Makedepend-ack Makedepend-gnu
	sh ../.././generate.sh .//gnu/rts ../.././obj-ack/ ../.././obj-gcc/
	@echo
	@echo *Attention*
	@echo Makefile is regenerated... rerun command to see changes
	@echo *Attention*
	@echo

depend: depend-ack
all-gnu: ../.././obj-gcc//libc.a

../.././obj-gcc//libc.a: ../.././obj-gcc//.//gnu/rts/__setjmp.o
../.././obj-gcc//libc.a: ../.././obj-gcc//.//gnu/rts/longjmp.o

../.././obj-gcc//libc.a:
	ar cr ../.././obj-gcc//libc.a $?

../.././obj-gcc//.//gnu/rts/__setjmp.o: __setjmp.gs
	arm-elf-gcc  -nostartfiles -nodefaultlibs -O0 -mcpu=arm920t -mtune=arm920t -c -o ../.././obj-gcc//.//gnu/rts/__setjmp.o __setjmp.gs

../.././obj-gcc//.//gnu/rts/longjmp.o: longjmp.gs
	arm-elf-gcc  -nostartfiles -nodefaultlibs -O0 -mcpu=arm920t -mtune=arm920t -c -o ../.././obj-gcc//.//gnu/rts/longjmp.o longjmp.gs




clean::
	rm -f ../.././obj-gcc//.//gnu/rts/*

include Makedepend-ack
include .depend-ack

include Makedepend-gnu
include .depend-gnu
