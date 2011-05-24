.code 32
.sect .text
.extern	sync
.global	_sync


_sync:
	b	sync
