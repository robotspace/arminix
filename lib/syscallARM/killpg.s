.code 32
.sect .text
.extern	killpg
.global	_killpg


_killpg:
	b	killpg
