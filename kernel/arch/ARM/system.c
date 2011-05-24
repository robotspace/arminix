/* system dependent functions for use inside the whole kernel. */

#include "../../kernel.h"

#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <minix/portio.h>
#include <minix/u64.h>
#include <minix/sysutil.h>
#include <a.out.h>
#include <EP93xx.h>

#include "proto.h"
#include "../../proc.h"

PUBLIC void arch_shutdown(int how)
{
	/* Mask all interrupts, including the clock. */
	VIC1IntEnClear = ~0x00;		/* clear ALL bits of VIC1IntEnable */
	VIC2IntEnClear = ~0x00;		/* clear ALL bits of VIC2IntEnable */

	if(how != RBT_RESET) {
		/* return to boot monitor */

		/* Return to the boot monitor. Set
		 * the program if not already done.
		 */
		if (how != RBT_MONITOR)
			arch_set_params("", 1);
		if(minix_panicing) {
			int source, dest;
			static char mybuffer[sizeof(params_buffer)];
			char *lead = "echo \\n*** kernel messages:\\n";
			int leadlen = strlen(lead);
			strcpy(mybuffer, lead);

#define DECSOURCE source = (source - 1 + _KMESS_BUF_SIZE) % _KMESS_BUF_SIZE

			dest = sizeof(mybuffer)-1;
			mybuffer[dest--] = '\0';

			source = kmess.km_next;
			DECSOURCE; 

			while(dest >= leadlen) {
				char c = kmess.km_buf[source];
				if(c == '\n') {
					mybuffer[dest--] = 'n';
					mybuffer[dest] = '\\';
				} else if(isprint(c) &&
					c != '\'' && c != '"' &&
					c != '\\' && c != ';') {
					mybuffer[dest] = c;
				} else	mybuffer[dest] = ' ';

				DECSOURCE;
				dest--;
			}

			arch_set_params(mybuffer, strlen(mybuffer)+1);
		}
		kprintf("\n\n\n\r***** The system has stopped *****\n\rPlease press reset");
		while(1);
	} else {
		SYSCON_DEVICE_CONFIG = (1<<31);	/* Write to the reset bit in the system config register, this wil soft reset the CPU */
	}
}

/* address of a.out headers, set in mpx386.s */
phys_bytes aout;

PUBLIC void arch_get_aout_headers(int i, struct exec *h)
{
	/* The bootstrap loader created an array of the a.out headers at
	 * absolute address 'aout'. Get one element to h.
	 */
	//	phys_copy(aout + i * A_MINHDR, vir2phys(h), (phys_bytes) A_MINHDR);
}

PUBLIC void system_init(void)
{
	do_serial_debug = 1;
}

PUBLIC void ser_putc(char c)
{
	int timeout;
	for (timeout = 0; timeout < 1000; timeout++) {
		if (!(UART1_FLAG & (1 << 5))) break;		/* check for TX FIFO Full flag */
	}
	UART1_DATA = c;	
}
		
/*===========================================================================*
 *				do_ser_debug				     * 
 *===========================================================================*/
PUBLIC void do_ser_debug()
{
	u8_t c;
	if (!UART1_DATA) return;
	c = UART1_DATA;
	ser_debug(c);
}

PRIVATE void ser_debug(int c)
{
	do_serial_debug++;
	kprintf("ser_debug: %d\n", c);
	switch(c)
	{
	case '1':
		ser_dump_proc();
		break;
	case '2':
		ser_dump_stats();
		break;
	}
	do_serial_debug--;
}

PUBLIC void ser_dump_proc()
{
	struct proc *pp;

	for (pp= BEG_PROC_ADDR; pp < END_PROC_ADDR; pp++)
	{
		if (pp->p_rts_flags & SLOT_FREE)
			continue;
		kprintf(
	"%d: 0x%02x %s e %d src %d dst %d prio %d/%d time %d/%d EIP 0x%x\n",
			proc_nr(pp),
			pp->p_rts_flags, pp->p_name,
			pp->p_endpoint, pp->p_getfrom_e, pp->p_sendto_e,
			pp->p_priority, pp->p_max_priority,
			pp->p_user_time, pp->p_sys_time, 
			pp->p_reg.pc);
		proc_stacktrace(pp);
	}
}

PRIVATE void ser_dump_stats()
{
	kprintf("ipc_stats:\n");
	kprintf("deadproc: %d\n", ipc_stats.deadproc);
	kprintf("bad_endpoint: %d\n", ipc_stats.bad_endpoint);
	kprintf("dst_not_allowed: %d\n", ipc_stats.dst_not_allowed);
	kprintf("bad_call: %d\n", ipc_stats.bad_call);
	kprintf("call_not_allowed: %d\n", ipc_stats.call_not_allowed);
	kprintf("bad_buffer: %d\n", ipc_stats.bad_buffer);
	kprintf("deadlock: %d\n", ipc_stats.deadlock);
	kprintf("not_ready: %d\n", ipc_stats.not_ready);
	kprintf("src_died: %d\n", ipc_stats.src_died);
	kprintf("dst_died: %d\n", ipc_stats.dst_died);
	kprintf("no_priv: %d\n", ipc_stats.no_priv);
	kprintf("bad_size: %d\n", ipc_stats.bad_size);
	kprintf("bad_senda: %d\n", ipc_stats.bad_senda);
	if (ex64hi(ipc_stats.total))
	{
		kprintf("total: %x:%08x\n", ex64hi(ipc_stats.total),
			ex64lo(ipc_stats.total));
	}
	else
		kprintf("total: %u\n", ex64lo(ipc_stats.total));

	kprintf("sys_stats:\n");
	kprintf("bad_req: %d\n", sys_stats.bad_req);
	kprintf("not_allowed: %d\n", sys_stats.not_allowed);
	if (ex64hi(sys_stats.total))
	{
		kprintf("total: %x:%08x\n", ex64hi(sys_stats.total),
			ex64lo(sys_stats.total));
	}
	else
		kprintf("total: %u\n", ex64lo(sys_stats.total));
}

PUBLIC int arch_init_profile_clock(u32_t freq)
{
  return 0;
}

PUBLIC void arch_stop_profile_clock(void)
{
	return;
}

PUBLIC void arch_ack_profile_clock(void)
{
	return;
}

/* Saved by mpx386.s into these variables. */
u32_t params_size, params_offset, mon_ds;

PUBLIC int arch_get_params(char *params, int maxsize)
{
	/* there is no bootloader, so there are no parameters */
	params[0] = '\0';
	return OK;
}

PUBLIC int arch_set_params(char *params, int size)
{
	/* there is no bootloader, so there are no parameters */
	return OK;
}
