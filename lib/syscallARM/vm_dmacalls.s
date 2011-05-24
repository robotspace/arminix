.code 32
.sect .text
.extern	_vm_adddma
.global	vm_adddma
.extern	_vm_deldma
.global	vm_deldma
.extern	_vm_getdma
.global	vm_getdma


vm_adddma:
	b	_vm_adddma
vm_deldma:
	b	_vm_deldma
vm_getdma:
	b	_vm_getdma

