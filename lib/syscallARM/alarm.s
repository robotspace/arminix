.code 32
.sect .text
.extern	_alarm
.global	alarm


alarm:
	b	_alarm
