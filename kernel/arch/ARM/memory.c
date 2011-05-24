/*
* =====================================================================
* ARM/memory.c
* =====================================================================
*
* ARM Virtual Memory for Minix3 ARM port
* written by: Léon Melis sept. 2009
* Based upon origional memory.c for i386.
*
* notes:
*	4 sept 09 	- The ARM does not have "high memory", or a BIOS to determine its size.
*				To retain compatibility with the non-architecture dependent sources, 
*				this value should manualy determined and passed by a dummy BIOS
*				- Aperantly each running process knows where the i386 page directory
*				base is located, in i386 this is stored in the CR3 register. For compatibility
*				reasons, the ARM level1 table base pointer is supplied as CR3 value to 
*				each process.
*	15 sept 09	- Removed all print functions, since they are not used
*
* Resources:
* 	- ARM920T reference manual chapter 3
*/

// compat, still to do
#define	ARM_VM_WRITE	1


#include "../../kernel.h"
#include "../../proc.h"
#include "../../vm.h"

#include <minix/type.h>
#include <minix/syslib.h>
#include <minix/sysutil.h>
#include <string.h>

#include "vm_ARM.h"

#include <minix/portio.h>

#include "proto.h"
#include "../../proto.h"
#include "../../debug.h"

/* VM functions and data. */
PUBLIC u32_t kernel_cr3;
FORWARD _PROTOTYPE( void phys_put32, (phys_bytes addr, u32_t value)	);
FORWARD _PROTOTYPE( u32_t phys_get32, (phys_bytes addr)			);

