.code 32
.sect .text
.extern	_sigdelset
.global	sigdelset


sigdelset:
	b	_sigdelset
