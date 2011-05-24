.code 32
.sect .text
.extern	_pause
.global	pause


pause:
	b	_pause
