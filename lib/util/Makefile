#Generated from .//util/Makefile.in
all: all-ack

all-ack:
all-gnu:

makefiles: Makefile
Makedepend-ack Makedepend-gnu: 
	sh .././generate.sh .//util .././obj-ack/ .././obj-gcc/

Makefile: Makefile.in Makedepend-ack Makedepend-gnu
	sh .././generate.sh .//util .././obj-ack/ .././obj-gcc/
	@echo
	@echo *Attention*
	@echo Makefile is regenerated... rerun command to see changes
	@echo *Attention*
	@echo

depend: depend-ack
all-ack: .././obj-ack//libutil.a

.././obj-ack//libutil.a: .././obj-ack//libutil.a(openpty.o)

.././obj-ack//libutil.a:
	ar cr .././obj-ack//libutil.a .././obj-ack//.//util/*.o
	rm .././obj-ack//.//util/*.o

.././obj-ack//libutil.a(openpty.o): openpty.c
	cc -O -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-ack//.//util/openpty.o openpty.c

all-gnu: .././obj-gcc//libutil.a

.././obj-gcc//libutil.a: .././obj-gcc//.//util/openpty.o

.././obj-gcc//libutil.a:
	ar cr .././obj-gcc//libutil.a $?

.././obj-gcc//.//util/openpty.o: openpty.c
	arm-elf-gcc -O -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//util/openpty.o openpty.c




clean::
	rm -f .././obj-ack//.//util/*
	rm -f .././obj-gcc//.//util/*

include Makedepend-ack
include .depend-ack

include Makedepend-gnu
include .depend-gnu
