.code 32
.sect .text
.extern	_sigismember
.global	sigismember


sigismember:
	b	_sigismember
