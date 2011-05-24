#include "../../system.h"
#include <minix/type.h>

/*===========================================================================*
 *				do_readbios				     *
 * Everything that != x86 does not have a BIOS....
 *===========================================================================*/
PUBLIC int do_readbios(m_ptr)
register message *m_ptr;	/* pointer to request message */
{
  struct vir_addr src, dst;     
        
  src.segment = 0;
  dst.segment = 0;
  src.offset = 0;
  dst.offset = 0;
  src.proc_nr_e = 0;
  dst.proc_nr_e = 0;      

  return virtual_copy_vmcheck(&src, &dst, m_ptr->RDB_SIZE);
}
