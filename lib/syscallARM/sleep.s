.code 32
.sect .text
.extern	_sleep
.global	sleep


sleep:
	b	_sleep