#if DEBUG_VMASSERT
#define vmassert(t) { \
	if(!(t)) { minix_panic("vm: assert " #t " failed\n", __LINE__); } }
#else
#define vmassert(t) { }
#endif

/**** Internal VM Functions ***  called from do_vmctl */
PUBLIC void vm_init(void)
{
	int o;
	phys_bytes p, lvl2_size;
	phys_bytes vm_lvl1_base, vm_lvl2_base, phys_mem;
	u32_t entry;
	unsigned pages;
	struct proc* rp;

	if (!vm_size)				/* determined in DO_VM_SETBUF */
		minix_panic("ARM_vm_init: no space for page tables", NO_NUM);

	if(vm_running){				/* test if this routine has already runned, is set to 0 in main.c */
#if VM_DEBUG					/* defined in do_vm_setbuf */
		kprintf("memory.c: VM was already initiated...\r\n"
#endif
		return;
	}	
#if VM_DEBUG
	kprintf("memory.c: Initiating VM...\r\n"	
#endif
	
	/* Align level1 entry point */
	o = (vm_base % ARM_VM_LVL1_ALIGNMENT);		/* VM base determined in DO_VM_SETBUF */
	if (o != 0)	o = ARM_VM_LVL1_ALIGNMENT-o;	/* if not aligned */
	vm_lvl1_base = vm_base + o;					/* add offset to the vm_base */

	/* Level2 tables start after the level1 table */
	vm_lvl2_base = vm_lvl1_base+(ARM_VM_LVL1_ENTRIES*ARM_VM_LVL1_ENT_SIZE);

	/* determine total size of lvl2 tables */
	lvl2_size = (vm_base+vm_size)-vm_lvl2_base;			/* determine total size of page table section */
	lvl2_size -= (lvl2_size % ARM_VM_PAGE_SIZE);			/* determine total size of PTE's that actually fit */

	/* Compute the number of pages based on vm_mem_high */
	pages = (vm_mem_high-1)/ARM_VM_PAGE_SIZE + 1;			/* actual ammount of pages that fit in the high memory */

	/* check if pages will actually fit in space allocated for page tables */
	if (pages * ARM_VM_LVL2_ENT_SIZE > lvl2_size)
		minix_panic("ARM_vm_init: level2 page table too small", NO_NUM);

	/* Set up the level2 entries */
	for (p= 0; p*ARM_VM_LVL2_ENT_SIZE < lvl2_size; p++)	/* do for all pages */
	{
		phys_mem = p*ARM_VM_PAGE_SIZE;						/* phys address of page */
		entry = phys_mem | ARM_VM_LVL2_SMALL;			/* set up level2 entry */
		if (phys_mem >= vm_mem_high) 
			entry= 0;									/* entry's beyond system's high memory SBZ */
		phys_put32(vm_lvl2_base + p*ARM_VM_LVL2_ENT_SIZE, entry);		/* write the PTE's */
	}

	/* Set up the level1 entries */		
	for (p= 0; p < ARM_VM_LVL1_ENTRIES; p++)
	{
		phys_mem= vm_lvl2_base + p*ARM_VM_PAGE_SIZE;
		entry= phys_mem | ARM_VM_LVL1_COARSE;
		if (phys_mem >= vm_lvl2_base + lvl2_size)
			entry= 0;
		phys_put32(vm_lvl1_base + p*ARM_VM_LVL1_ENT_SIZE, entry);
	}

	/* Set this cr3 in all currently running processes for
	 * future context switches.
	 */
	for (rp=BEG_PROC_ADDR; rp<END_PROC_ADDR; rp++) {		/* do for all processes */
		//u32_t mycr3;
		if(isemptyp(rp)) continue;							/* check if process is not empty */
	//	rp->p_seg.p_cr3 = vm_lvl1_base;						/* set directory base for all processes */
	}

	kernel_cr3 = vm_lvl1_base;								/* set directory base for the kernel */

	/* Set this cr3 now (not active until paging enabled). */
	write_cp15(2,0,vm_lvl1_base);

	/* Actually enable paging (activating cr3 load above). */
	write_cp15(1,0,(read_cp15(1,0)|0x1));	/* set bit 0 in CP15 register 2 */
	
	/* Don't do this init in the future. */
	vm_running = 1;
}

PRIVATE void phys_put32(addr, value)
phys_bytes addr;
u32_t value;
{
	phys_copy(value, addr, sizeof(value));
}

PRIVATE u32_t phys_get32(addr)
phys_bytes addr;
{
	u32_t value = 0;
	phys_copy(addr, value, sizeof(value));
	return value;
}


/*===========================================================================*
 *                              alloc_remote_segment                         *
 *===========================================================================*/
PUBLIC vir_bytes alloc_remote_segment(u32_t *selector, segframe_t *segments, int index, phys_bytes phys, vir_bytes size, int priv)
{
	phys_bytes offset = 0;
	/* Check if the segment size can be recorded in bytes, that is, check
	 * if descriptor's limit field can delimited the allowed memory region
	 * precisely. This works up to 1MB. If the size is larger, 4K pages
	 * instead of bytes are used.
	*/
	#if 0
	if (size < BYTE_GRAN_MAX) {		/* defined in archconst.h */
	if(1){
		init_dataseg(&segments->p_ldt[EXTRA_LDT_INDEX+index], phys, size, priv);
		*selector = ((EXTRA_LDT_INDEX+index)*0x08) | (1*0x04) | priv;
		offset = 0;
	} else {						/* use 4k page */
		init_dataseg(&segments->p_ldt[EXTRA_LDT_INDEX+index], phys & ~0xFFFF, 0, priv);
		*selector = ((EXTRA_LDT_INDEX+index)*0x08) | (1*0x04) | priv;
		offset = phys & 0xFFFF;
	}
	#endif
	return offset;
}


/*===========================================================================*
 *                              umap_remote                                  *
 *===========================================================================*/
PUBLIC phys_bytes umap_remote(struct proc* rp, int seg,	vir_bytes vir_addr, vir_bytes bytes)
{
/* Calculate the physical memory address for a given virtual address. */
  struct far_mem *fm;

#if 0
  if(rp->p_misc_flags & MF_FULLVM) return 0;
#endif

  if (bytes <= 0) return( (phys_bytes) 0);							/* if number of requested bytes is 0 or negative, return 0 */
  if (seg < 0 || seg >= NR_REMOTE_SEGS) return( (phys_bytes) 0);	/* if segment is negative of greater than NR_REMOTE_SEGS, return 0, defined in archconst.h*/

  fm = &rp->p_priv->s_farmem[seg];
  if (! fm->in_use) return( (phys_bytes) 0);						/* if in use, return 0 */
  if (vir_addr + bytes > fm->mem_len) return( (phys_bytes) 0);		/* if beyond memory length, return 0 */

  return(fm->mem_phys + (phys_bytes) vir_addr);						/* return calculated address */
}



/*===========================================================================*
 *                              umap_local                                   *
 *===========================================================================*/
PUBLIC phys_bytes umap_local(rp, seg, vir_addr, bytes)
register struct proc *rp;       /* pointer to proc table entry for process */
int seg;                        /* T, D, or S segment */
vir_bytes vir_addr;             /* virtual address in bytes within the seg */
vir_bytes bytes;                /* # of bytes to be copied */
{
/* Calculate the physical memory address for a given virtual address. */
 #if 0
  vir_clicks vc;                /* the virtual address in clicks */
  phys_bytes pa;                /* intermediate variables as phys_bytes */
  phys_bytes seg_base;

  if(seg != T && seg != D && seg != S)
	minix_panic("umap_local: wrong seg", seg);

  if (bytes <= 0) return( (phys_bytes) 0);
  if (vir_addr + bytes <= vir_addr) return 0;   /* overflow */
  vc = (vir_addr + bytes - 1) >> CLICK_SHIFT;   /* last click of data */
 
  if (seg != T)
        seg = (vc < rp->p_memmap[D].mem_vir + rp->p_memmap[D].mem_len ? D : S);
 
  if ((vir_addr>>CLICK_SHIFT) >= rp->p_memmap[seg].mem_vir + rp->p_memmap[seg].mem_len) 
		return( (phys_bytes) 0 );
 
  if (vc >= rp->p_memmap[seg].mem_vir + rp->p_memmap[seg].mem_len) 
		return( (phys_bytes) 0 );
  
  seg_base = (phys_bytes) rp->p_memmap[seg].mem_phys;
  seg_base = seg_base << CLICK_SHIFT;   /* segment origin in bytes */
  pa = (phys_bytes) vir_addr;
  pa -= rp->p_memmap[seg].mem_vir << CLICK_SHIFT;
  return(seg_base + pa);
#endif
  return(vir_addr);
}

/*===========================================================================*
 *                              umap_virtual                                 *
 *===========================================================================*/
PUBLIC phys_bytes umap_virtual(rp, seg, vir_addr, bytes)
register struct proc *rp;       /* pointer to proc table entry for process */
int seg;                        /* T, D, or S segment */
vir_bytes vir_addr;             /* virtual address in bytes within the seg */
vir_bytes bytes;                /* # of bytes to be copied */
{
	vir_bytes linear;
	u32_t phys = 0;

	if(seg == MEM_GRANT) {
		phys = umap_grant(rp, vir_addr, bytes);
	} else {
		if(!(linear = umap_local(rp, seg, vir_addr, bytes))) {
			kprintf("SYSTEM:umap_virtual: umap_local failed\n");
			phys = 0;
		} else {
			if(vm_lookup(rp, linear, &phys, NULL) != OK) {
				kprintf("SYSTEM:umap_virtual: vm_lookup of %s: seg 0x%lx: 0x%lx failed\n", rp->p_name, seg, vir_addr);
				phys = 0;
			}
			if(phys == 0)
				minix_panic("vm_lookup returned phys", phys);
		}
	}

	if(phys == 0) {
		kprintf("SYSTEM:umap_virtual: lookup failed\n");
		return 0;
	}

	/* Now make sure addresses are contiguous in physical memory
	 * so that the umap makes sense.
	 */
	if(bytes > 0 && !vm_contiguous(rp, linear, bytes)) {
		kprintf("umap_virtual: %s: %d at 0x%lx (vir 0x%lx) not contiguous\n",
			rp->p_name, bytes, linear, vir_addr);
		return 0;
	}

	/* phys must be larger than 0 (or the caller will think the call
	 * failed), and address must not cross a page boundary.
	 */
	vmassert(phys);

	return phys;
}

/*===========================================================================*
 *                              vm_lookup                                    *
 *===========================================================================*/
PUBLIC int vm_lookup(struct proc *proc, vir_bytes virtual, vir_bytes *physical, u32_t *ptent)
{
	u32_t *root, *pt;
	int pde, pte;
	u32_t pde_v, pte_v;

	vmassert(proc);
	vmassert(physical);
	vmassert(!(proc->p_rts_flags & SLOT_FREE));

	/* Retrieve level1 entry. */
	//root = (u32_t *) proc->p_seg.p_cr3;
	vmassert(!((u32_t) root % ARM_VM_PAGE_SIZE));
	pde = ARM_VM_LVL1E(virtual);
	vmassert(pde >= 0 && pde < ARM_VM_LVL1_ENTRIES);
	pde_v = phys_get32((u32_t) (root + pde));
	if(!(pde_v & 0x3)) {			/* check if type bits [0:1] in lvl1 entry != 0 */
#if 0
		kprintf("vm_lookup: %d:%s:0x%lx: cr3 0x%lx: pde %d not present\n",
			proc->p_endpoint, proc->p_name, virtual, root, pde);
		kprintf("kernel stack: ");
		util_stacktrace();
#endif
		return EFAULT;
	}

	/* Retrieve level2 entry. */
	pt = (u32_t *) ARM_VM_LVL2A(pde_v);
	vmassert(!((u32_t) pt % ARM_VM_PAGE_SIZE));
	pte = ARM_VM_LVL2E(virtual);
	vmassert(pte >= 0 && pte < ARM_VM_LVL2_ENTRIES);
	pte_v = phys_get32((u32_t) (pt + pte));
	if(!(pte_v & 0x3)) {			/* check if type bits [0:1] in lvl2 entry != 0 */
#if 0
		kprintf("vm_lookup: %d:%s:0x%lx: cr3 %lx: pde %d: pte %d not present\n",
			proc->p_endpoint, proc->p_name, virtual, root, pde, pte);
		kprintf("kernel stack: ");
		util_stacktrace();
#endif
		return EFAULT;
	}

	if(ptent) *ptent = pte_v;

	/* Actual address now known; retrieve it and add page offset. */
	*physical = ARM_VM_LVL2A(pte_v);
	*physical += virtual % ARM_VM_PAGE_SIZE;

	return OK;
}

/* From virtual address v in process p,
 * lookup physical address and assign it to d.
 * If p is NULL, assume it's already a physical address.
 */
#define LOOKUP(d, p, v, flagsp) {									\
	int r; 															\
	if(!(p)) { (d) = (v); } 										\
	else {															\
		if((r=vm_lookup((p), (v), &(d), flagsp)) != OK) { 			\
			kprintf("vm_copy: lookup failed of 0x%lx in %d (%s)\n"	\
				"kernel stacktrace: ", (v), (p)->p_endpoint, 		\
					(p)->p_name);									\
			util_stacktrace();										\
			return r;												\
		} } }

/*===========================================================================*
 *                              vm_copy                                      *
 *===========================================================================*/
int vm_copy(vir_bytes src, struct proc *srcproc,
	 vir_bytes dst, struct proc *dstproc, phys_bytes bytes)
{
#define WRAPS(v) (ULONG_MAX - (v) <= bytes)

	if(WRAPS(src) || WRAPS(dst))
		minix_panic("vm_copy: linear address wraps", NO_NUM);

	while(bytes > 0) {
		u32_t n, flags;
		phys_bytes p_src, p_dst;
#define PAGEREMAIN(v) (ARM_VM_PAGE_SIZE - ((v) % ARM_VM_PAGE_SIZE))

		/* We can copy this number of bytes without
		 * crossing a page boundary, but don't copy more
		 * than asked.
		 */
		n = MIN(PAGEREMAIN(src), PAGEREMAIN(dst));
		n = MIN(n, bytes);
		vmassert(n > 0);
		vmassert(n <= ARM_VM_PAGE_SIZE);

		/* Convert both virtual addresses to physical and do
		 * copy.
		 */
		LOOKUP(p_src, srcproc, src, NULL);
		LOOKUP(p_dst, dstproc, dst, &flags);
#if 0		/* ARM does not have writeable flag in entry */		
		if(!(flags & I386_VM_WRITE)) {
			kprintf("vm_copy: copying to nonwritable page\n");
			kprintf("kernel stack: ");
			util_stacktrace();
			return EFAULT;
		}
#endif
		phys_copy(p_src, p_dst, n);

		/* Book number of bytes copied. */
		vmassert(bytes >= n);
		bytes -= n;
		src += n;
		dst += n;
	}

	return OK;
}

/*===========================================================================*
 *                              vm_contiguous                                *
 *===========================================================================*/
PUBLIC int vm_contiguous(struct proc *targetproc, u32_t vir_buf, size_t bytes)
{
	int first = 1, r, boundaries = 0;
	u32_t prev_phys, po;
	u32_t prev_vir;

	vmassert(targetproc);
	vmassert(bytes > 0);
	vmassert(vm_running);

	/* Start and end at page boundary to make logic simpler. */
	po = vir_buf % ARM_VM_PAGE_SIZE;
	if(po > 0) {
		bytes += po;
		vir_buf -= po;
	}
	po = (vir_buf + bytes) % ARM_VM_PAGE_SIZE;
	if(po > 0)
		bytes += ARM_VM_PAGE_SIZE - po;

	/* Keep going as long as we cross a page boundary. */
	while(bytes > 0) {
		u32_t phys;

		if((r=vm_lookup(targetproc, vir_buf, &phys, NULL)) != OK) {
			kprintf("vm_contiguous: vm_lookup failed, %d\n", r);
			kprintf("kernel stack: ");
			util_stacktrace();
			return 0;
		}

		if(!first) {
			if(prev_phys+ARM_VM_PAGE_SIZE != phys) {
				kprintf("vm_contiguous: no (0x%lx, 0x%lx)\n",
					prev_phys, phys);
				kprintf("kernel stack: ");
				util_stacktrace();
				return 0;
			}
		}

		first = 0;

		prev_phys = phys;
		prev_vir = vir_buf;
		vir_buf += ARM_VM_PAGE_SIZE;
		bytes -= ARM_VM_PAGE_SIZE;
		boundaries++;
	}

	if(verbose_vm)				/* global var (glo.h) */
		kprintf("vm_contiguous: yes (%d boundaries tested)\n",
			boundaries);

	return 1;
}

int vm_checkrange_verbose = 0;

/*===========================================================================*
 *                              vm_checkrange                                *
 *===========================================================================*/
PUBLIC int vm_checkrange(struct proc *caller, struct proc *target,
	vir_bytes vir, vir_bytes bytes, int wrfl, int checkonly)
{
	u32_t flags, po, v;
	//int r;

	vmassert(vm_running);

	/* If caller has had a reply to this request, return it. */
	if(RTS_ISSET(caller, VMREQUEST)) {
		if(caller->p_vmrequest.who == target->p_endpoint) {
			if(caller->p_vmrequest.vmresult == VMSUSPEND)
				minix_panic("check sees VMSUSPEND?", NO_NUM);
			RTS_LOCK_UNSET(caller, VMREQUEST);
#if VM_DEBUG
			kprintf("SYSTEM: vm_checkrange: returning vmresult %d\n",
				caller->p_vmrequest.vmresult);
#endif
			return caller->p_vmrequest.vmresult;
		} else {
#if VM_DEBUG
			kprintf("SYSTEM: vm_checkrange: caller has a request for %d, "
				"but our target is %d\n",
				caller->p_vmrequest.who, target->p_endpoint);
#endif
		}
	}

	po = vir % ARM_VM_PAGE_SIZE;
	if(po > 0) {
		vir -= po;
		bytes += po;
	}

	vmassert(target);
	vmassert(bytes > 0);

	for(v = vir; v < vir + bytes;  v+= ARM_VM_PAGE_SIZE) {
		u32_t phys;

		/* If page exists and it's writable if desired, we're OK
		 * for this page.
		 */
		if(vm_lookup(target, v, &phys, &flags) == OK && !(wrfl && !(flags & ARM_VM_WRITE))) {
			if(vm_checkrange_verbose) {
#if VM_DEBUG
				kprintf("SYSTEM: checkrange:%s:%d: 0x%lx: write 0x%lx, flags 0x%lx, phys 0x%lx, OK\n",
				target->p_name, target->p_endpoint, v, wrfl, flags, phys);
#endif
			}
			continue;
		}

		if(vm_checkrange_verbose) {
			kprintf("SYSTEM: checkrange:%s:%d: 0x%lx: write 0x%lx, flags 0x%lx, phys 0x%lx, NOT OK\n",
			target->p_name, target->p_endpoint, v, wrfl, flags, phys);
		}

		if(checkonly)
			return VMSUSPEND;

		/* This range is not OK for this process. Set parameters
		 * of the request and notify VM about the pending request.
		 */
		if(RTS_ISSET(caller, VMREQUEST))
			minix_panic("VMREQUEST already set", caller->p_endpoint);
		RTS_LOCK_SET(caller, VMREQUEST);

		/* Set parameters in caller. */
		caller->p_vmrequest.writeflag = wrfl;
		caller->p_vmrequest.start = vir;
		caller->p_vmrequest.length = bytes;
		caller->p_vmrequest.who = target->p_endpoint;

		/* Set caller in target. */
		target->p_vmrequest.requestor = caller;

		/* Connect caller on vmrequest wait queue. */
		caller->p_vmrequest.nextrequestor = vmrequest;
		vmrequest = caller;
		soft_notify(VM_PROC_NR);

#if VM_DEBUG
		kprintf("SYSTEM: vm_checkrange: range bad for "
			"target %s:0x%lx-0x%lx, caller %s\n",
				target->p_name, vir, vir+bytes, caller->p_name);

		kprintf("vm_checkrange kernel trace: ");
		util_stacktrace();
		kprintf("target trace: ");
		proc_stacktrace(target);
#endif

		if(target->p_endpoint == VM_PROC_NR) {
			kprintf("caller trace: ");
			proc_stacktrace(caller);
			kprintf("target trace: ");
			proc_stacktrace(target);
			minix_panic("VM ranges should be OK", NO_NUM);
		}

		return VMSUSPEND;
	}

	return OK;
}


/*===========================================================================*
 *				virtual_copy_f				     *
 * defined in proto.h as virtual_copy and virtual_copy_vmcheck
 *===========================================================================*/
PUBLIC int virtual_copy_f(src_addr, dst_addr, bytes, vmcheck)
struct vir_addr *src_addr;	/* source virtual address */
struct vir_addr *dst_addr;	/* destination virtual address */
vir_bytes bytes;		/* # of bytes to copy  */
int vmcheck;			/* if nonzero, can return VMSUSPEND */
{
/* Copy bytes from virtual address src_addr to virtual address dst_addr. 
 * Virtual addresses can be in ABS, LOCAL_SEG, REMOTE_SEG, or BIOS_SEG.
 */
  struct vir_addr *vir_addr[2];	/* virtual source and destination address */
  phys_bytes phys_addr[2];	/* absolute source and destination */ 
  int seg_index;
  int i, r;
  struct proc *procs[2];

  /* Check copy count. */
  if (bytes <= 0) return(EDOM);

  /* Do some more checks and map virtual addresses to physical addresses. */
  vir_addr[_SRC_] = src_addr;
  vir_addr[_DST_] = dst_addr;

  for (i=_SRC_; i<=_DST_; i++) {
	int proc_nr, type;
	struct proc *p;

 	type = vir_addr[i]->segment & SEGMENT_TYPE;
	if((type != PHYS_SEG && type != BIOS_SEG) &&
	   isokendpt(vir_addr[i]->proc_nr_e, &proc_nr))
		p = proc_addr(proc_nr);
	else 
		p = NULL;

	procs[i] = p;

      /* Get physical address. */
      switch(type) {
      case LOCAL_SEG:
      case LOCAL_VM_SEG:
	  if(!p) return EDEADSRCDST;
          seg_index = vir_addr[i]->segment & SEGMENT_INDEX;
	  if(type == LOCAL_SEG)
	          phys_addr[i] = umap_local(p, seg_index, vir_addr[i]->offset,
			bytes);
	  else
	  	phys_addr[i] = umap_virtual(p, seg_index, vir_addr[i]->offset,
			bytes);
	  if(phys_addr[i] == 0) {
		kprintf("virtual_copy: map 0x%x failed for %s seg %d, "
			"offset %lx, len %d, i %d\n",
			type, p->p_name, seg_index, vir_addr[i]->offset,
			bytes, i);
	  }
          break;
      case REMOTE_SEG:
	  if(!p) return EDEADSRCDST;
          seg_index = vir_addr[i]->segment & SEGMENT_INDEX;
          phys_addr[i] = umap_remote(p, seg_index, vir_addr[i]->offset, bytes);
          break;
#if _MINIX_CHIP == _CHIP_INTEL
      case BIOS_SEG:
          phys_addr[i] = umap_bios(vir_addr[i]->offset, bytes );
          break;
#endif
      case PHYS_SEG:
          phys_addr[i] = vir_addr[i]->offset;
          break;
      case GRANT_SEG:
	  phys_addr[i] = umap_grant(p, vir_addr[i]->offset, bytes);
	  break;
      default:
	  kprintf("virtual_copy: strange type 0x%x\n", type);
          return(EINVAL);
      }

      /* Check if mapping succeeded. */
      if (phys_addr[i] <= 0 && vir_addr[i]->segment != PHYS_SEG)  {
      kprintf("virtual_copy EFAULT\n");
          return(EFAULT);
      }
  }

  if(vmcheck && procs[_SRC_])
	CHECKRANGE_OR_SUSPEND(procs[_SRC_], phys_addr[_SRC_], bytes, 0);
  if(vmcheck && procs[_DST_])
	CHECKRANGE_OR_SUSPEND(procs[_DST_], phys_addr[_DST_], bytes, 1);

  /* Now copy bytes between physical addresseses. */
  if(!vm_running || (procs[_SRC_] == NULL && procs[_DST_] == NULL)) {
	/* Without vm, address ranges actually are physical. */
	phys_copy(phys_addr[_SRC_], phys_addr[_DST_], (phys_bytes) bytes);
	r = OK;
  } else {
	/* With vm, addresses need further interpretation. */
	r = vm_copy(phys_addr[_SRC_], procs[_SRC_], 
		phys_addr[_DST_], procs[_DST_], (phys_bytes) bytes);
	if(r != OK) {
		kprintf("vm_copy: %lx to %lx failed\n",
			phys_addr[_SRC_],phys_addr[_DST_]);
	}
  }

  return(r);
}

/*===========================================================================*
 *				data_copy				     *
 *===========================================================================*/
PUBLIC int data_copy(endpoint_t from_proc, vir_bytes from_addr,	endpoint_t to_proc, vir_bytes to_addr, size_t bytes)
{
  struct vir_addr src, dst;

  src.segment = dst.segment = D;
  src.offset = from_addr;
  dst.offset = to_addr;
  src.proc_nr_e = from_proc;
  dst.proc_nr_e = to_proc;

  return virtual_copy(&src, &dst, bytes);
}


/* called from do_exec */
/*===========================================================================*
 *				arch_pre_exec				     *
 *===========================================================================*/
PUBLIC int arch_pre_exec(struct proc *pr, u32_t ip, u32_t sp)
{
/* wipe extra LDT entries, set program counter, and stack pointer. */
	//memset(pr->p_seg.p_ldt + EXTRA_LDT_INDEX, 0, sizeof(pr->p_seg.p_ldt[0]) * (LDT_SIZE - EXTRA_LDT_INDEX));
	pr->p_reg.pc = ip;
	pr->p_reg.sp = sp;
	return 0;
}

/* called from do_umap */
/*===========================================================================*
 *				arch_umap				     *
 *===========================================================================*/
PUBLIC int arch_umap(struct proc *pr, vir_bytes offset, vir_bytes count, int seg, phys_bytes *addr)
{
	//switch(seg) {
	//	case BIOS_SEG:
	//		*addr = umap_bios(offset, count);
	//		return OK;
	//}

	/* This must be EINVAL; the umap fallback function in
	 * lib/syslib/alloc_util.c depends on it to detect an
	 * older kernel (as opposed to mapping error).
	 */
	return EINVAL;
}
