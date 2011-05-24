/*****************************************************************
* ARM PL190 interrupt controller. 
* For the ARM-Minix project
*
* The EP93xx CPU used for this project has 2 PL190's in a daisy 
* chained setup, therefore VIC1 and VIC2 are present.
*
* Author: Léon Melis 08-2009
*
*****************************************************************/
#include "../../kernel.h"
#include "../../proc.h"
#include "../../proto.h"

extern void __enable_interrupts(void);
extern void __disable_interrupts(void);
extern void __irq_isr(void);
//extern void clock_handler(void);

//void intr_init(int mine);
void ISR_CLK1HZ(void);
void ISR_CLK64HZ(void);
void ISR_TMR1(void);
void ISR_UART1(void);
int intr_disabled(void);

#include "./include/PL190.h"
#include "./include/EP93xx.h"
#include "../../kernel.h"
#include "../../proc.h"
#include "proto.h"
#include <minix/com.h>
#include <minix/portio.h>

#define		reg_VIC1Addr	0x800B0100
#define		reg_VIC1Cntl	0x800B0200
#define		reg_VIC2Addr	0x800C0100
#define		reg_VIC2Cntl	0x800C0200

PUBLIC int intr_init(int mine){
	/* Disable IRQ and FIQ in CPSR */
	int i;
	intr_disable();
	
	VIC1IntSelect		= 0x00;			/*all vectors of VIC1 are IRQ (0 = IRQ, 1 = FIQ) */
	VIC2IntSelect		= 0x00;			/*all vectors of VIC2 are IRQ (0 = IRQ, 1 = FIQ) */
	
	VIC1IntEnClear	= ~0x00;			/* clear ALL bit of VIC1IntEnable */
	VIC2IntEnClear	= ~0x00;			/* clear ALL bit of VIC2IntEnable */

	VIC1SoftIntClear	= ~0x00;			/* Clear all soft interrupts of VIC1 */
	VIC2SoftIntClear	= ~0x00;			/* Clear all soft interrupts of VIC2 */
	
	VIC1Protection	= 0x00;			/* VIC1 protection, 0 = user mode */
	VIC2Protection	= 0x00;			/* VIC2 protection, 0 = user mode */
	
	/* clear vector 1 */
	for(i=0; i<=31; i++)
	{
		*((volatile unsigned int *)reg_VIC1Addr+i) = 0x00;
		*((volatile unsigned int *)reg_VIC1Cntl+i) = 0x00;
	}
	
	/* clear vector 2 */
	for(i=0; i<=31; i++)
	{
		*((volatile unsigned int *)reg_VIC2Addr+i) = 0x00;
		*((volatile unsigned int *)reg_VIC2Cntl+i) = 0x00;
	}
	
	VIC1VectAddr	= 0xFF;			/* write any value to update VIC1 priority table */
	VIC2VectAddr	= 0xFF;			/* write any value to update VIC2 priority table */

	return OK;
}

/* experimental ISR for UART */
void ISR_UART1(void){
	char data;
	data = UART1_DATA;
	UART1_DATA = data;	/* echo */
}

int intr_disabled(void)
{
	if(read_cpu_flags() & 1<<7)		/* check for INT flag in CPSR, if set, interrupts are disabled */
		return 1;
	return 0;
}

int intr_unmask(irq_hook_t* hook){
	if(hook->irq <= 32){		/* VIC1 */
		*((volatile unsigned int *)reg_VIC1Addr+(hook->id)) = (unsigned int)hook->handler;
		*((volatile unsigned int *)reg_VIC1Cntl+(hook->id)) = (hook->irq | 0x20);
		VIC1IntEnable	= (1<<(hook->irq));
		VIC1VectAddr	= 0xFF;			/* write any value to update VIC1 priority table */
		intr_enable();
		return OK;
	}
	else if(hook->irq <= 64){		/* VIC2 */
		*((volatile unsigned int *)reg_VIC2Addr+(hook->id)) = (unsigned int)hook->handler;
		*((volatile unsigned int *)reg_VIC2Cntl+(hook->id)) = (hook->irq | 0x20);
		VIC2IntEnable	= (1<<(hook->irq-32));
		VIC2VectAddr	= 0xFF;			/* write any value to update VIC2 priority table */
		intr_enable();
		return OK;
	}
	else{
		return -1;
	}
}

int intr_mask(irq_hook_t* hook){
	if(hook->irq <= 32){		/* VIC1 */
		VIC1IntEnable	&=  ~(1<<(hook->irq));
		VIC1VectAddr	= 0xFF;			/* write any value to update VIC1 priority table */
		return OK;
	}
	else if(hook->irq <= 64){		/* VIC2 */
		VIC2IntEnable	&= ~(1<<(hook->irq-32));
		VIC2VectAddr	= 0xFF;			/* write any value to update VIC2 priority table */
		return OK;
	}
	else{
		return -1;
	}
}
