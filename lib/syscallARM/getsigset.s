.code 32
.sect .text
.extern	_getsigset
.global	getsigset


getsigset:
	b	_getsigset
