.code 32
.sect .text
.extern	sysuname
.global	_sysuname


_sysuname:
	b	sysuname
