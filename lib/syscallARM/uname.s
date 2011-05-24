.code 32
.sect .text
.extern	uname
.global	_uname


_uname:
	b	uname
