.code 32
.sect .text
.extern	getpprocnr
.global	_getpprocnr


_getpprocnr:
	b	getpprocnr
