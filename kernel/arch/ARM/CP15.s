@ =========================================================================== 
@ coprocessor.s
@
@ This file houses all the functions needed to read or write the control
@ registers of the CP15 co-processor, found in the ARM920T.
@
@ This file prevents the use of in line assembly ("ast proof")
@
@ =========================================================================== 

.section .text
.code 32

@ =========================================================================== 
@ 				read_cp15
@ =========================================================================== 
@ PUBLIC u_32 read_cp15(u_32 reg, u_32 operant2);
@ Read CoProcessor register
.global read_cp15
read_cp15:
	cmp		r0, #15				@ check if register is within range
	addlo	pc, pc, r0, LSL #2	@ the magical lookup table
	b		read_fault
	b		read_cr0
	b		read_cr1
	b		read_cr2
	b		read_cr3
	b		read_fault			@ CP15 register 4 should not be read or written
	b		read_cr5
	b		read_cr6
	b		read_fault			@ CP15 register 7 should not be read
	b		read_fault			@ CP15 register 8 should not be read
	b		read_cr9			
	b		read_cr10			
	b		read_fault			@ CP15 register 11 should not be read or written
	b		read_fault			@ CP15 register 12 should not be read or written
	b		read_cr13
	b		read_fault			@ CP15 register 14 should not be read or written
	b		read_cr15
	mov		pc, lr				@ return

read_cr0:
	cmp		r1,#0				@ Register CR0 has an operant
	mrceq 	P15,0,r0,cr0,cr0,0
	mrcne 	P15,0,r0,cr0,cr0,1
	mov		pc, lr				@ return
read_cr1:
	mrc 	P15,0,r0,cr1,cr0
	mov		pc, lr				@ return
read_cr2:
	mrc		P15,0,r0,cr2,cr0
	mov		pc, lr				@ return
read_cr3:
	mrc 	P15,0,r0,cr3,cr0
	mov		pc, lr				@ return
read_cr5:
	cmp		r1,#0				@ Register CR5 has an operant
	mrceq 	P15,0,r0,cr5,cr0,0
	mrcne 	P15,0,r0,cr5,cr0,1
	mov		pc, lr				@ return
read_cr6:
	mrc		P15,0,r0,cr6,cr0
	mov		pc, lr				@ return
read_cr9:
	cmp		r1,#0				@ Register CR9 has an operant
	mrceq 	P15,0,r0,cr9,cr0,0
	mrcne 	P15,0,r0,cr9,cr0,1
	mov		pc, lr				@ return
read_cr10:
	cmp		r1,#0				@ Register CR10 has an operant
	mrceq 	P15,0,r0,cr10,cr0,0
	mrcne 	P15,0,r0,cr10,cr0,1
	mov		pc, lr				@ return
read_cr13:
	mrc 	P15,0,r0,cr13,cr0
	mov		pc, lr				@ return
read_cr15:
	mrc 	P15,0,r0,cr15,cr0
	mov		pc, lr				@ return
read_fault:
	mov		r0, #-1			
	mov		pc, lr				@ return error


@ =========================================================================== 
@ 				write_cp15	      
@ =========================================================================== 
@ PUBLIC void write_cp15(u_32 reg, u32 operant2, u_32 value);
@ Write CoProcessor register, CR7 and CR8 should have own function!
.global write_cp15
write_cp15:
	cmp		r0, #15				@ check if register is within range
	cmp		r0, #15				@ check if register is within range
	addlo	pc, pc, r0, LSL #2	@ the magical lookup table
	b		read_fault
	b		exit				@ CR0 should not be written
	b		write_cr1
	b		write_cr2
	b		write_cr3
	b		exit				@ CR4 should not be written
	b		write_cr5
	b		write_cr6
	b		exit				@ CR7 has complex features, an should have own function
	b		exit				@ CR8 has complex features, an should have own function
	b		write_cr9			@ CR9 has an operant 2, so deal with it seperatly
	b		write_cr10			@ CR10 has an operant 2, so deal with it seperatly	
	b		exit
	b		exit
	MCR 	P15,0,r2,cr13,cr0
	b		exit
	MCR 	P15,0,r2,cr15,cr0
exit:
	mov		pc, lr				@ return

write_cr1:
	mcr 	P15,0,r2,cr1,cr0	
	mov		pc, lr				@ return
write_cr2:
	mcr 	P15,0,r2,cr2,cr0	
	mov		pc, lr				@ return
write_cr3:
	mcr 	P15,0,r2,cr3,cr0	
	mov		pc, lr				@ return
write_cr5:
	cmp		r1,#0				@ determine operant
	mcreq 	P15,0,r2,cr5,cr0,0
	mcrne 	P15,0,r2,cr5,cr0,1
	mov		pc, lr				@ return
write_cr6:
	mcr 	P15,0,r2,cr6,cr0	
	mov		pc, lr				@ return
write_cr9:
	cmp		r1,#0				@ determine operant
	mcreq 	P15,0,r2,cr9,cr0,0
	mcrne 	P15,0,r2,cr9,cr0,1
	mov		pc, lr				@ return
write_cr10:
	cmp		r1,#0				@ determine operant
	mcreq 	P15,0,r2,cr10,cr0,0
	mcrne 	P15,0,r2,cr10,cr0,1
	mov		pc, lr				@ return
write_cr13:
	mcr 	P15,0,r2,cr13,cr0	
	mov		pc, lr				@ return
write_cr15:
	mcr 	P15,0,r2,cr15,cr0	
	mov		pc, lr				@ return
	

@ =========================================================================== 
@ 				inval_all_tlbs	      
@ =========================================================================== 
@ PUBLIC void inval_all_tlbs(void);
@ invalidate all TLB's (Data and Instruciton TLB's)
.global inval_all_tlbs
inval_all_tlbs:
	mov		r0,#0
	mcr		P15, 0, r0, cr8, cr7, 0
	mov		pc, lr

@ =========================================================================== 
@ 				inval_d_tlbs	      
@ =========================================================================== 
@ PUBLIC void inval_d_tlbs(void);
@ invalidate all DATA TLB's
.global inval_d_tlbs
inval_d_tlbs:
	mov		r0,#0
	mcr		P15, 0, r0, cr8, cr6, 0
	mov		pc, lr

@ =========================================================================== 
@ 				inval_i_tlbs	      
@ =========================================================================== 
@ PUBLIC void inval_i_tlbs(void);
@ invalidate all INSTRUCTION TLB's
.global inval_i_tlbs
inval_i_tlbs:
	mov		r0,#0
	mcr		P15, 0, r0, cr8, cr5, 0
	mov		pc, lr

@ =========================================================================== 
@ 				inval_single_i_tlb      
@ =========================================================================== 
@ PUBLIC void inval_single_i_tlb(u_32 MVA);
@ invalidate single INSTRUCTION TLB selected by MVA (modified virtual address)
.global inval_single_i_tlb
inval_single_i_tlb:
	mcr		P15, 0, r0, cr8, cr5, 1
	mov		pc, lr

@ =========================================================================== 
@ 				inval_single_d_tlb      
@ =========================================================================== 
@ PUBLIC void inval_single_d_tlb(u_32 MVA);
@ invalidate single DATA TLB selected by MVA (modified virtual address)
.global inval_single_d_tlb
inval_single_d_tlb:
	mcr		P15, 0, r0, cr8, cr6, 1
	mov		pc, lr
