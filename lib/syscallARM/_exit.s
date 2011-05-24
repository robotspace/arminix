.code 32
.sect .text
.extern	__exit
.global	_exit


_exit:
	b	__exit
