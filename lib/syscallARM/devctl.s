.code 32
.sect .text
.extern	devctl
.global	_devctl


_devctl:
	b	devctl
