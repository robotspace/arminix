.code 32
.sect .text
.extern	_setuid
.extern _seteuid
.global	setuid
.global	seteuid


setuid:
	b	_setuid

seteuid:
	b	_seteuid
