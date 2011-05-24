.code 32
.sect .text
.extern	_mmap
.global	mmap


mmap:
	b	_mmap
