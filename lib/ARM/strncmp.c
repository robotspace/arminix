/*
FUNCTION
	<<strncmp>>---character string compare
	
INDEX
	strncmp

ANSI_SYNOPSIS
	#include <string.h>
	int strncmp(const char *<[a]>, const char * <[b]>, size_t <[length]>);

TRAD_SYNOPSIS
	#include <string.h>
	int strncmp(<[a]>, <[b]>, <[length]>)
	char *<[a]>;
	char *<[b]>;
	size_t <[length]>

DESCRIPTION
	<<strncmp>> compares up to <[length]> characters
	from the string at <[a]> to the string at <[b]>.

RETURNS
	If <<*<[a]>>> sorts lexicographically after <<*<[b]>>>,
	<<strncmp>> returns a number greater than zero.  If the two
	strings are equivalent, <<strncmp>> returns zero.  If <<*<[a]>>>
	sorts lexicographically before <<*<[b]>>>, <<strncmp>> returns a
	number less than zero.

PORTABILITY
<<strncmp>> is ANSI C.

<<strncmp>> requires no supporting OS subroutines.

QUICKREF
	strncmp ansi pure
*/

#include <string.h>
#include <limits.h>

/* Nonzero if either X or Y is not aligned on a "long" boundary.  */
#define UNALIGNED(X, Y) \
  (((long)X & (sizeof (long) - 1)) | ((long)Y & (sizeof (long) - 1)))

/* DETECTNULL returns nonzero if (long)X contains a NULL byte. */

#define DETECTNULL(X) (((X) - 0x01010101) & ~(X) & 0x80808080)

int strncmp(const char *_s1, const char *_s2, size_t _n)
{
  unsigned long *a1;
  unsigned long *a2;

  if (_n == 0)
    return 0;

  /* If s1 or s2 are unaligned, then compare bytes. */
  if (!UNALIGNED (_s1, _s2))
    {
      /* If s1 and s2 are word-aligned, compare them a word at a time. */
      a1 = (unsigned long*)_s1;
      a2 = (unsigned long*)_s2;
      while (_n >= sizeof (long) && *a1 == *a2)
        {
          _n -= sizeof (long);

          /* If we've run out of bytes or hit a null, return zero
	     since we already know *a1 == *a2.  */
          if (_n == 0 || DETECTNULL (*a1))
	    return 0;

          a1++;
          a2++;
        }

      /* A difference was detected in last few bytes of s1, so search bytewise */
      _s1 = (char*)a1;
      _s2 = (char*)a2;
    }

  while (_n-- > 0 && *_s1 == *_s2)
    {
      /* If we've run out of bytes or hit a null, return zero
	 since we already know *s1 == *s2.  */
      if (_n == 0 || *_s1 == '\0')
	return 0;
      _s1++;
      _s2++;
    }
  return (*(unsigned char *) _s1) - (*(unsigned char *) _s2);
}
