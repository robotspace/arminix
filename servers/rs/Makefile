# Makefile for Reincarnation Server (RS)
SERVER = rs
UTIL = service

# programs, flags, etc.
CFLAGS= -O0 -mcpu=arm920t -mtune=arm920t -mstructure-size-boundary=32 -fpack-struct -fno-builtin -I ../../kernel/arch/ARM/include
CC=arm-elf-gcc
LIBS=-Wl,--start-group ../../new_lib/obj-gcc/*.a  /usr/local/arm-elf/lib/gcc/arm-elf/4.4.1/*.a -Wl,--end-group -nodefaultlibs -B ../../new_lib/obj-gcc/ARM
UTIL_OBJ = service.o
OBJ = exec.o main.o manager.o 

# build local binary
all build:	$(SERVER) $(UTIL)
$(UTIL):	$(UTIL_OBJ)
	$(CC) -o $@.elf $(LDFLAGS) $(UTIL_OBJ) $(LIBS)
$(SERVER):	$(OBJ)
	$(CC) -o $@.elf $(LDFLAGS) $(OBJ) $(LIBS)
	

# clean up local files
clean:
	rm -f $(SERVER).elf $(UTIL).elf *.o *.bak