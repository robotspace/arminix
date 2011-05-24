.code 32
.sect .text
.extern	cprofile
.global	_cprofile


_cprofile:
	b	cprofile
