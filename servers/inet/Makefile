# Makefile for Inet
SERVER = inet

# Directories
g = generic

# programs, flags, etc.
CFLAGS= -O0 -mcpu=arm920t -mtune=arm920t -mstructure-size-boundary=32 -fpack-struct -fno-builtin -D_MINIX -D__minix
CC=arm-elf-gcc
LIBS=-Wl,--start-group ../../new_lib/obj-gcc/*.a  /usr/local/arm-elf/lib/gcc/arm-elf/4.4.1/*.a -Wl,--end-group -nodefaultlibs -B ../../new_lib/obj-gcc/ARM
OBJ = 	buf.o clock.o inet.o inet_config.o \
	mnx_eth.o mq.o qp.o sr.o stacktrace.o \
	$g/udp.o $g/arp.o $g/eth.o $g/event.o \
	$g/icmp.o $g/io.o $g/ip.o $g/ip_ioctl.o \
	$g/ip_lib.o $g/ip_read.o $g/ip_write.o \
	$g/ipr.o $g/rand256.o $g/tcp.o $g/tcp_lib.o \
	$g/tcp_recv.o $g/tcp_send.o $g/ip_eth.o \
	$g/ip_ps.o $g/psip.o \
	minix3/queryparam.o sha2.o


# build local binary
all build:$(SERVER)
$(SERVER):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) version.c $(LIBS) -o $(SERVER).elf

# clean up local files
clean:
	rm -f $(SERVER).elf *.o *.bak
	rm -f $(g)/*.o