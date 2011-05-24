.code 32
.sect .text
.extern	mkfifo
.global	_mkfifo


_mkfifo:
	b	mkfifo
