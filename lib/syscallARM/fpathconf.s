.code 32
.sect .text
.extern	fpathconf
.global	_fpathconf


_fpathconf:
	b	fpathconf
