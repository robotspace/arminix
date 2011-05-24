.code 32
.sect .text
.extern	_setsid
.global	setsid


setsid:
	b	_setsid
