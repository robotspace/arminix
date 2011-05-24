# Hello world test proggel
PROG=hello
# programs, flags, etc.
LNK   = linkerscript
CFLAGS= -O0 -mcpu=arm920t -mtune=arm920t -mstructure-size-boundary=32 -fpack-struct -fno-builtin 
AS=$(CC);
CC=arm-elf-gcc
LIBS=-Wl,-T,$(LNK) -Wl,--start-group ../../new_lib/obj-gcc/*.a  /usr/local/arm-elf/lib/gcc/arm-elf/4.4.1/*.a -Wl,--end-group -nodefaultlibs -nostartfiles
OBJ=main.o utility.o

# build local binary
all build:$(PROG)
$(PROG):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(PROG).elf
	
# clean up local files
clean:
	rm -f $(PROG).elf *.o *.bak
