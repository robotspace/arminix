.code 32
.sect .text
.extern	_mknod
.global	mknod


mknod:
	b	_mknod
