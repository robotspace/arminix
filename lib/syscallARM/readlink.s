.code 32
.sect .text
.extern	readlink
.global	_readlink


_readlink:
	b	readlink
