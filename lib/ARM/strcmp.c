/*
FUNCTION
	<<strcmp>>---character string compare
	
INDEX
	strcmp

ANSI_SYNOPSIS
	#include <string.h>
	int strcmp(const char *<[a]>, const char *<[b]>);

TRAD_SYNOPSIS
	#include <string.h>
	int strcmp(<[a]>, <[b]>)
	char *<[a]>;
	char *<[b]>;

DESCRIPTION
	<<strcmp>> compares the string at <[a]> to
	the string at <[b]>.

RETURNS
	If <<*<[a]>>> sorts lexicographically after <<*<[b]>>>,
	<<strcmp>> returns a number greater than zero.  If the two
	strings match, <<strcmp>> returns zero.  If <<*<[a]>>>
	sorts lexicographically before <<*<[b]>>>, <<strcmp>> returns a
	number less than zero.

PORTABILITY
<<strcmp>> is ANSI C.

<<strcmp>> requires no supporting OS subroutines.

QUICKREF
	strcmp ansi pure
*/

#include <string.h>
#include <limits.h>

/* Nonzero if either X or Y is not aligned on a "long" boundary.  */
#define UNALIGNED(X, Y) (((long)X & (sizeof (long) - 1)) | ((long)Y & (sizeof (long) - 1)))
#define DETECTNULL(X) (((X) - 0x01010101) & ~(X) & 0x80808080)

int strcmp(const char *_s1, const char *_s2)
{ 
  unsigned long *a1;
  unsigned long *a2;

  /* If s1 or s2 are unaligned, then compare bytes. */
  if (!UNALIGNED (_s1, _s2))
    {  
      /* If s1 and s2 are word-aligned, compare them a word at a time. */
      a1 = (unsigned long*)_s1;
      a2 = (unsigned long*)_s2;
      while (*a1 == *a2)
        {
          /* To get here, *a1 == *a2, thus if we find a null in *a1,
	     then the strings must be equal, so return zero.  */
          if (DETECTNULL (*a1))
	    return 0;

          a1++;
          a2++;
        }

      /* A difference was detected in last few bytes of s1, so search bytewise */
      _s1 = (char*)a1;
      _s2 = (char*)a2;
    }

  while (*_s1 != '\0' && *_s1 == *_s2)
    {
      _s1++;
      _s2++;
    }
  return (*(unsigned char *) _s1) - (*(unsigned char *) _s2);
}
