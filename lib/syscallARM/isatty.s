.code 32
.sect .text
.extern	isatty
.global	_isatty


_isatty:
	b	isatty
