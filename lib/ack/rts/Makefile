#Generated from .//ack/rts/Makefile.in
all: all-ack

all-ack:
all-gnu:

makefiles: Makefile
Makedepend-ack Makedepend-gnu: 
	sh ../.././generate.sh .//ack/rts ../.././obj-ack/ ../.././obj-gcc/

Makefile: Makefile.in Makedepend-ack Makedepend-gnu
	sh ../.././generate.sh .//ack/rts ../.././obj-ack/ ../.././obj-gcc/
	@echo
	@echo *Attention*
	@echo Makefile is regenerated... rerun command to see changes
	@echo *Attention*
	@echo

depend: depend-ack
all-ack: ../.././obj-ack//libc.a

../.././obj-ack//libc.a: ../.././obj-ack//libc.a(setjmp.o)

../.././obj-ack//libc.a:
	ar cr ../.././obj-ack//libc.a ../.././obj-ack//.//ack/rts/*.o
	rm ../.././obj-ack//.//ack/rts/*.o

../.././obj-ack//libc.a(setjmp.o): setjmp.e
	cc -O -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mcpu=arm920t -mtune=arm920t -c -o ../.././obj-ack//.//ack/rts/setjmp.o setjmp.e



clean::
	rm -f ../.././obj-ack//.//ack/rts/*

include Makedepend-ack
include .depend-ack

include Makedepend-gnu
include .depend-gnu
