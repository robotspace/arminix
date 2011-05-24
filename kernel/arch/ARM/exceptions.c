/* 
* This file houses all the exception handlers, for the ARM7/9 core
* Written by: Léon Melis 12/08/09
* For the Minix-ARM project
*/

#include "exceptions.h"
#include <EP93xx.h>
#include <minix/com.h>

extern void kprintf(const char *fmt, ...);
extern int read_cp15(int reg, int operant2);

/* exception handler for undifined instructions */ 
void fail_undef(void)           
{
	register unsigned * link_ptr asm("lr");
	kprintf("\nERROR: CPU encountered an unknown instruction at 0x%x\n",link_ptr);
	asm("MOVS pc,r14");		/* return and restore CPSR */
}

/* exception handler for prefetch abort 
* prefetch fault can be found in R14 */
void fail_pabt(void)
{
	register unsigned * link_ptr asm("lr");
	kprintf("\nERROR: Software caused prefetch abort at 0x%x\n",link_ptr);
	asm("SUBS PC,R14,#4");		/* return 1 instruction before P-ABT occured, to re-execute instruction in pipeline */
}

/* exception handler for data abort 
* Data abort FSR (Fault Status register) and FAR (Fault Address Register) 
* can be found in de Co-Processor CP15 register 6 and 7 */
void fail_dabt(void)
{
	register unsigned * link_ptr asm("lr");
	int trap_errno, instruction;
	kprintf("\nERROR: Software caused data abort at 0x%x\n",link_ptr);
	//trap_errno = read_cp15(5,0);
	//instruction = read_cp15(6,0);
	//pagefault(*instruction, trap_errno);
	asm("SUBS PC,R14,#8");		/* return 2 instructions before D-ABT occured, to retry */
}

/* exception handler for FIQ */ 
void FIQ_handler(void)
{
	register unsigned * link_ptr asm("lr");
	kprintf("\nERROR: An FIQ occured, but no handler is defined! 0x%x\n",link_ptr);
	asm("SUBS PC,R14,#4");
}

/*
*
* dummy operations for Minix
*
*
*/
void reset(void);
void monitor(void);

void reset(void)
{
	register unsigned * link_ptr asm("lr");
	kprintf("\r\nSoftware called for a system reset at 0x%x\r\nPlease press the reset button on the board :)",link_ptr);
	while(1);
}

void monitor(void)
{
	register unsigned * link_ptr asm("lr");
	kprintf("\r\nSoftware called to return to the system monitor 0x%x\r\nI guess that would be RedBoot, so please press the reset button on the board :)",link_ptr);
	while(1);
}

void undef_task(void);
void undef_task(void)
{
	kprintf("\r\nThis is an undefined task, time to make a bootloader!");
}

