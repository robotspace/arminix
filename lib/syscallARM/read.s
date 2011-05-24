.code 32
.sect .text
.extern	_read
.global	read


read:
	b	_read
