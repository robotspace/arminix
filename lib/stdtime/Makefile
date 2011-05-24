#Generated from .//stdtime/Makefile.in
all: all-ack

all-ack:
all-gnu:

makefiles: Makefile
Makedepend-ack Makedepend-gnu: 
	sh .././generate.sh .//stdtime .././obj-ack/ .././obj-gcc/

Makefile: Makefile.in Makedepend-ack Makedepend-gnu
	sh .././generate.sh .//stdtime .././obj-ack/ .././obj-gcc/
	@echo
	@echo *Attention*
	@echo Makefile is regenerated... rerun command to see changes
	@echo *Attention*
	@echo

depend: depend-ack
all-ack: .././obj-ack//libc.a

.././obj-ack//libc.a: .././obj-ack//libc.a(asctime.o)
.././obj-ack//libc.a: .././obj-ack//libc.a(localtime.o)
.././obj-ack//libc.a: .././obj-ack//libc.a(strftime.o)

.././obj-ack//libc.a:
	ar cr .././obj-ack//libc.a .././obj-ack//.//stdtime/*.o
	rm .././obj-ack//.//stdtime/*.o

.././obj-ack//libc.a(asctime.o): asctime.c
	cc -D_MINIX -D_POSIX_SOURCE -D__USG -I../../commands/zoneinfo -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-ack//.//stdtime/asctime.o asctime.c
.././obj-ack//libc.a(localtime.o): localtime.c
	cc -D_MINIX -D_POSIX_SOURCE -D__USG -I../../commands/zoneinfo -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-ack//.//stdtime/localtime.o localtime.c
.././obj-ack//libc.a(strftime.o): strftime.c
	cc -D_MINIX -D_POSIX_SOURCE -D__USG -I../../commands/zoneinfo -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-ack//.//stdtime/strftime.o strftime.c

all-gnu: .././obj-gcc//libc.a

.././obj-gcc//libc.a: .././obj-gcc//.//stdtime/asctime.o
.././obj-gcc//libc.a: .././obj-gcc//.//stdtime/localtime.o
.././obj-gcc//libc.a: .././obj-gcc//.//stdtime/strftime.o

.././obj-gcc//libc.a:
	ar cr .././obj-gcc//libc.a $?

.././obj-gcc//.//stdtime/asctime.o: asctime.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -D__USG -I../../commands/zoneinfo -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//stdtime/asctime.o asctime.c

.././obj-gcc//.//stdtime/localtime.o: localtime.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -D__USG -I../../commands/zoneinfo -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//stdtime/localtime.o localtime.c

.././obj-gcc//.//stdtime/strftime.o: strftime.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -D__USG -I../../commands/zoneinfo -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//stdtime/strftime.o strftime.c




clean::
	rm -f .././obj-ack//.//stdtime/*
	rm -f .././obj-gcc//.//stdtime/*

include Makedepend-ack
include .depend-ack

include Makedepend-gnu
include .depend-gnu
