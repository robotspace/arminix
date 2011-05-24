.code 32
.sect .text
.extern	getnpid
.global	_getnpid


_getnpid:
	b	getnpid
