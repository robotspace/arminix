.code 32
.sect .text
.extern	getcwd
.global	_getcwd


_getcwd:
	b	getcwd
