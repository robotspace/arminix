.code 32
.sect .text
.extern	_reboot
.global	reboot


reboot:
	b	_reboot
