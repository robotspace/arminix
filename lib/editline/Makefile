#Generated from .//editline/Makefile.in
all: all-ack

all-ack:
all-gnu:

makefiles: Makefile
Makedepend-ack Makedepend-gnu: 
	sh .././generate.sh .//editline .././obj-ack/ .././obj-gcc/

Makefile: Makefile.in Makedepend-ack Makedepend-gnu
	sh .././generate.sh .//editline .././obj-ack/ .././obj-gcc/
	@echo
	@echo *Attention*
	@echo Makefile is regenerated... rerun command to see changes
	@echo *Attention*
	@echo

depend: depend-ack
all-ack: .././obj-ack//libedit.a

.././obj-ack//libedit.a: .././obj-ack//libedit.a(editline.o)
.././obj-ack//libedit.a: .././obj-ack//libedit.a(complete.o)
.././obj-ack//libedit.a: .././obj-ack//libedit.a(sysunix.o)

.././obj-ack//libedit.a:
	ar cr .././obj-ack//libedit.a .././obj-ack//.//editline/*.o
	rm .././obj-ack//.//editline/*.o

.././obj-ack//libedit.a(editline.o): editline.c
	cc -O -D_MINIX -D_POSIX_SOURCE -DANSI_ARROWS -DHAVE_STDLIB -DHAVE_TCGETATTR -DHIDE -DUSE_DIRENT 	-DHIST_SIZE=100 -DUSE_TERMCAP -DSYS_UNIX -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-ack//.//editline/editline.o editline.c
.././obj-ack//libedit.a(complete.o): complete.c
	cc -O -D_MINIX -D_POSIX_SOURCE -DANSI_ARROWS -DHAVE_STDLIB -DHAVE_TCGETATTR -DHIDE -DUSE_DIRENT 	-DHIST_SIZE=100 -DUSE_TERMCAP -DSYS_UNIX -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-ack//.//editline/complete.o complete.c
.././obj-ack//libedit.a(sysunix.o): sysunix.c
	cc -O -D_MINIX -D_POSIX_SOURCE -DANSI_ARROWS -DHAVE_STDLIB -DHAVE_TCGETATTR -DHIDE -DUSE_DIRENT 	-DHIST_SIZE=100 -DUSE_TERMCAP -DSYS_UNIX -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-ack//.//editline/sysunix.o sysunix.c

all-gnu: .././obj-gcc//libedit.a

.././obj-gcc//libedit.a: .././obj-gcc//.//editline/editline.o
.././obj-gcc//libedit.a: .././obj-gcc//.//editline/complete.o
.././obj-gcc//libedit.a: .././obj-gcc//.//editline/sysunix.o

.././obj-gcc//libedit.a:
	ar cr .././obj-gcc//libedit.a $?

.././obj-gcc//.//editline/editline.o: editline.c
	arm-elf-gcc -O -D_MINIX -D_POSIX_SOURCE -DANSI_ARROWS -DHAVE_STDLIB -DHAVE_TCGETATTR -DHIDE -DUSE_DIRENT 	-DHIST_SIZE=100 -DUSE_TERMCAP -DSYS_UNIX -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//editline/editline.o editline.c

.././obj-gcc//.//editline/complete.o: complete.c
	arm-elf-gcc -O -D_MINIX -D_POSIX_SOURCE -DANSI_ARROWS -DHAVE_STDLIB -DHAVE_TCGETATTR -DHIDE -DUSE_DIRENT 	-DHIST_SIZE=100 -DUSE_TERMCAP -DSYS_UNIX -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//editline/complete.o complete.c

.././obj-gcc//.//editline/sysunix.o: sysunix.c
	arm-elf-gcc -O -D_MINIX -D_POSIX_SOURCE -DANSI_ARROWS -DHAVE_STDLIB -DHAVE_TCGETATTR -DHIDE -DUSE_DIRENT 	-DHIST_SIZE=100 -DUSE_TERMCAP -DSYS_UNIX -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//editline/sysunix.o sysunix.c




clean::
	rm -f .././obj-ack//.//editline/*
	rm -f .././obj-gcc//.//editline/*

include Makedepend-ack
include .depend-ack

include Makedepend-gnu
include .depend-gnu
