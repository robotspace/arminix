.code 32
.sect .text
.extern	_getuid
.global	getuid


getuid:
	b	_getuid
