/* The kernel call implemented in this file:
 *   m_type:	SYS_VMCTL
 *
 * The parameters for this kernel call are:
 *   	SVMCTL_WHO	which process
 *    	SVMCTL_PARAM	set this setting (VMCTL_*)
 *    	SVMCTL_VALUE	to this value
 */

#include "../../system.h"
#include <minix/type.h>

extern u32_t kernel_cr3;

/*===========================================================================*
 *				arch_do_vmctl				     *
 *===========================================================================*/
PUBLIC int arch_do_vmctl(m_ptr, p)
register message *m_ptr;	/* pointer to request message */
struct proc *p;
{
  kprintf("arch_do_vmctl called, but not implemented\n");
  return -1;
}
