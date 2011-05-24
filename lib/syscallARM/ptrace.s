.code 32
.sect .text
.extern	ptrace
.global	_ptrace


_ptrace:
	b	ptrace
