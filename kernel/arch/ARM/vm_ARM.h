/*
* =====================================================================
* sys/vm_ARM.h
* =====================================================================
*
* ARM Virtual Memory for Minix3 ARM port
* written by: Léon Melis sept. 2009
*
*
* For highest possible compatibility with i386, small pages (4k) with 
* coarse tables (one entry per page) have been selected. 
* For a different setup, this file should be edited.
*
* Resources:
* 	- ARM920T reference manual chapter 3
*/

/* ARM VM globals */
#define ARM_VM_PAGE_SIZE		4096		/* size of single page */
#define ARM_VM_LVL1_ENTRIES		4096		/* Number of entries in a LVL1 table */
#define ARM_VM_LVL2_ENTRIES		256			/* Number of entries in a LVL2 table (coarse)*/
#define ARM_VM_LVL1_ALIGNMENT	16384		/* Level1 table base (pointed by CP15 reg 2) should reside on a 16k boundry */

/* Level1 entry */
#define ARM_VM_LVL1_ENT_SIZE	4			/* Size of a level1 table entry */
#define ARM_VM_LVL1_COARSE		0x11		/* set as coarse page table entry, domain 0 */
#define ARM_VM_LVL1_ADDR_MASK	0xFFFFFC00	/* address should reside in bits 31:10 */

/* level2 entry */
#define ARM_VM_LVL2_ENT_SIZE	4			/* Size of a level2 table entry */
#define ARM_VM_LVL2_SMALL		0xFFE		/* set entry for small page, each sub-page user RW, cache fully enabled */
#define	ARM_VM_LVL2_ADDR_MASK	0xFFFFF000	/* address should reside in bits 31:12 */

/* MVA translation (MVA is same as linear address in i386 world) */
#define ARM_VM_LVL1_ENT_SHIFT	20			/* Shift to get entry in LVL1 table */
#define ARM_VM_LVL2_ENT_SHIFT	12			/* Shift to get entry in LVL2 table */
#define ARM_VM_LVL2_ENT_MASK	0xFF		/* Mask to get entry in page table */

/* ARM paging 'functions' */
#define ARM_VM_LVL1E(v)	( (v) >> ARM_VM_LVL1_ENT_SHIFT)								/* Level 1 page entry (offset from base) */
#define ARM_VM_LVL2E(v)	(((v) >> ARM_VM_LVL2_ENT_SHIFT) & ARM_VM_LVL2_ENT_MASK)		/* Level 2 page entry (offset from base) */
#define ARM_VM_LVL2A(v)	( (v) & ARM_VM_LVL2_ADDR_MASK)								/* level 2 page address */

/* ARM MMU Fault Status (FS in CP15 Register 5) */
#define ARM_VM_AF1	0x01	/* alignment fault (address was misaligned) (NOTE: in this case, bit[1] is don't care, so 0x2 and 0x3 are also capable) */
#define ARM_VM_AF2	0x02	/* alignment fault (address was misaligned) (NOTE: in this case, bit[1] is don't care, so 0x2 and 0x3 are also capable) */
#define ARM_VM_AF3	0x03	/* alignment fault (address was misaligned) (NOTE: in this case, bit[1] is don't care, so 0x2 and 0x3 are also capable) */
#define ARM_VM_SF_T	0x05	/* Sect fault caused by translation (section does not exist) */
#define ARM_VM_PF_T	0x07	/* Page fault caused by translation (page does not exits) */
#define ARM_VM_SF_D	0x09	/* Sect fault caused by domain (no access or reserved) */
#define ARM_VM_PF_D	0x0B	/* Page fault caused by domain (no acces or reserved) */
#define ARM_VM_SF_P	0x0D	/* Sect fault caused by permission (access violation in section) */
#define ARM_VM_PF_P	0x0F	/* Page fault caused by permission (access violation in page) */
#define ARM_VM_SF_B	0x08	/* Sect fault caused by cahce */
#define ARM_VM_PF_B	0x0A	/* Page fault caused by cache */
