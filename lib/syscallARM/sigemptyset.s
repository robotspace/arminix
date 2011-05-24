.code 32
.sect .text
.extern	_sigemptyset
.global	sigemptyset


sigemptyset:
	b	_sigemptyset
