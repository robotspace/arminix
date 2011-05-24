.code 32
.sect .text
.extern	execlp
.global	_execlp


_execlp:
	b	execlp
