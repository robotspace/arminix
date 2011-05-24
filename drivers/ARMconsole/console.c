/* simple console driver for the ARM port, outputs everything to UART, 
* no formatting of whatsoever is done, this is the task for the console to
* which the ARMboard is connected to. */

#include "../drivers.h"
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/vm.h>
#include <sys/video.h>
#include <minix/tty.h>
#include <minix/callnr.h>
#include <minix/com.h>
#include <minix/sys_config.h>
#include "tty.h"
#include <sys/select.h>

typedef struct console {
  tty_t *c_tty;			/* associated TTY struct */
  int c_column;			/* current column number (0-origin) */
  int c_row;			/* current row (0 at top of screen) */
  int c_rwords;			/* number of WORDS (not bytes) in outqueue */
  unsigned c_start;		/* start of video memory of this console */
  unsigned c_limit;		/* limit of this console's video memory */
  unsigned c_org;		/* location in RAM where 6845 base points */
  unsigned c_cur;		/* current position of cursor in video RAM */
  unsigned c_attr;		/* character attribute */
  unsigned c_blank;		/* blank attribute */
  char c_reverse;		/* reverse video */
  char c_esc_state;		/* 0=normal, 1=ESC, 2=ESC[ */
  char c_esc_intro;		/* Distinguishing character following ESC */
  int *c_esc_parmp;		/* pointer to current escape parameter */
  int c_esc_parmv[MAX_ESC_PARMS];	/* list of escape parameters */
  u16_t c_ramqueue[CONS_RAM_WORDS];	/* buffer for video RAM */
  int c_line;			/* line no */
} console_t;

PRIVATE unsigned scr_width;	/* # characters on a line */
PRIVATE unsigned scr_lines;	/* # lines on the screen */
PRIVATE unsigned scr_size;	/* # characters on the screen */

PRIVATE int nr_cons= 1;		/* actual number of consoles */
PRIVATE console_t cons_table[NR_CONS];


FORWARD _PROTOTYPE( int cons_write, (struct tty *tp, int try)		);
FORWARD _PROTOTYPE( void cons_echo, (tty_t *tp, int c)			);
FORWARD _PROTOTYPE( void out_char, (console_t *cons, int c)		);
FORWARD _PROTOTYPE( void cons_putk, (int c)				);
FORWARD _PROTOTYPE( void ser_putc, (char c)				);

FORWARD _PROTOTYPE( int kb_read, (struct tty *tp, int try) 		);

#define KB_IN_BYTES	  32	/* size of keyboard input buffer */
PRIVATE char ibuf[KB_IN_BYTES];	/* input buffer */
PRIVATE char *ihead = ibuf;	/* next free spot in input buffer */
PRIVATE char *itail = ibuf;	/* scan code to return to TTY */
PRIVATE int icount;		/* # codes in buffer */


/*===========================================================================*
 *				cons_write				     *
 *===========================================================================*/
PRIVATE int cons_write(tp, try)
register struct tty *tp;	/* tells which terminal is to be used */
int try;
{
/* Copy as much data as possible to the output queue, then start I/O.  On
 * memory-mapped terminals, such as the IBM console, the I/O will also be
 * finished, and the counts updated.  Keep repeating until all I/O done.
 */

  int count;
  int result;
  register char *tbuf;
  char buf[64];
  console_t *cons = tp->tty_priv;

  if (try) return 1;	/* we can always write to console */

  /* Check quickly for nothing to do, so this can be called often without
   * unmodular tests elsewhere.
   */
  if ((count = tp->tty_outleft) == 0 || tp->tty_inhibited) return 0;

  /* Copy the user bytes to buf[] for decent addressing. Loop over the
   * copies, since the user buffer may be much larger than buf[].
   */
  do {
	if (count > sizeof(buf)) count = sizeof(buf);
	if(tp->tty_out_safe) {
	   if ((result = sys_safecopyfrom(tp->tty_outproc, tp->tty_out_vir_g,
		tp->tty_out_vir_offset, (vir_bytes) buf, count, D)) != OK)
		break;
	    tp->tty_out_vir_offset += count;
	} else {
	   if ((result = sys_vircopy(tp->tty_outproc, D, tp->tty_out_vir_g, 
			SELF, D, (vir_bytes) buf, (vir_bytes) count)) != OK)
		break;
	    tp->tty_out_vir_g += count;
	}
	tbuf = buf;

	/* Update terminal data structure. */
	tp->tty_outcum += count;
	tp->tty_outleft -= count;

	/* Output each byte of the copy to the screen.  Avoid calling
	 * out_char() for the "easy" characters, put them into the buffer
	 * directly.
	 */
	do {
		if ((unsigned) *tbuf < ' ' || cons->c_esc_state > 0
			|| cons->c_column >= scr_width
			|| cons->c_rwords >= buflen(cons->c_ramqueue))
		{
			out_char(cons, *tbuf++);
		} else {
			cons->c_ramqueue[cons->c_rwords++] =
					cons->c_attr | (*tbuf++ & BYTE);
			cons->c_column++;
		}
	} while (--count != 0);
  } while ((count = tp->tty_outleft) != 0 && !tp->tty_inhibited);

  /* Reply to the writer if all output is finished or if an error occured. */
  if (tp->tty_outleft == 0 || result != OK) {
	/* REVIVE is not possible. I/O on memory mapped consoles finishes. */
	tty_reply(tp->tty_outrepcode, tp->tty_outcaller, tp->tty_outproc,
							tp->tty_outcum);
	tp->tty_outcum = 0;
  }

  return 0;
}

