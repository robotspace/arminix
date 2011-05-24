.code 32
.sect .text
.extern	opendir
.global	_opendir


_opendir:
	b	opendir
