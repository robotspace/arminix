.code 32
.sect .text
.extern	getdents
.global	_getdents


_getdents:
	b	getdents
