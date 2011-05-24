.code 32
.sect .text
.extern	execv
.global	_execv


_execv:
	b	execv
