.code 32
.sect .text
.extern	brk
.global	_brk


_brk:
	b	brk
