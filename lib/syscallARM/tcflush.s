.code 32
.sect .text
.extern	tcflush
.global	_tcflush


_tcflush:
	b	tcflush
