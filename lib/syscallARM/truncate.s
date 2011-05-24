.code 32
.sect .text
.extern	truncate
.extern	ftruncate
.global	_truncate
.global	_ftruncate


_truncate:
	b	truncate


_ftruncate:
	b	ftruncate
