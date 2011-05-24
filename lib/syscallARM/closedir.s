.code 32
.sect .text
.extern	closedir
.global	_closedir


_closedir:
	b	closedir
