#Generated from .//timers/Makefile.in
all: all-ack

all-ack:
all-gnu:

makefiles: Makefile
Makedepend-ack Makedepend-gnu: 
	sh .././generate.sh .//timers .././obj-ack/ .././obj-gcc/

Makefile: Makefile.in Makedepend-ack Makedepend-gnu
	sh .././generate.sh .//timers .././obj-ack/ .././obj-gcc/
	@echo
	@echo *Attention*
	@echo Makefile is regenerated... rerun command to see changes
	@echo *Attention*
	@echo

depend: depend-ack
all-ack: .././obj-ack//libtimers.a

.././obj-ack//libtimers.a: .././obj-ack//libtimers.a(tmrs_set.o)
.././obj-ack//libtimers.a: .././obj-ack//libtimers.a(tmrs_clr.o)
.././obj-ack//libtimers.a: .././obj-ack//libtimers.a(tmrs_exp.o)

.././obj-ack//libtimers.a:
	ar cr .././obj-ack//libtimers.a .././obj-ack//.//timers/*.o
	rm .././obj-ack//.//timers/*.o

.././obj-ack//libtimers.a(tmrs_set.o): tmrs_set.c
	cc -O -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-ack//.//timers/tmrs_set.o tmrs_set.c
.././obj-ack//libtimers.a(tmrs_clr.o): tmrs_clr.c
	cc -O -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-ack//.//timers/tmrs_clr.o tmrs_clr.c
.././obj-ack//libtimers.a(tmrs_exp.o): tmrs_exp.c
	cc -O -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-ack//.//timers/tmrs_exp.o tmrs_exp.c

all-gnu: .././obj-gcc//libtimers.a

.././obj-gcc//libtimers.a: .././obj-gcc//.//timers/tmrs_set.o
.././obj-gcc//libtimers.a: .././obj-gcc//.//timers/tmrs_clr.o
.././obj-gcc//libtimers.a: .././obj-gcc//.//timers/tmrs_exp.o

.././obj-gcc//libtimers.a:
	ar cr .././obj-gcc//libtimers.a $?

.././obj-gcc//.//timers/tmrs_set.o: tmrs_set.c
	arm-elf-gcc -O -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//timers/tmrs_set.o tmrs_set.c

.././obj-gcc//.//timers/tmrs_clr.o: tmrs_clr.c
	arm-elf-gcc -O -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//timers/tmrs_clr.o tmrs_clr.c

.././obj-gcc//.//timers/tmrs_exp.o: tmrs_exp.c
	arm-elf-gcc -O -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//timers/tmrs_exp.o tmrs_exp.c




clean::
	rm -f .././obj-ack//.//timers/*
	rm -f .././obj-gcc//.//timers/*

include Makedepend-ack
include .depend-ack

include Makedepend-gnu
include .depend-gnu
