#Generated from .//gnu/Makefile.in
all: all-ack

all-ack:
all-gnu:

makefiles: Makefile
Makedepend-ack Makedepend-gnu: 
	sh .././generate.sh .//gnu .././obj-ack/ .././obj-gcc/

Makefile: Makefile.in Makedepend-ack Makedepend-gnu
	sh .././generate.sh .//gnu .././obj-ack/ .././obj-gcc/
	@echo
	@echo *Attention*
	@echo Makefile is regenerated... rerun command to see changes
	@echo *Attention*
	@echo

all-ack: makefiles
	cd end && $(MAKE) $@
	cd ieee_float && $(MAKE) $@
	cd rts && $(MAKE) $@

all-gnu: makefiles
	mkdir -p .././obj-gcc//.//gnu/end
	cd end && $(MAKE) $@
	mkdir -p .././obj-gcc//.//gnu/ieee_float
	cd ieee_float && $(MAKE) $@
	mkdir -p .././obj-gcc//.//gnu/rts
	cd rts && $(MAKE) $@

clean depend depend-ack depend-gnu:: makefiles
	cd end && $(MAKE) $@
	cd ieee_float && $(MAKE) $@
	cd rts && $(MAKE) $@
	cd do && $(MAKE) $@

makefiles: end/Makefile
makefiles: ieee_float/Makefile
makefiles: rts/Makefile

end/Makefile: end/Makefile.in
	cd end && sh ../.././generate.sh .//gnu/end ../.././obj-ack/ ../.././obj-gcc/ && $(MAKE) makefiles
ieee_float/Makefile: ieee_float/Makefile.in
	cd ieee_float && sh ../.././generate.sh .//gnu/ieee_float ../.././obj-ack/ ../.././obj-gcc/ && $(MAKE) makefiles
rts/Makefile: rts/Makefile.in
	cd rts && sh ../.././generate.sh .//gnu/rts ../.././obj-ack/ ../.././obj-gcc/ && $(MAKE) makefiles

clean::
	rm -f .././obj-gcc//.//gnu/*

include Makedepend-ack
include .depend-ack

include Makedepend-gnu
include .depend-gnu
