.code 32
.sect .text
.extern	pathconf
.global	_pathconf


_pathconf:
	b	pathconf
