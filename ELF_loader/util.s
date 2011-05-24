.code 32

#int mem_cmp(int *address, int *value, int count)
.global mem_cmp
mem_cmp:
	push	{r3,r4}
	cmp		r2,#0
	beq		cmp_end
	sub		r2,r2,#1
	ldrb	r3, [r0],#1
	ldrb	r4,	[r1],#1
	cmp		r3,r4
	beq		mem_cmp
cmp_error:
	pop		{r3,r4}
	mov		r0,#-1
	mov		pc,lr
cmp_end:
	pop		{r3,r4}
	mov		r0,#0
	mov		pc,lr
	
# int mem_cpy(unsigned int source, unsigned int dest, unsigned int len);
.global mem_cpy
mem_cpy:
	cmp		r2,#0
	beq		mem_cpy_end
	sub		r2,r2,#1
	ldrb	r3, [r0],#1		@ source
	strb	r3,	[r1],#1		@ dest
	b		mem_cpy
mem_cpy_end:
	mov		r0,#0
	mov		pc,lr

.global runprog
runprog:
	mov		pc,r0
