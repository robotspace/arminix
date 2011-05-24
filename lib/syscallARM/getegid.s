.code 32
.sect .text
.extern	getegid
.global	_getegid


_getegid:
	b	getegid
