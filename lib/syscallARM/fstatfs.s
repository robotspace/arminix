.code 32
.sect .text
.extern	fstatfs
.global	_fstatfs


_fstatfs:
	b	fstatfs
