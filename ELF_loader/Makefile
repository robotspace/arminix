# Makefile for ELF loader
PROG=loader
# programs, flags, etc.
LNK   = linkerscript
CFLAGS= -g -O0 -mcpu=arm920t -mtune=arm920t -mstructure-size-boundary=32 -fpack-struct -fno-builtin 
AS=$(CC);
CC=arm-elf-gcc
LIBS=-Wl,-T,$(LNK) -Wl,--start-group ../new_lib/obj-gcc/*.a  /usr/local/arm-elf/lib/gcc/arm-elf/4.4.1/*.a -Wl,--end-group -nodefaultlibs  -B ../new_lib/obj-gcc/ARM
OBJ=main.o utility.o util.s

# build local binary
all build:$(PROG)
$(PROG):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(PROG).elf

util.o: util.s
	$(CC) $(CFLAGS) -c util.s
	
# clean up local files
clean:
	rm -f $(PROG).elf *.o *.bak
