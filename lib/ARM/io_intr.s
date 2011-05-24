#==============================================================================
#
# enable and disable interrupts
# written by Léon Melis for the Minix3 ARM port oct 2009
#
#==============================================================================

.code 32
.sect .text

.global intr_disable
intr_disable:
	mrs		r0, CPSR
	orr		r0, r0, #0xC0	@ disable IRQ/FIQ interrupts
	msr		CPSR_c, r0
	mov		pc, lr 

.global intr_enable
intr_enable:
	mrs		r0, CPSR
	bic		r0, r0, #0x80	@ enable IRQ interrupts
	msr		CPSR_c, r0
	mov		pc, lr
