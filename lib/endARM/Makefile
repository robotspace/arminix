#Generated from .//endARM/Makefile.in
all: all-ack

all-ack:
all-gnu:

makefiles: Makefile
Makedepend-ack Makedepend-gnu: 
	sh .././generate.sh .//endARM .././obj-ack/ .././obj-gcc/

Makefile: Makefile.in Makedepend-ack Makedepend-gnu
	sh .././generate.sh .//endARM .././obj-ack/ .././obj-gcc/
	@echo
	@echo *Attention*
	@echo Makefile is regenerated... rerun command to see changes
	@echo *Attention*
	@echo

depend: depend-ack
all-ack: .././obj-ack//end.a

.././obj-ack//end.a: .././obj-ack//end.a(edata.o)
.././obj-ack//end.a: .././obj-ack//end.a(em_end.o)
.././obj-ack//end.a: .././obj-ack//end.a(end.o)
.././obj-ack//end.a: .././obj-ack//end.a(etext.o)

.././obj-ack//end.a:
	ar cr .././obj-ack//end.a .././obj-ack//.//endARM/*.o
	rm .././obj-ack//.//endARM/*.o

.././obj-ack//end.a(edata.o): edata.s
	cc -mcpu=arm920t -mtune=arm920t -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-ack//.//endARM/edata.o edata.s
.././obj-ack//end.a(em_end.o): em_end.s
	cc -mcpu=arm920t -mtune=arm920t -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-ack//.//endARM/em_end.o em_end.s
.././obj-ack//end.a(end.o): end.s
	cc -mcpu=arm920t -mtune=arm920t -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-ack//.//endARM/end.o end.s
.././obj-ack//end.a(etext.o): etext.s
	cc -mcpu=arm920t -mtune=arm920t -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-ack//.//endARM/etext.o etext.s

all-gnu: .././obj-gcc//end.a

.././obj-gcc//end.a: .././obj-gcc//.//endARM/edata.o
.././obj-gcc//end.a: .././obj-gcc//.//endARM/em_end.o
.././obj-gcc//end.a: .././obj-gcc//.//endARM/end.o
.././obj-gcc//end.a: .././obj-gcc//.//endARM/etext.o

.././obj-gcc//end.a:
	ar cr .././obj-gcc//end.a $?

.././obj-gcc//.//endARM/edata.o: edata.s
	arm-elf-gcc -mcpu=arm920t -mtune=arm920t -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//endARM/edata.o edata.s

.././obj-gcc//.//endARM/em_end.o: em_end.s
	arm-elf-gcc -mcpu=arm920t -mtune=arm920t -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//endARM/em_end.o em_end.s

.././obj-gcc//.//endARM/end.o: end.s
	arm-elf-gcc -mcpu=arm920t -mtune=arm920t -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//endARM/end.o end.s

.././obj-gcc//.//endARM/etext.o: etext.s
	arm-elf-gcc -mcpu=arm920t -mtune=arm920t -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//endARM/etext.o etext.s




clean::
	rm -f .././obj-ack//.//endARM/*
	rm -f .././obj-gcc//.//endARM/*

include Makedepend-ack
include .depend-ack

include Makedepend-gnu
include .depend-gnu
