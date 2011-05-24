/*
FUNCTION
	<<strcpy>>---copy string

INDEX
	strcpy

ANSI_SYNOPSIS
	#include <string.h>
	char *strcpy(char *<[dst]>, const char *<[src]>);

TRAD_SYNOPSIS
	#include <string.h>
	char *strcpy(<[dst]>, <[src]>)
	char *<[dst]>;
	char *<[src]>;

DESCRIPTION
	<<strcpy>> copies the string pointed to by <[src]>
	(including the terminating null character) to the array
	pointed to by <[dst]>.

RETURNS
	This function returns the initial value of <[dst]>.

PORTABILITY
<<strcpy>> is ANSI C.

<<strcpy>> requires no supporting OS subroutines.

QUICKREF
	strcpy ansi pure
*/

#include <string.h>
#include <limits.h>

/*SUPPRESS 560*/
/*SUPPRESS 530*/

/* Nonzero if either X or Y is not aligned on a "long" boundary.  */
#define UNALIGNED(X, Y) (((long)X & (sizeof (long) - 1)) | ((long)Y & (sizeof (long) - 1)))
#define DETECTNULL(X) (((X) - 0x01010101) & ~(X) & 0x80808080)

char* strcpy(char *_s1, const char *_s2)
{
  char *dst = _s1;
  _CONST char *src = _s2;
  long *aligned_dst;
  _CONST long *aligned_src;

  /* If SRC or DEST is unaligned, then copy bytes.  */
  if (!UNALIGNED (src, dst))
    {
      aligned_dst = (long*)dst;
      aligned_src = (long*)src;

      /* SRC and DEST are both "long int" aligned, try to do "long int"
         sized copies.  */
      while (!DETECTNULL(*aligned_src))
        {
          *aligned_dst++ = *aligned_src++;
        }

      dst = (char*)aligned_dst;
      src = (char*)aligned_src;
    }

  while ((*dst++ = *src++))
    ;
  return _s1;
}
