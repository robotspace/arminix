.code 32
.sect .text
.extern	_sbrk
.global	sbrk


sbrk:
	b	_sbrk
