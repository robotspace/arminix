# Makefile for File System (FS)
SERVER = mfs
NR_BUFS=1024

# programs, flags, etc.
CFLAGS= -O0 -mcpu=arm920t -mtune=arm920t -mstructure-size-boundary=32 -fpack-struct -fno-builtin -DNR_BUFS=$(NR_BUFS)
CC=arm-elf-gcc
LIBS=-Wl,--start-group ../../new_lib/obj-gcc/*.a  /usr/local/arm-elf/lib/gcc/arm-elf/4.4.1/*.a -Wl,--end-group -nodefaultlibs -B ../../new_lib/obj-gcc/ARM
OBJ =	cache.o device.o link.o \
	mount.o misc.o open.o pipe.o protect.o read.o \
	stadir.o table.o time.o utility.o \
	write.o inode.o main.o path.o super.o

# build local binary
all build:$(SERVER)
$(SERVER):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(SERVER).elf

# clean up local files
clean:
	rm -f $(SERVER).elf *.o *.bak
	