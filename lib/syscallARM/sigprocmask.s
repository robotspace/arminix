.code 32
.sect .text
.extern	_sigprocmask
.global	sigprocmask


sigprocmask:
	b	_sigprocmask
