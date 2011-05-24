.code 32
.sect .text
.extern	_umask
.global	umask


umask:
	b	_umask
