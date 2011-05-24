.code 32
.sect .text
.extern	_waitpid
.global	waitpid


waitpid:
	b	_waitpid
