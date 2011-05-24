# Makefile for File System (FS)
SERVER = vfs

# programs, flags, etc.
CFLAGS= -O0 -mcpu=arm920t -mtune=arm920t -mstructure-size-boundary=32 -fpack-struct -fno-builtin 
CC=arm-elf-gcc
LIBS=-Wl,--start-group ../../new_lib/obj-gcc/*.a  /usr/local/arm-elf/lib/gcc/arm-elf/4.4.1/*.a -Wl,--end-group -nodefaultlibs -B ../../new_lib/obj-gcc/ARM
OBJ =	main.o open.o read.o write.o pipe.o dmap.o \
	path.o device.o mount.o link.o exec.o \
	filedes.o stadir.o protect.o time.o \
	lock.o misc.o utility.o select.o timers.o table.o \
	vnode.o vmnt.o request.o kputc.o mmap.o


# build local binary
all build:$(SERVER)
$(SERVER):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(SERVER).elf

# clean up local files
clean:
	rm -f $(SERVER).elf *.o *.bak