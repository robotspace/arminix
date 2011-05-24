.code 32
.sect .text
.extern	execvp
.global	_execvp


_execvp:
	b	execvp
