.code 32
.sect .text
.extern	_close
.global	close


close:
	b	_close
