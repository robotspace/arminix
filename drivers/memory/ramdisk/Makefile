#directories
u = ../../../
i = $u/include
s = $i/sys
m = $i/minix
b = $i/ibm
d = ..

OUTFILE= ramdisk
CPPFLAGS=
CFLAGS=-g -O0 -mcpu=arm920t -mtune=arm920t -mstructure-size-boundary=32 -fpack-struct -fno-builtin -I$i
CC=arm-elf-gcc
LIBS = -Wl,--start-group $u/lib/obj-gnu/*.a  /usr/local/arm-elf/lib/gcc/arm-elf/4.4.1/*.a -Wl,--end-group -nostartfiles -nodefaultlibs 
LDFLAGS = 
OBJ = bintoc.o


# build local binary
all build:	$(OUTFILE)
$(OUTFILE):	$(OBJ)
	$(CC) -o $@.o $(LDFLAGS) $(OBJ) $(LIBS)
	
	
clean:
	rm -f $(OUTFILE) *.o *.bak 