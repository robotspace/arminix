# =============================================================================
#
# C-runtime 0 for the kernel
#
# This code :
# - initializes the exception vectors
# - initializes the stacks
# - initializes values from FLASH to RAM
# - Set the unitiated values (the .BBS block ) in RAM to NULL
# - branch to Cstart
# - branch to main
# 
# Written for the ARM-Minix project by Léon Melis 08-2009 
#
# =============================================================================

.section .text
.code 32

# value's defined in linkerscript
#.extern bss_start
#.extern bss_end

# Operating mode bits
.set	MODE_FIQ,	0x11
.set	MODE_IRQ,	0x12
.set	MODE_SVC,	0x13
.set	MODE_ABT,	0x17
.set	MODE_UND,	0x1B
.set	MODE_SYS,	0x1F
.set	MODE_USER,	0x10

# other identifiers
.set	IRQ_FLAG, 	0x80		@ Flag for IRQ disable
.set	FIQ_FLAG, 	0x40		@ Flag for FIQ disable


# =============================================================================
#	start
# =============================================================================

.global _start
.global _boot
_start:
_boot:
	ldr		pc, map_reset
	ldr		pc, map_undef
	ldr		pc, map_swi 
	ldr		pc, map_pabt
	ldr		pc, map_dabt
	nop							@ legacy, should be a nop
	ldr		pc, map_irq
	ldr		pc, map_fiq

map_reset:	.word	reset_handler
map_undef:	.word	fail_undef
map_swi:	.word	SWI_handler
map_pabt:	.word	fail_pabt
map_dabt:	.word	fail_dabt
map_nop:	.word	0			@ keep this, to align to 64 bytes
map_irq:	.word	IRQ_handler
map_fiq:	.word	FIQ_handler

# =============================================================================
# Copy first 40 bytes to address 0x0 (the reset vector)
# by doing this, exception always work, independend of where the code starts 
# =============================================================================

reset_handler:
	ldr		r1, =_boot			@ Determine start location of code
	cmp		r1, #0x00			@ if 0, no need to copy the code
	beq		StackSetup			@ skip to next section
	mov		r2, #0x00			@ First memory address
	mov		r3, #0x40			@ End of vector initialisation
copy_boot:
	cmp		r2, r3
	ldrlo	r0, [r1], #4
	strlo	r0, [r2], #4
	blo		copy_boot


# =============================================================================
# Setup stack for each mode. Interrupts disabled in all modes
# =============================================================================

StackSetup:
	ldr		r0, =stack_end
	msr		cpsr_c, #MODE_UND | IRQ_FLAG | FIQ_FLAG 	@ Undefined
	mov		sp, r0
	ldr		r1, =undef_stack
	sub		r0, r0, r1

	msr		cpsr_c, #MODE_ABT | IRQ_FLAG | FIQ_FLAG 	@ Abort 
	mov		sp, r0
	ldr		r1, =abort_stack
	sub		r0, r0, r1

	msr		cpsr_c, #MODE_FIQ | IRQ_FLAG | FIQ_FLAG 	@ FIQ 
	mov		sp, r0	
	ldr		r1, =fiq_stack
	sub		r0, r0, r1

	msr		cpsr_c, #MODE_IRQ | IRQ_FLAG | FIQ_FLAG 	@ IRQ 
	mov		sp, r0
	ldr		r1, =irq_stack
	sub		r0, r0, r1

	msr		cpsr_c, #MODE_SVC | IRQ_FLAG | FIQ_FLAG		@ Supervisor 
	mov		sp, r0
	ldr		r1, =svc_stack
	sub		r0, r0, r1

	msr		cpsr_c, #MODE_SYS | IRQ_FLAG | FIQ_FLAG 	@ System Mode 
	mov		sp, r0

# =============================================================================
# Copy .data section from FLASH to RAM, if necessary
# =============================================================================

	ldr		r1, =etext			@ determine end of .text from linkerscript
	ldr		r2, =data			@ determine start of .data from linkerscript
	ldr		r3, =edata			@ determine end of .data from linkerscript
	subs	r3, r3, r2			@ Determine length of data section
	beq		.end_set_loop		@ If zero, there is nothing to do here
	subs	r0, r2, r1			@ Determine offset between text and data
	beq		.end_set_loop		@ If zero, all code is obviously in RAM
								@ then there is nothing to do here
.set_loop:
	ldrb	r4, [r2], #1		@ Read byte from flash, and increase FLASH ptr
	strb	r4, [r1], #1		@ Store byte to RAM, and increase RAM pointer
	subs	r3, r3, #1			@ Decrease number of bytes to copy by one
	bgt		.set_loop			@ Repeat until we are done
.end_set_loop:

# =============================================================================
# According to the C standard, the .bss (Block Started by Symbol) section 
# should be NULL upon reset, so let's do that:
# =============================================================================

	ldr		r1, =bss_start		@ determine bss_start from linkerscript
	ldr		r3, =bss_end		@ determine bss_end from linkerscript
	subs	r3, r3, r1			@ determine length of BSS
	beq		.end_clear_loop		@ If zero, there are no uninitialised value's
	mov		r2, #0				@ Fill everything with.... zero!
.clear_loop:
	strb	r2, [r1], #1		@ set byte to 0, and move on to the next byte
	subs	r3, r3, #1			@ decrease remaining .bss length by one
	bgt		.clear_loop			@ if zero, we are done!
.end_clear_loop:

# =============================================================================
# this stage of the low level init of the CPU is done now run cstart
# =============================================================================

	ldr		r0,=_boot			@ kernel code segment
	ldr		r1,=data			@ kernel data segment
	mov		r2,#0				@ monitor data segment
	mov		r3,#0				@ data offset of boot params
	mov 	r4,#0				@ lengt of boot params
	bl		cstart
	
# =============================================================================
# because restart() is called from main, we MUST be in supervisor mode to make
# the first task switch work
# =============================================================================

	msr		cpsr_c,#MODE_SVC | IRQ_FLAG | FIQ_FLAG		

# =============================================================================
# and finaly, go to main, don't set return address
# =============================================================================

	b 		main
