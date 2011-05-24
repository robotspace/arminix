/*
FUNCTION
	<<strncpy>>---_ned copy string

INDEX
	strncpy

ANSI_SYNOPSIS
	#include <string.h>
	char *strncpy(char *<[dst]>, const char *<[src]>, size_t <[length]>);

TRAD_SYNOPSIS
	#include <string.h>
	char *strncpy(<[dst]>, <[src]>, <[length]>)
	char *<[dst]>;
	char *<[src]>;
	size_t <[length]>;

DESCRIPTION
	<<strncpy>> copies not more than <[length]> characters from the
	the string pointed to by <[src]> (including the terminating
	null character) to the array pointed to by <[dst]>.  If the
	string pointed to by <[src]> is shorter than <[length]>
	characters, null characters are appended to the destination
	array until a total of <[length]> characters have been
	written.

RETURNS
	This function returns the initial value of <[dst]>.

PORTABILITY
<<strncpy>> is ANSI C.

<<strncpy>> requires no supporting OS subroutines.

QUICKREF
	strncpy ansi pure
*/

#include <string.h>

/*SUPPRESS 560*/
/*SUPPRESS 530*/

/* Nonzero if either X or Y is not aligned on a "long" boundary.  */
#define UNALIGNED(X, Y) (((long)X & (sizeof (long) - 1)) | ((long)Y & (sizeof (long) - 1)))
#define DETECTNULL(X) (((X) - 0x01010101) & ~(X) & 0x80808080)
#define TOO_SMALL(LEN) ((LEN) < sizeof (long))

char *strncpy(char *_s1, const char *_s2, size_t _n)
{
  char *dst = _s1;
  const char *src = _s2;
  long *aligned_dst;
  const long *aligned_src;

  /* If SRC and DEST is aligned and _n large enough, then copy words.  */
  if (!UNALIGNED (src, dst) && !TOO_SMALL (_n))
    {
      aligned_dst = (long*)dst;
      aligned_src = (long*)src;

      /* SRC and DEST are both "long int" aligned, try to do "long int"
	 sized copies.  */
      while (_n >= sizeof (long int) && !DETECTNULL(*aligned_src))
	{
	  _n -= sizeof (long int);
	  *aligned_dst++ = *aligned_src++;
	}

      dst = (char*)aligned_dst;
      src = (char*)aligned_src;
    }

  while (_n > 0)
    {
      --_n;
      if ((*dst++ = *src++) == '\0')
	break;
    }

  while (_n-- > 0)
    *dst++ = '\0';

  return _s1;
}
