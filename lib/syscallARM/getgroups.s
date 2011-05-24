.code 32
.sect .text
.extern	getgroups
.global	_getgroups


_getgroups:
	b	getgroups
