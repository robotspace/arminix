.code 32
.global _exit
.global __exit
.global ___exit
.extern intr_enable
_exit:
__exit:
___exit:
	bl	intr_enable				@ make sure the CPU can escape from this infinite loop
	b	___exit					@ and do the loop
