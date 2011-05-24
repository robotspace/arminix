.code 32
.sect .text
.extern	_sigaddset
.global	sigaddset


sigaddset:
	b	_sigaddset
	