.code 32
.sect .text
.extern	_getnprocnr
.global getnprocnr


getnprocnr:
	b	_getnprocnr
