.code 32
.sect .text
.extern	lseek64
.global	_lseek64


_lseek64:
	b	lseek64
