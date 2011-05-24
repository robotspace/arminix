.code 32
.sect .text
.extern	setgid
.global	_setgid
.global	_setegid


_setgid:
	b	setgid

_setegid:
	b	setegid
