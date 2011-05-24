.code 32
.sect .text
.extern	_lseek
.global	lseek


lseek:
	b	_lseek
