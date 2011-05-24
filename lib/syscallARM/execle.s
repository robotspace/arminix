.code 32
.sect .text
.extern	_execle
.global	execle


execle:
	b	_execle
