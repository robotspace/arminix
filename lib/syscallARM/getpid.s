.code 32
.sect .text
.extern	_getpid
.global	getpid


getpid:
	b	_getpid
