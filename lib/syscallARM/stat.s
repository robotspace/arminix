.code 32
.sect .text
.extern	_stat
.global	stat


stat:
	b	_stat
