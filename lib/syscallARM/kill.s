.code 32
.sect .text
.extern	_kill
.global	kill


kill:
	b	_kill
