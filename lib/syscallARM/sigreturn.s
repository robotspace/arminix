.code 32
.sect .text
.extern	_sigreturn
.global	sigreturn
.global __sigreturn

__sigreturn:
sigreturn:
	b	_sigreturn
