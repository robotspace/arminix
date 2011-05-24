
#ifndef _ARM_TYPES_H
#define _ARM_TYPES_H

#include <minix/sys_config.h>
#include "archconst.h"

typedef unsigned reg_t;         /* machine register */

struct stackframe_s { 
  reg_t psw;					/* is actually called PSR in ARM, but this is not compatible with Minix */
  reg_t r0;
  reg_t r1;
  reg_t r2;
  reg_t r3;
  reg_t r4;
  reg_t r5;
  reg_t r6;
  reg_t r7;
  reg_t r8;
  reg_t r9; 
  reg_t r10;
  reg_t fp;					/* named FP for compatibilty with Minix */
  reg_t r12;
  reg_t sp;
  reg_t lr;
  reg_t pc;
  reg_t retreg;
};

struct segdesc_s {		/* segment descriptor for protected mode */
};

typedef struct segframe {
	int segment_selector;
} segframe_t;

/* Page fault event. Stored in process table. Only valid if PAGEFAULT set in p_rts_flags. */
struct pagefault
{
	u32_t   pf_virtual;     /* Address causing fault. */
	u32_t   pf_flags;       /* Pagefault flags on stack. */
};

#endif 		/* _ARM_TYPES_H */

