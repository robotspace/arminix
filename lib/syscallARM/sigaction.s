.code 32
.sect .text
.extern	_sigaction
.global	sigaction


sigaction:
	b	_sigaction
