.code 32
.sect .text
.extern	rewinddir
.global	_rewinddir


_rewinddir:
	b	rewinddir
