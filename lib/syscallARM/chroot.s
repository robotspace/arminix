.code 32
.sect .text
.extern	chroot
.global	_chroot


_chroot:
	b	chroot
