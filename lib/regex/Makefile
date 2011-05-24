#Generated from .//regex/Makefile.in
all: all-ack

all-ack:
all-gnu:

makefiles: Makefile
Makedepend-ack Makedepend-gnu: 
	sh .././generate.sh .//regex .././obj-ack/ .././obj-gcc/

Makefile: Makefile.in Makedepend-ack Makedepend-gnu
	sh .././generate.sh .//regex .././obj-ack/ .././obj-gcc/
	@echo
	@echo *Attention*
	@echo Makefile is regenerated... rerun command to see changes
	@echo *Attention*
	@echo

depend: depend-ack
all-ack: .././obj-ack//libc.a

.././obj-ack//libc.a: .././obj-ack//libc.a(regcomp.o)
.././obj-ack//libc.a: .././obj-ack//libc.a(regerror.o)
.././obj-ack//libc.a: .././obj-ack//libc.a(regexec.o)
.././obj-ack//libc.a: .././obj-ack//libc.a(regfree.o)

.././obj-ack//libc.a:
	ar cr .././obj-ack//libc.a .././obj-ack//.//regex/*.o
	rm .././obj-ack//.//regex/*.o

.././obj-ack//libc.a(regcomp.o): regcomp.c
	cc -O -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-ack//.//regex/regcomp.o regcomp.c
.././obj-ack//libc.a(regerror.o): regerror.c
	cc -O -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-ack//.//regex/regerror.o regerror.c
.././obj-ack//libc.a(regexec.o): regexec.c
	cc -O -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-ack//.//regex/regexec.o regexec.c
.././obj-ack//libc.a(regfree.o): regfree.c
	cc -O -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-ack//.//regex/regfree.o regfree.c

all-gnu: .././obj-gcc//libc.a

.././obj-gcc//libc.a: .././obj-gcc//.//regex/regcomp.o
.././obj-gcc//libc.a: .././obj-gcc//.//regex/regerror.o
.././obj-gcc//libc.a: .././obj-gcc//.//regex/regexec.o
.././obj-gcc//libc.a: .././obj-gcc//.//regex/regfree.o

.././obj-gcc//libc.a:
	ar cr .././obj-gcc//libc.a $?

.././obj-gcc//.//regex/regcomp.o: regcomp.c
	arm-elf-gcc -O -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//regex/regcomp.o regcomp.c

.././obj-gcc//.//regex/regerror.o: regerror.c
	arm-elf-gcc -O -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//regex/regerror.o regerror.c

.././obj-gcc//.//regex/regexec.o: regexec.c
	arm-elf-gcc -O -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//regex/regexec.o regexec.c

.././obj-gcc//.//regex/regfree.o: regfree.c
	arm-elf-gcc -O -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//regex/regfree.o regfree.c




clean::
	rm -f .././obj-ack//.//regex/*
	rm -f .././obj-gcc//.//regex/*

include Makedepend-ack
include .depend-ack

include Makedepend-gnu
include .depend-gnu
