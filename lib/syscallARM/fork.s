.code 32
.sect .text
.extern	_fork
.global	fork


fork:
	b	_fork
