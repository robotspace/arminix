#Generated from .//Makefile.in
all: all-ack

all-ack:
all-gnu:

makefiles: Makefile
Makedepend-ack Makedepend-gnu: 
	sh ./generate.sh ./ ./obj-ack/ ./obj-gcc/

Makefile: Makefile.in Makedepend-ack Makedepend-gnu
	sh ./generate.sh ./ ./obj-ack/ ./obj-gcc/
	@echo
	@echo *Attention*
	@echo Makefile is regenerated... rerun command to see changes
	@echo *Attention*
	@echo

all-ack: makefiles
	mkdir -p ./obj-ack//.//ansi
	cd ansi && $(MAKE) $@
	mkdir -p ./obj-ack//.//curses
	cd curses && $(MAKE) $@
	mkdir -p ./obj-ack//.//dummy
	cd dummy && $(MAKE) $@
	mkdir -p ./obj-ack//.//editline
	cd editline && $(MAKE) $@
	mkdir -p ./obj-ack//.//endARM
	cd endARM && $(MAKE) $@
	mkdir -p ./obj-ack//.//ip
	cd ip && $(MAKE) $@
	mkdir -p ./obj-ack//.//math
	cd math && $(MAKE) $@
	mkdir -p ./obj-ack//.//other
	cd other && $(MAKE) $@
	mkdir -p ./obj-ack//.//posix
	cd posix && $(MAKE) $@
	mkdir -p ./obj-ack//.//regex
	cd regex && $(MAKE) $@
	mkdir -p ./obj-ack//.//stdio
	cd stdio && $(MAKE) $@
	mkdir -p ./obj-ack//.//stdtime
	cd stdtime && $(MAKE) $@
	mkdir -p ./obj-ack//.//syscallARM
	cd syscallARM && $(MAKE) $@
	mkdir -p ./obj-ack//.//syslib
	cd syslib && $(MAKE) $@
	mkdir -p ./obj-ack//.//util
	cd util && $(MAKE) $@
	mkdir -p ./obj-ack//.//sysutil
	cd sysutil && $(MAKE) $@
	mkdir -p ./obj-ack//.//timers
	cd timers && $(MAKE) $@
	mkdir -p ./obj-ack//.//ARM
	cd ARM && $(MAKE) $@
	mkdir -p ./obj-ack//.//ack
	cd ack && $(MAKE) $@
	mkdir -p ./obj-ack//.//gnu
	cd gnu && $(MAKE) $@

all-gnu: makefiles
	mkdir -p ./obj-gcc//.//ansi
	cd ansi && $(MAKE) $@
	mkdir -p ./obj-gcc//.//curses
	cd curses && $(MAKE) $@
	mkdir -p ./obj-gcc//.//dummy
	cd dummy && $(MAKE) $@
	mkdir -p ./obj-gcc//.//editline
	cd editline && $(MAKE) $@
	mkdir -p ./obj-gcc//.//endARM
	cd endARM && $(MAKE) $@
	mkdir -p ./obj-gcc//.//ip
	cd ip && $(MAKE) $@
	mkdir -p ./obj-gcc//.//math
	cd math && $(MAKE) $@
	mkdir -p ./obj-gcc//.//other
	cd other && $(MAKE) $@
	mkdir -p ./obj-gcc//.//posix
	cd posix && $(MAKE) $@
	mkdir -p ./obj-gcc//.//regex
	cd regex && $(MAKE) $@
	mkdir -p ./obj-gcc//.//stdio
	cd stdio && $(MAKE) $@
	#mkdir -p ./obj-gcc//.//stdtime
	#cd stdtime && $(MAKE) $@
	mkdir -p ./obj-gcc//.//syscallARM
	cd syscallARM && $(MAKE) $@
	mkdir -p ./obj-gcc//.//syslib
	cd syslib && $(MAKE) $@
	mkdir -p ./obj-gcc//.//util
	cd util && $(MAKE) $@
	mkdir -p ./obj-gcc//.//sysutil
	cd sysutil && $(MAKE) $@
	mkdir -p ./obj-gcc//.//timers
	cd timers && $(MAKE) $@
	mkdir -p ./obj-gcc//.//ARM
	cd ARM && $(MAKE) $@
	mkdir -p ./obj-gcc//.//ack
	cd ack && $(MAKE) $@
	mkdir -p ./obj-gcc//.//gnu
	cd gnu && $(MAKE) $@

