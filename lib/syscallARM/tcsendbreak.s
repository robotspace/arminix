.code 32
.sect .text
.extern	tcsendbreak
.global	_tcsendbreak


_tcsendbreak:
	b	tcsendbreak
