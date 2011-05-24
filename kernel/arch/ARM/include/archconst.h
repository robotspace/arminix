/* Program Status Words */
#define INIT_PSW     			0x600000df    /* initial psw */
#define INIT_TASK_PSW 	0x6000005f    /* initial psw for tasks (with interrupts enabled)*/

/* interrupt stuff */
#define NR_IRQ_VECTORS 64
#define	CLOCK_IRQ	35

/* fancy stuff for the banner */
#define _SVN_REVISION "for ARM, last build: "__DATE__" "__TIME__

/* other stuff that ARM does not have, but Minix does use outside of arch specific code */
 /* needed for system/do_trace.c */
#define TRACEBIT      0x0  
#define SETPSW(rp, new)    ((rp)->p_reg.psw = new)     /* permits only certain bits to be set */

/* Privileges. */
#define INTR_PRIVILEGE       0	/* kernel and interrupt handlers */
#define TASK_PRIVILEGE       1	/* kernel tasks */
#define USER_PRIVILEGE       3	/* servers and user processes */