clean depend depend-ack depend-gnu:: makefiles
	cd ansi && $(MAKE) $@
	cd curses && $(MAKE) $@
	cd dummy && $(MAKE) $@
	cd editline && $(MAKE) $@
	cd endARM && $(MAKE) $@
	cd ip && $(MAKE) $@
	cd math && $(MAKE) $@
	cd other && $(MAKE) $@
	cd posix && $(MAKE) $@
	cd regex && $(MAKE) $@
	cd stdio && $(MAKE) $@
	cd stdtime && $(MAKE) $@
	cd syscallARM && $(MAKE) $@
	cd syslib && $(MAKE) $@
	cd util && $(MAKE) $@
	cd sysutil && $(MAKE) $@
	cd timers && $(MAKE) $@
	cd ARM && $(MAKE) $@
	cd ack && $(MAKE) $@
	cd gnu && $(MAKE) $@

makefiles: ansi/Makefile
makefiles: curses/Makefile
makefiles: dummy/Makefile
makefiles: editline/Makefile
makefiles: endARM/Makefile
makefiles: ip/Makefile
makefiles: math/Makefile
makefiles: other/Makefile
makefiles: posix/Makefile
makefiles: regex/Makefile
makefiles: stdio/Makefile
makefiles: stdtime/Makefile
makefiles: syscallARM/Makefile
makefiles: syslib/Makefile
makefiles: util/Makefile
makefiles: sysutil/Makefile
makefiles: timers/Makefile
makefiles: ARM/Makefile
makefiles: ack/Makefile
makefiles: gnu/Makefile

ansi/Makefile: ansi/Makefile.in
	cd ansi && sh .././generate.sh .//ansi .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles
curses/Makefile: curses/Makefile.in
	cd curses && sh .././generate.sh .//curses .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles
dummy/Makefile: dummy/Makefile.in
	cd dummy && sh .././generate.sh .//dummy .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles
editline/Makefile: editline/Makefile.in
	cd editline && sh .././generate.sh .//editline .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles
endARM/Makefile: endARM/Makefile.in
	cd endARM && sh .././generate.sh .//endARM .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles
ip/Makefile: ip/Makefile.in
	cd ip && sh .././generate.sh .//ip .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles
math/Makefile: math/Makefile.in
	cd math && sh .././generate.sh .//math .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles
other/Makefile: other/Makefile.in
	cd other && sh .././generate.sh .//other .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles
posix/Makefile: posix/Makefile.in
	cd posix && sh .././generate.sh .//posix .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles
regex/Makefile: regex/Makefile.in
	cd regex && sh .././generate.sh .//regex .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles
stdio/Makefile: stdio/Makefile.in
	cd stdio && sh .././generate.sh .//stdio .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles
stdtime/Makefile: stdtime/Makefile.in
	cd stdtime && sh .././generate.sh .//stdtime .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles
syscallARM/Makefile: syscallARM/Makefile.in
	cd syscallARM && sh .././generate.sh .//syscallARM .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles
syslib/Makefile: syslib/Makefile.in
	cd syslib && sh .././generate.sh .//syslib .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles
util/Makefile: util/Makefile.in
	cd util && sh .././generate.sh .//util .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles
sysutil/Makefile: sysutil/Makefile.in
	cd sysutil && sh .././generate.sh .//sysutil .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles
timers/Makefile: timers/Makefile.in
	cd timers && sh .././generate.sh .//timers .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles
ARM/Makefile: ARM/Makefile.in
	cd ARM && sh .././generate.sh .//ARM .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles
ack/Makefile: ack/Makefile.in
	cd ack && sh .././generate.sh .//ack .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles
gnu/Makefile: gnu/Makefile.in
	cd gnu && sh .././generate.sh .//gnu .././obj-ack/ .././obj-gcc/ && $(MAKE) makefiles

clean::
	rm -f ./obj-ack//.//*
	rm -f ./obj-gcc//.//*

include Makedepend-ack
include .depend-ack

include Makedepend-gnu
include .depend-gnu
