.code 32
.sect .text
.extern	_time
.global	time


time:
	b	_time
