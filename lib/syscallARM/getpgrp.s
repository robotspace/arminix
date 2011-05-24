.code 32
.sect .text
.extern	getpgrp
.global	_getpgrp


_getpgrp:
	b	getpgrp
