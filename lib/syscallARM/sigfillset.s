.code 32
.sect .text
.extern	_sigfillset
.global	sigfillset


sigfillset:
	b	_sigfillset
