.code 32
.sect .text
.extern	_getgid
.global	getgid


getgid:
	b	_getgid
