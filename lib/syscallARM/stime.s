.code 32
.sect .text
.extern	stime
.global	_stime


_stime:
	b	stime
