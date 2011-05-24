.code 32
.sect .text
.extern	getppid
.global	_getppid


_getppid:
	b	getppid