/*===========================================================================*
 *				cons_echo				     *
 *===========================================================================*/
PRIVATE void cons_echo(tp, c)
register tty_t *tp;		/* pointer to tty struct */
int c;				/* character to be echoed */
{
  ser_putc(c);
}

/*===========================================================================*
 *				out_char				     *
 *===========================================================================*/
PRIVATE void out_char(cons, c)
register console_t *cons;	/* pointer to console struct */
int c;				/* character to be output */
{
/* Output a character on the console. */
  if (cons == &cons_table[0] && c != '\0')
  {
	if (c == '\n')
		ser_putc('\r');
	ser_putc(c);
  }
}

/*===========================================================================*
 *				scr_init				     *
 *===========================================================================*/
PUBLIC void scr_init(tp)
tty_t *tp;
{
/* Initialize the screen driver. */
  console_t *cons;
  u16_t bios_columns, bios_crtbase, bios_fontlines;
  u8_t bios_rows;
  int line;
  int s;
  static int vdu_initialized = 0;
  static unsigned page_size;

  /* Associate console and TTY. */
  line = tp - &tty_table[0];
  if (line >= nr_cons) return;
  cons = &cons_table[line];
  cons->c_tty = tp;
  cons->c_line = line;
  tp->tty_priv = cons;

  /* Fill in TTY function hooks. */
  tp->tty_devwrite = cons_write;
  tp->tty_echo = cons_echo;

  cons->c_start = line * page_size;
  cons->c_limit = cons->c_start + page_size;
  cons->c_cur = cons->c_org = cons->c_start;
  cons->c_attr = cons->c_blank = BLANK_COLOR;

}

/*===========================================================================*
 *				kputc					     *
 *===========================================================================*/
PUBLIC void kputc(c)
int c;
{
/* Accumulate a single character for a kernel message. Send a notification
 * the to output driver if an END_OF_KMESS is encountered. 
 */
	cons_putk(c);
  if (c != 0) {
      kmess.km_buf[kmess.km_next] = c;	/* put normal char in buffer */
      if (kmess.km_size < _KMESS_BUF_SIZE)
          kmess.km_size += 1;		
      kmess.km_next = (kmess.km_next + 1) % _KMESS_BUF_SIZE;
  } else {
      notify(LOG_PROC_NR);
  }
}

/*===========================================================================*
 *				do_new_kmess				     *
 *===========================================================================*/
PUBLIC void do_new_kmess(m)
message *m;
{
/* Notification for a new kernel message. */
  static struct kmessages kmess;		/* kmessages structure */
  static int prev_next = 0;			/* previous next seen */
  int bytes;
  int r;

  /* Try to get a fresh copy of the buffer with kernel messages. */
#if DEAD_CODE	
  /* During shutdown, the reply is garbled because new notifications arrive
   * while the system task makes a copy of the kernel messages buffer.
   * Hence, don't check the return value. 
   */
  if ((r=sys_getkmessages(&kmess)) != OK) {
  	printf("TTY: couldn't get copy of kmessages: %d, 0x%x\n", r,r);
  	return;
  }
#endif
  sys_getkmessages(&kmess);

  /* Print only the new part. Determine how many new bytes there are with 
   * help of the current and previous 'next' index. Note that the kernel
   * buffer is circular. This works fine if less then _KMESS_BUF_SIZE bytes
   * is new data; else we miss % _KMESS_BUF_SIZE here.  
   * Check for size being positive, the buffer might as well be emptied!
   */
  if (kmess.km_size > 0) {
      bytes = ((kmess.km_next + _KMESS_BUF_SIZE) - prev_next) % _KMESS_BUF_SIZE;
      r=prev_next;				/* start at previous old */ 
      while (bytes > 0) {			
          cons_putk( kmess.km_buf[(r%_KMESS_BUF_SIZE)] );
          bytes --;
          r ++;
      }
      cons_putk(0);			/* terminate to flush output */
  }

  /* Almost done, store 'next' so that we can determine what part of the
   * kernel messages buffer to print next time a notification arrives.
   */
  prev_next = kmess.km_next;
}

/*===========================================================================*
 *				do_diagnostics				     *
 *===========================================================================*/
