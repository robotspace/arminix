.code 32
.sect .text
.extern	_sigsuspend
.global	sigsuspend


sigsuspend:
	b	_sigsuspend
