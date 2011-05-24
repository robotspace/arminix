.code 32
.sect .text
.extern	_getprocnr
.global	getprocnr


getprocnr:
	b	_getprocnr
