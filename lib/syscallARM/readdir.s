.code 32
.sect .text
.extern	readdir
.global	_readdir


_readdir:
	b	readdir
