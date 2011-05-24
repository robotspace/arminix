.code 32
.sect .text
.extern	_svrctl
.global	svrctl


svrctl:
	b	_svrctl
