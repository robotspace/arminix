@ sections

.sect .text
.code 32

.global	_read_tsc
.global	read_tsc

@*===========================================================================*
@ PUBLIC void read_tsc(unsigned long *high, unsigned long *low);
@ Read the cycle counter of the CPU. Pentium and up. 
read_tsc:
_read_tsc:
@	push edx
@	push eax
@.data1 0x0f		! this is the RDTSC instruction 
@.data1 0x31		! it places the TSC in EDX:EAX
@	push ebp
@	mov ebp, 16(esp)
@	mov (ebp), edx
@	mov ebp, 20(esp)
@	mov (ebp), eax
@	pop ebp
@	pop eax
@	pop edx
@	ret
.set	RTC_DATA, 0x80920000
ldr		r3, =RTC_DATA		@ check if IRQ came from VIC1 or VIC2
ldr		r3, [r3]	
ldr		r2,	=0
str		r3,	[r1]			@ store to low
str		r2,	[r0]			@ store to high
mov		pc, lr				@ return
