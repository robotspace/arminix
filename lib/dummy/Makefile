#Generated from .//dummy/Makefile.in
all: all-ack

all-ack:
all-gnu:

makefiles: Makefile
Makedepend-ack Makedepend-gnu: 
	sh .././generate.sh .//dummy .././obj-ack/ .././obj-gcc/

Makefile: Makefile.in Makedepend-ack Makedepend-gnu
	sh .././generate.sh .//dummy .././obj-ack/ .././obj-gcc/
	@echo
	@echo *Attention*
	@echo Makefile is regenerated... rerun command to see changes
	@echo *Attention*
	@echo

depend: depend-ack
all-ack: .././obj-ack//libm.a

.././obj-ack//libm.a: .././obj-ack//libm.a(dummy.o)

.././obj-ack//libm.a:
	ar cr .././obj-ack//libm.a .././obj-ack//.//dummy/*.o
	rm .././obj-ack//.//dummy/*.o

.././obj-ack//libm.a(dummy.o): dummy.c
	cc  -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-ack//.//dummy/dummy.o dummy.c

all-gnu: .././obj-gcc//libm.a

.././obj-gcc//libm.a: .././obj-gcc//.//dummy/dummy.o

.././obj-gcc//libm.a:
	ar cr .././obj-gcc//libm.a $?

.././obj-gcc//.//dummy/dummy.o: dummy.c
	arm-elf-gcc  -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//dummy/dummy.o dummy.c




clean::
	rm -f .././obj-ack//.//dummy/*
	rm -f .././obj-gcc//.//dummy/*

include Makedepend-ack
include .depend-ack

include Makedepend-gnu
include .depend-gnu
