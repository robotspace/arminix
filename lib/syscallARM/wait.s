.code 32
.sect .text
.extern	_wait
.global	wait


wait:
	b	_wait
