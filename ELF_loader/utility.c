#include <stdarg.h>
#include <unistd.h>
#include "EP93xx.h"

#define END_OF_KMESS 	-1

void kputc(int c);
void ser_putc(char c);
void printf(const char *fmt, ...);
void panic(const char *mess, int nr);

/*===========================================================================*
 *				printf					     *
 *===========================================================================*/
void printf(const char *fmt, ...) 	/* format to be printed */
{
  int c;					/* next character in fmt */
  int d;
  unsigned long u;				/* hold number argument */
  int base;					/* base of number arg */
  int negative;					/* print minus sign */
  static char x2c[] = "0123456789ABCDEF";	/* nr conversion table */
  char ascii[8 * sizeof(long) / 3 + 2];		/* string for ascii number */
  char *s;					/* string to be printed */
  va_list argp;					/* optional arguments */
 
  va_start(argp, fmt);				/* init variable arguments */

  while((c=*fmt++) != 0) {

      if (c == '%') {				/* expect format '%key' */
	  negative = 0;				/* (re)initialize */
	  s = NULL;				/* (re)initialize */
          switch(c = *fmt++) {			/* determine what to do */

          /* Known keys are %d, %u, %x, %s, and %%. This is easily extended 
           * with number types like %b and %o by providing a different base.
           * Number type keys don't set a string to 's', but use the general
           * conversion after the switch statement.
           */ 
          case 'd':				/* output decimal */
              d = va_arg(argp, signed int);
              if (d < 0) { negative = 1; u = -d; }  else { u = d; }
              base = 10;
              break;
          case 'u':				/* output unsigned long */
              u = va_arg(argp, unsigned long);
              base = 10;
              break;
		  case 'X':
          case 'x':				/* output hexadecimal */
              u = va_arg(argp, unsigned long);
              base = 0x10;
              break;
          case 's': 				/* output string */
              s = va_arg(argp, char *);
              if (s == NULL) s = "(null)";
              break;
          case '%':				/* output percent */
              s = "%";				 
              break;			

          /* Unrecognized key. */
          default:				/* echo back %key */
              s = "%?";				
              s[1] = c;				/* set unknown key */
          }

          /* Assume a number if no string is set. Convert to ascii. */
          if (s == NULL) {
              s = ascii + sizeof(ascii)-1;
              *s = 0;			
              do {  *--s = x2c[(u % base)]; }	/* work backwards */
              while ((u /= base) > 0); 
          }

          /* This is where the actual output for format "%key" is done. */
          if (negative) ser_putc('-');  		/* print sign if negative */
          while(*s != 0) { ser_putc(*s++); }	/* print string/ number */
      }
      else {
          ser_putc(c);				/* print and continue */
      }
  }
//  kputc(END_OF_KMESS);				/* terminate output */
  va_end(argp);					/* end variable arguments */
}

void ser_putc(char c)
{
	int i;

	for (i = 0; i < 1000; i++) {
		if (!(UART1_FLAG & (1 << 5))) break;		/* check for TX FIFO Full flag */
	}
	UART1_DATA = c;
	return;
}
