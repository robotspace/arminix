.code 32
.sect .text
.extern	_fcntl
.global	fcntl


fcntl:
	b	_fcntl
