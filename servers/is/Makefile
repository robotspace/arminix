# Makefile for Information Server (IS)
SERVER = is

# programs, flags, etc.
CFLAGS= -O0 -mcpu=arm920t -mtune=arm920t -mstructure-size-boundary=32 -fpack-struct -fno-builtin -I ../../kernel/arch/ARM/include
CC=arm-elf-gcc
LIBS=-Wl,--start-group ../../new_lib/obj-gcc/*.a  /usr/local/arm-elf/lib/gcc/arm-elf/4.4.1/*.a -Wl,--end-group -nodefaultlibs -B ../../new_lib/obj-gcc/ARM
OBJ = main.o dmp.o dmp_kernel.o dmp_pm.o dmp_fs.o dmp_rs.o dmp_ds.o 


# build local binary
all build:$(SERVER)
$(SERVER):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(SERVER).elf

# clean up local files
clean:
	rm -f $(SERVER).elf *.o *.bak
