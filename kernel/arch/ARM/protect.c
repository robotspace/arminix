/* This file contains code for initialization of protected mode, to initialize
 * code and data segment descriptors, and to initialize global descriptors
 * for local descriptors in the process table.
 */

#include "../../kernel.h"
#include "../../proc.h"
#include <archconst.h>
#include "proto.h"

/*===========================================================================*
 *				seg2phys			
 *
 * wordt alleen gebruikt in start.c
 *===========================================================================*/
PUBLIC phys_bytes seg2phys(U16_t seg)
{
/* This is a workaround, since seg2phys is not needed by ARM, but this functions is called from main.c, which is supposed to
* be architecture independend.
 */
    return (phys_bytes) seg;
}

/*===========================================================================*
 *				init_dataseg				     *
 *
 * wordt gebruikt in protect.c en memory.c
 *===========================================================================*/
PUBLIC void init_dataseg(register struct segdesc_s *segdp, phys_bytes base, vir_bytes size, int privilege)
{
	/* This will eventually be necessary, but for now its unused */
}

/*===========================================================================*
 *				init_codeseg				     *
 *
 * wordt gebruikt in protect.c
 *===========================================================================*/
PUBLIC void init_codeseg(register struct segdesc_s *segdp, phys_bytes base, vir_bytes size, int privilege)
{
	/* This will eventually be necessary, but for now its unused */
}

/*===========================================================================*
 *				alloc_segments				     *
 * wordt aangeroepen vanuit main.c en system/do_newmap
 *===========================================================================*/

 PUBLIC void alloc_segments(register struct proc *rp)
{
/* this function is used as a dirty hack, since we do not have arguments about a.out files passed to the kernel by any loader,
we have got to establish stacks for all processes. */
	if (isusern(proc_nr(rp))) {		/* user-space process? */ 
		static int i = 1;					/* use first 1024 bytes for SVC stack */
		rp->p_reg.sp = 0xF4A40-(i++*1024);
	}
}

