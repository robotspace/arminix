.code 32
.sect .text
.extern	_execve
.global	execve


execve:
	b	_execve
