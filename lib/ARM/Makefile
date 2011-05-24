#Generated from .//ARM/Makefile.in
all: all-ack

all-ack:
all-gnu:

makefiles: Makefile
Makedepend-ack Makedepend-gnu: 
	sh .././generate.sh .//ARM .././obj-ack/ .././obj-gcc/

Makefile: Makefile.in Makedepend-ack Makedepend-gnu
	sh .././generate.sh .//ARM .././obj-ack/ .././obj-gcc/
	@echo
	@echo *Attention*
	@echo Makefile is regenerated... rerun command to see changes
	@echo *Attention*
	@echo

depend: depend-ack
all-gnu: .././obj-gcc//ARM.a

.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/brksize.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/crt0.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/environ.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/exit.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/io.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/io_intr.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/ipc.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/math.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/memchr.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/memcpy.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/memcmp.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/memmove.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/memset.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/misc.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/strcat.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/strchr.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/strcmp.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/strcpy.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/strncat.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/strncmp.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/strlen.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/strrchr.o
.././obj-gcc//ARM.a: .././obj-gcc//.//ARM/strncpy.o

.././obj-gcc//ARM.a:
	ar cr .././obj-gcc//ARM.a $?

.././obj-gcc//.//ARM/brksize.o: brksize.s
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/brksize.o brksize.s

.././obj-gcc//.//ARM/crt0.o: crt0.s
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/crt0.o crt0.s

.././obj-gcc//.//ARM/environ.o: environ.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/environ.o environ.c

.././obj-gcc//.//ARM/exit.o: exit.s
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/exit.o exit.s

.././obj-gcc//.//ARM/io.o: io.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/io.o io.c

.././obj-gcc//.//ARM/io_intr.o: io_intr.s
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/io_intr.o io_intr.s

.././obj-gcc//.//ARM/ipc.o: ipc.s
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/ipc.o ipc.s

.././obj-gcc//.//ARM/math.o: math.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/math.o math.c

.././obj-gcc//.//ARM/memchr.o: memchr.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/memchr.o memchr.c

.././obj-gcc//.//ARM/memcpy.o: memcpy.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/memcpy.o memcpy.c

.././obj-gcc//.//ARM/memcmp.o: memcmp.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/memcmp.o memcmp.c

.././obj-gcc//.//ARM/memmove.o: memmove.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/memmove.o memmove.c

.././obj-gcc//.//ARM/memset.o: memset.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/memset.o memset.c

.././obj-gcc//.//ARM/misc.o: misc.s
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/misc.o misc.s

.././obj-gcc//.//ARM/strcat.o: strcat.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/strcat.o strcat.c

.././obj-gcc//.//ARM/strchr.o: strchr.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/strchr.o strchr.c

.././obj-gcc//.//ARM/strcmp.o: strcmp.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/strcmp.o strcmp.c

.././obj-gcc//.//ARM/strcpy.o: strcpy.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/strcpy.o strcpy.c

.././obj-gcc//.//ARM/strncat.o: strncat.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/strncat.o strncat.c

.././obj-gcc//.//ARM/strncmp.o: strncmp.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/strncmp.o strncmp.c

.././obj-gcc//.//ARM/strlen.o: strlen.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/strlen.o strlen.c

.././obj-gcc//.//ARM/strrchr.o: strrchr.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/strrchr.o strrchr.c

.././obj-gcc//.//ARM/strncpy.o: strncpy.c
	arm-elf-gcc -D_MINIX -D_POSIX_SOURCE -nostartfiles -nodefaultlibs -O0 -mtune=arm920t -fno-builtin -c -o .././obj-gcc//.//ARM/strncpy.o strncpy.c




clean::
	rm -f .././obj-gcc//.//ARM/*

include Makedepend-ack
include .depend-ack

include Makedepend-gnu
include .depend-gnu
