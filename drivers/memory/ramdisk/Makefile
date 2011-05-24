OUTFILE= ramdisk
CPPFLAGS=
CFLAGS=-g -O0 -mcpu=arm920t -mtune=arm920t -mstructure-size-boundary=32 -fpack-struct -fno-builtin
CC=arm-elf-gcc
LIBS = -Wl,--start-group /usr/local/arm-elf/minix3/lib/obj-gnu/*.a  /usr/local/arm-elf/lib/gcc/arm-elf/4.4.1/*.a -Wl,--end-group -nostartfiles -nodefaultlibs 
LDFLAGS = 
OBJ = bintoc.o


# build local binary
all build:	$(OUTFILE)
$(OUTFILE):	$(OBJ)
#	$(CC) -o $@.o $(LDFLAGS) $(OBJ) $(LIBS)
	
	
clean:
	rm -f $(OUTFILE) *.o *.bak 