PUBLIC void do_diagnostics(m_ptr, safe)
message *m_ptr;			/* pointer to request message */
int safe;
{
/* Print a string for a server. */
  char c;
  vir_bytes src;
  int count, offset = 0;
  int result = OK;
  int proc_nr = m_ptr->m_source;

  src = (vir_bytes) m_ptr->DIAG_PRINT_BUF_G;
  for (count = m_ptr->DIAG_BUF_COUNT; count > 0; count--) {
	int r;
	if(safe) {
	   r = sys_safecopyfrom(proc_nr, src, offset, (vir_bytes) &c, 1, D);
	   if(r != OK)
	  	   printf("<tty: proc %d, grant %ld>", proc_nr, src);
	} else {
	   r = sys_vircopy(proc_nr, D, src+offset, SELF, D, (vir_bytes) &c, 1);
	}
	offset++;
	if(r != OK) {
		result = EFAULT;
		break;
	}
	cons_putk(c);
  }
  cons_putk(0);			/* always terminate, even with EFAULT */

  if(m_ptr->m_type != ASYN_DIAGNOSTICS) {
	  m_ptr->m_type = DIAG_REPL;
	  m_ptr->REP_STATUS = result;
	  send(m_ptr->m_source, m_ptr);
  }
}

/*===========================================================================*
 *				do_get_kmess				     *
 *===========================================================================*/
PUBLIC void do_get_kmess(m_ptr)
message *m_ptr;			/* pointer to request message */
{
/* Provide the log device with debug output */
  vir_bytes dst;
  int r;

  dst = (vir_bytes) m_ptr->GETKM_PTR;
  r= OK;
  if (sys_vircopy(SELF, D, (vir_bytes)&kmess, m_ptr->m_source, D,
	dst, sizeof(kmess)) != OK) {
	r = EFAULT;
  }
  m_ptr->m_type = r;
  send(m_ptr->m_source, m_ptr);
}

/*===========================================================================*
 *				do_get_kmess_s				     *
 *===========================================================================*/
PUBLIC void do_get_kmess_s(m_ptr)
message *m_ptr;			/* pointer to request message */
{
/* Provide the log device with debug output */
  cp_grant_id_t gid;
  int r;

  gid = m_ptr->GETKM_GRANT;
  r= OK;
  if (sys_safecopyto(m_ptr->m_source, gid, 0, (vir_bytes)&kmess, sizeof(kmess),
	D) != OK) {
	r = EFAULT;
  }
  m_ptr->m_type = r;
  send(m_ptr->m_source, m_ptr);
}

/*===========================================================================*
 *				cons_putk				     *
 *===========================================================================*/
PRIVATE void cons_putk(c)
int c;				/* character to print */
{
	ser_putc(c);
}

#define APB_PHYS_BASE						0x80800000
#define UART1_BASE							(APB_PHYS_BASE + 0x000c0000)
#define	UART1_DATA							(*((volatile unsigned int *) (UART1_BASE)))
#define	UART1_FLAG							(*((volatile unsigned int *) (UART1_BASE + (0x018))))

PUBLIC void ser_putc(char c)
{
	int timeout;
	for (timeout = 0; timeout < 1000; timeout++) {
		if (!(UART1_FLAG & (1 << 5))) break;		/* check for TX FIFO Full flag */
	}
	UART1_DATA = c;	
}

/*===========================================================================*
 *				kb_init					     *
 *===========================================================================*/
PUBLIC void kb_init(tp)
tty_t *tp;
{
/* Initialize the keyboard driver. */

  tp->tty_devread = kb_read;	/* input function */
}

/*===========================================================================*
 *				kbd_interrupt				     *
 *===========================================================================*/
PUBLIC void kbd_interrupt(m_ptr)
message *m_ptr;
{
  /* A UART interrupt has occurred.  Process it. */
  unsigned char received = UART1_DATA;

  /* Store the character in memory so the task can get at it later. */
  if (icount < KB_IN_BYTES) {
	*ihead++ = received;
	if (ihead == ibuf + KB_IN_BYTES) ihead = ibuf;
	icount++;
	tty_table[ccurrent].tty_events = 1;
	if (tty_table[ccurrent].tty_select_ops & SEL_RD) {
		select_retry(&tty_table[ccurrent]);
	}
  }
}

/*===========================================================================*
 *				kb_read					     *
 *===========================================================================*/
PRIVATE int kb_read(tp, try)
tty_t *tp;
int try;
{
/* Process characters from the circular keyboard buffer. */
  char buf[3];
  int received;

  tp = &tty_table[ccurrent];		/* always use the current console */

  if (try) {
  	if (icount > 0) return 1;
  	return 0;
  }

  while (icount > 0) {
	received = *itail++;			/* take one character */
	if (itail == ibuf + KB_IN_BYTES) itail = ibuf;
	icount--;

	buf[0] = received;
	(void) in_process(tp, buf, 1);
  }
  return 1;
}

