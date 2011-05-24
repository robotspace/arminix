.code 32
.sect .text
.extern	chdir
.global	_chdir
.extern	fchdir
.global	_fchdir


_chdir:
	b	chdir
_fchdir:
	b	fchdir
