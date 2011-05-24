.code 32
.sect .text
.extern	umount
.global	_umount


_umount:
	b	umount
