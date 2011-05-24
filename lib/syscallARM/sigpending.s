.code 32
.sect .text
.extern	sigpending
.global	_sigpending


_sigpending:
	b	sigpending
