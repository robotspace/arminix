# Makefile for all device drivers.
#
MAKE = exec make -$(MAKEFLAGS)

usage:
	@echo "" >&2
	@echo "Makefile for all device drivers." >&2
	@echo "Usage:" >&2
	@echo "	make build    # Compile all device drivers locally" >&2
	@echo "	make image    # Compile drivers in boot image" >&2
	@echo "	make clean    # Remove local compiler results" >&2
	@echo "	make install  # Install drivers to /etc/drivers/" >&2
	@echo "	                (requires root privileges)" >&2
	@echo "" >&2

build: all
all install depend clean:
	cd ./libdriver && $(MAKE) $@
	cd ./libdriver_asyn && $(MAKE) $@
#	cd ./tty && $(MAKE) $@
#	cd ./amddev && $(MAKE) $@
#	cd ./at_wini && $(MAKE) $@
#	cd ./audio && $(MAKE) $@
#	cd ./floppy && $(MAKE) $@
#	cd ./printer && $(MAKE) $@
#	cd ./rtl8139 && $(MAKE) $@
#	cd ./orinoco && $(MAKE) $@
#	cd ./fxp && $(MAKE) $@
#	cd ./dpeth && $(MAKE) $@
	cd ./log && $(MAKE) $@
#	cd ./bios_wini && $(MAKE) $@
#	cd ./random && $(MAKE) $@
#	cd ./readclock && $(MAKE) $@
#	cd ./dp8390 && $(MAKE) $@
#	cd ./sb16 && $(MAKE) $@
#	cd ./lance && $(MAKE) $@
#	cd ./pci && $(MAKE) $@
#	cd ./ti1225 && $(MAKE) $@
# Must be last for ramdisk image
	cd ./memory && $(MAKE) $@

image:
	cd ./libdriver && $(MAKE) build
	cd ./libdriver_asyn && $(MAKE) build
	cd ./tty && $(MAKE) build
	cd ./at_wini && $(MAKE) build
	cd ./floppy && $(MAKE) build
	cd ./bios_wini && $(MAKE) build
	cd ./log && $(MAKE) build
	cd ./pci && $(MAKE) build
	cd ./memory && $(MAKE) build	# Must be last for ramdisk image
