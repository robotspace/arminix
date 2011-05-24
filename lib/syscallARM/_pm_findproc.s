.code 32
.sect .text
.extern	__pm_findproc
.global	_pm_findproc


_pm_findproc:
	b	__pm_findproc
