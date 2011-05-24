.code 32
.sect .text
.extern	ioctl
.global	_ioctl


_ioctl:
	b	ioctl
