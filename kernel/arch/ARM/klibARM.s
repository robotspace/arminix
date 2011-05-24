# =============================================================================
#
# This file contains all functions that are written in ASM, to prevent the 
# use of inline ASM
# by: Léon Melis for the ARM-Minix project 06-2009
#
# Some functions could have easely been written in C, but to keep the location
# of various functions somewhat like the origional Minix3 source code, they 
# are still here, in ASM.
#
# =============================================================================

#include <minix/config.h>

.section .text
.code 32

# VIC adresses
.set	VIC1IRQStatus,	0x800B0000
.set	VIC2IRQStatus,	0x800C0000
.set	VIC1VectAddr, 	0x800B0030
.set	VIC2VectAddr, 	0x800C0030

# =============================================================================
# PL190 interrupt handler with support for daisy chained VIC
# saves interrupted process's registers to stackframe
# =============================================================================

.global IRQ_handler
IRQ_handler:
	sub		lr,lr,#4			@ modify return address because of interrupt
	stmfd	sp!,{r0-r3}			@ save everything we are likely to overwrite
	ldr		r0, =proc_ptr	
	ldr		r0,[r0]
	mrs		r1, spsr			@ store spsr to stackframe
	str		r1,[r0],#4
	ldmfd	sp!,{r2,r3}			@ reload stored r0 and r1 to r2 and r3
	stmea	r0!,{r2,r3}			@ store original r0 and r1 to stackframe
	ldmfd	sp!,{r2,r3}			@ reload stored r2 and r3
	str		lr,[r0, #52]		@ store address of interrupted instruction to
								@ PC field in stackframe
	stmea	r0,{r2-R14}^		@ store user R2-R14 in stackframe

	ldr		r0, =VIC1IRQStatus	@ check if IRQ came from VIC1 or VIC2
	ldr		r0, [r0]
	cmp		r0, #0
	beq		VIC2Handler

VIC1Handler:
	ldr		r0, =VIC1VectAddr	@ lookup appropriate ISR for IRQ source
	ldr		r0, [r0]
	mov		lr, pc				@ set return address 
	mov		pc, r0				@ call ISR
	ldr		r12, =VIC1VectAddr	@ VectorAddr pointer
	str		r0, [r12] 			@ Not important what r0 contains 
	b		IRQ_exit
	
VIC2Handler:
	ldr		r0, =VIC2VectAddr	@ lookup appropriate ISR for IRQ source
	ldr		r0, [r0]
	mov		lr, pc				@ set return address 
	mov		pc, r0				@ call ISR
	ldr		r12, =VIC2VectAddr  @ VectorAddr pointer
	str		r0, [r12] 			@ Not important what r0 contains 

IRQ_exit:	
	ldr 	r0, =k_reenter
	ldr		r1,[r0]
	add		r1,#1
	str		r1,[r0]				@ from -1 if not reentering
	cmp		r1,#0
	bne		restart1			@ stack is already kernel stack
	b		restart

	
# =============================================================================
#			reset
# =============================================================================
# FIXME: add reset intruction using the system controll register
.global _reset
_reset:
	b 	reset

	
# =============================================================================
# 				exit					      
# =============================================================================
# PUBLIC void exit();
# Some library routines use exit, so provide a dummy version.
# Actual calls to exit cannot occur in the kernel.
# GNU CC likes to call ___main from main() for nonobvious reasons.
.global _exit
.global __exit
.global ___exit

exit:
_exit:
__exit:
___exit:
	bl	intr_enable			@ make sure the CPU can escape from infinite loop
	b	___exit				@ and do the loop

___main:
	mov	pc, lr				@ return

	
# =============================================================================
# 				phys_outsw				      
# =============================================================================
# PUBLIC void phys_outsw(Port_t port, phys_bytes buf, size_t count);
# Output an array from an I/O port.  Absolute address version of outsw().

.global phys_outsw	
phys_outsw:
	push 	{r3} 				@ stack R3
	cmp		r2, #0
	beq		phys_outsw_end
	ldr		r3, [r1], #4
	str		r3, [r0], #4
	sub		r2, #1
	b		phys_outsw
phys_outsw_end:
	pop		{r3} 				@ unstack R3
	mov		pc, lr


# =============================================================================
# 				phys_outsb				      
# =============================================================================
# PUBLIC void phys_outsb(Port_t port, phys_bytes buf, size_t count);
# Output an array to an I/O port.  Absolute address version of outsb().

.global phys_outsb
phys_outsb:
	push 	{r3} 				@ stack R3
	cmp		r2, #0
	beq		phys_outsb_end
	ldrb	r3, [r1], #4		@ load byte, auto increment pointer
	strb	r3, [r0], #4		@ store byte, auto increment pointer
	sub		r2, #1
	b		phys_outsb
phys_outsb_end:
	pop 	{r3} 				@ unstack R3
	mov		pc, lr


# =============================================================================
# 				phys_insw				      
# =============================================================================
# PUBLIC void phys_insw(Port_t port, phys_bytes buf, size_t count);
# Input an array from an I/O port.  Absolute address version of insw().

.global phys_insw	
phys_insw:
	push 	{r3} 				@ stack R3
	cmp		r2, #0
	beq		phys_insw_end
	ldr		r3, [r0], #4		@ load word, auto increment pointer
	str		r3, [r1], #4		@ store word, auto increment pointer
	sub		r2, #1
	b			phys_insw
phys_insw_end:
	pop		{r3} 				@ unstack R3
	mov		pc, lr


# =============================================================================
# 				phys_insb				      
# =============================================================================
# PUBLIC void phys_insb(Port_t port, phys_bytes buf, size_t count);
# Input an array to an I/O port.  Absolute address version of insb().

.global phys_insb
phys_insb:
	push 	{r3} 				@ stack R3
	cmp		r2, #0
	beq		phys_insb_end
	ldrb	r3, [r0], #4		@ load byte, auto increment pointer
	strb	r3, [r1], #4		@ store byte, auto increment pointer
	sub		r2, #1
	b		phys_insb
phys_insb_end:
	pop		{r3} 				@ unstack R3
	mov		pc, lr


# =============================================================================
# 				phys_copy				      
# =============================================================================
# PUBLIC void phys_copy(phys_bytes source, phys_bytes destination,
#			phys_bytes bytecount);
# Copy a block of physical memory.

.global phys_copy
phys_copy:
	push 	{r3} 				@ stack R3
	cmp		r2, #0
	beq		phys_copy_end
	ldr		r3, [r0], #4		@ load word, auto increment pointer
	str		r3, [r1], #4		@ store word, auto increment pointer
	sub		r2, #1
	b		phys_copy
phys_copy_end:
	pop		{r3} 				@ unstack R3
	mov		pc, lr


# =============================================================================
# 				phys_memset				      
# =============================================================================
# PUBLIC void phys_memset(phys_bytes source, unsigned long pattern,
#	phys_bytes bytecount);
# Fill a block of physical memory with pattern.

.global phys_memset
phys_memset:
	cmp		r2, #0
	moveq	pc, lr					@ return if nothing else to do
	str		r1, [r0], #4			@ store pattern, auto increment pointer
	sub		r2, #1
	b		phys_memset


# =============================================================================
# 				idle_task				      
# =============================================================================
# Normally this task should be run in power safing mode.
# For now, it's just a very inefficient while(1)
.global idle_task
idle_task:
	b		idle_task

# =============================================================================
# 				read_cpu_flags				      
# =============================================================================
.global read_cpu_flags
read_cpu_flags:
	mrs		r0, cpsr
	mov		pc,lr

# =============================================================================
# 				SWI handler (_s_call in origional minix code)
# =============================================================================

.global SWI_handler
SWI_handler:
# first, increase k_reenter
	stmfd	sp!,{r0-r1}	
	ldr 	r0, =k_reenter
	ldr		r1,[r0]
	add		r1,#1
	str		r1,[r0]					@ k_reenter increased by one
	ldmfd	sp!,{r0-r1}
# the sys call is done before saving process stage, so that the results of 
# sys_call are stored in the stackframe.
	stmfd	sp!,{r12, r14}			@ stack LR & SP, so we can branch
	bl		sys_call				@ arguments should still be in place
# now we can safe all the process's registers
	stmfd	sp!,{r0-r3}
	ldr		r0, =proc_ptr
	ldr		r0,[r0]
	mrs		r1, spsr				@ load spsr
	str		r1,[r0],#4				@ save to stackframe, point to next field
	ldmfd	sp!,{r2,r3}				@ reload stored r0 and r1 to r2 and r3
	stmea	r0!,{r2,r3}				@ store origional r0 and r1 to stackframe
	ldmfd	sp!,{r2,r3,r12,r14}
	str		R14,[r0, #52]			@ store address of interrupted instruction 
									@ to PC field in stackframe
	stmea	r0,{r2-R14}^			@ store user R2-R14 in stackframe
# after this, fall into restart

# =============================================================================
# 				restart
# =============================================================================

.global restart
restart:
# Restart the current process or the next process if it is set. 
	ldr		r0, =next_ptr
	ldr		r2, [r0]				@ r2 now contains address of next_ptr
	cmp		r2, #0					@ see if another process is scheduled
	beq		restart1				@ if not, do not reschedule
	ldr		r1, =proc_ptr
	str		r2,[r1]					@ schedule new process
	mov		r3,#0
	str		r3,[r0]					@ next_ptr = 0
restart1:
# first, decrease k_reenter
	ldr 	r0, =k_reenter
	ldr		r1,[r0]
	sub		r1,#1
	str		r1,[r0]					@ k_reenter decreased by one
# second, restore registers en return to task
	ldr		r0,=proc_ptr			@ find stackframe
	ldr		r0,[r0]
	ldr		r12,[r0],#4				@ load task PSR and point to next field
	msr		spsr_fsxc, r12			@ to spsr_IRQ, so don't use it right away
	ldr		r14,[r0, #60]			@ load PC value (return register)
	ldmfd	r0,{r0-r14}^			@ load user mode registers from stackframe
	nop								@ cannot use banked register immediately 
									@ after user mode LDM
	movs	pc,r14					@ run new task, with SPSR->CPSR transfer
