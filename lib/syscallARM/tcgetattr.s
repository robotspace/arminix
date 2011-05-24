.code 32
.sect .text
.extern	tcgetattr
.global	_tcgetattr


_tcgetattr:
	b	tcgetattr
