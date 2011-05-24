.code 32
.sect .text
.extern	geteuid
.global	_geteuid


_geteuid:
	b	geteuid
