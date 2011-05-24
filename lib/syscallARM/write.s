.code 32
.sect .text
.extern	_write
.global	write


write:
	b	_write
