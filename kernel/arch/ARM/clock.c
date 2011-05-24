
/* ARM-specific clock functions. */

#include <EP93xx.h>
#include <minix/portio.h>


#include "../../kernel.h"

/*===========================================================================*
 *				arch_init_clock				     *
 *===========================================================================*/
PUBLIC int arch_init_clock(void)
{
	/* For the EP93xx CPU. there is a 60Hz hardware interrupt, purely in hardware, 
	there are no settings, and it cannot be shut down (only it's interrupt line) */
	
	/* RTC will not be used for EP93xx, shut it down just to be sure */
	RTC_LOAD	= 0x00;		/* reset RTC */
	RTC_MATCH	= 0x00;		/* no match value */
	RTC_CTRL	= 0x00;		/* disable interrupt on match */
	RTC_STS		= 0x01;		/* clear any pending interrupt */
	RTC_SW_COMP	= 0x00;		/* no software trim, set to default 1Hz generation */
	
	/* clear the interrupt bit of the 60Hz hardware tick, to start clean */
	SYSTEM_TICK_INT_ACK = 0x01;		/* clear interrupt source */
	return OK;
}

/*===========================================================================*
 *				clock_stop				     *
 *===========================================================================*/
PUBLIC void clock_stop(void)
{
	/* The EP93xx has a hardware clock, it cannot be stopped. Also, the ARM port does not 
	have a bootloader, so there is no need to shut down the clock */
	return;
}

/*===========================================================================*
 *				read_clock				     *
 *===========================================================================*/
PUBLIC clock_t read_clock(void)
{
	/* Return the current value of timer1 */   
	u32_t count;
	count = RTC_DATA;
	return count;
}

