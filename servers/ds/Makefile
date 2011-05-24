# Makefile for Data Store Server (DS)
SERVER = ds

# programs, flags, etc.
CFLAGS= -O0 -mcpu=arm920t -mtune=arm920t -mstructure-size-boundary=32 -fpack-struct -fno-builtin 
CC=arm-elf-gcc
LIBS=-Wl,--start-group ../../new_lib/obj-gcc/*.a  /usr/local/arm-elf/lib/gcc/arm-elf/4.4.1/*.a -Wl,--end-group -nodefaultlibs -B ../../new_lib/obj-gcc/ARM
OBJ=main.o store.o 


# build local binary
all build:$(SERVER)
$(SERVER):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(SERVER).elf

# clean up local files
clean:
	rm -f $(SERVER).elf *.o *.bak
