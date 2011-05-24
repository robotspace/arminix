.code 32
.sect .text
.extern	_getsysinfo
.global	getsysinfo
.extern	_getsysinfo_up
.global	getsysinfo_up


getsysinfo:
	b	_getsysinfo
getsysinfo_up:
	b	_getsysinfo_up
