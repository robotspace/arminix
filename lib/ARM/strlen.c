/*
FUNCTION
	<<strlen>>---character string length

INDEX
	strlen

ANSI_SYNOPSIS
	#include <string.h>
	size_t strlen(const char *<[str]>);

TRAD_SYNOPSIS
	#include <string.h>
	size_t strlen(<[str]>)
	char *<[src]>;

DESCRIPTION
	The <<strlen>> function works out the length of the string
	starting at <<*<[str]>>> by counting chararacters until it
	reaches a <<NULL>> character.

RETURNS
	<<strlen>> returns the character count.

PORTABILITY
<<strlen>> is ANSI C.

<<strlen>> requires no supporting OS subroutines.

QUICKREF
	strlen ansi pure
*/

#include <ansi.h>
#include <string.h>
#include <limits.h>

#define LBLOCKSIZE   (sizeof (long))
#define UNALIGNED(X) ((long)X & (LBLOCKSIZE - 1))
#define DETECTNULL(X) (((X) - 0x01010101) & ~(X) & 0x80808080)

size_t strlen(const char *_s)
{
  const char *start = _s;

#if !defined(PREFER_SIZE_OVER_SPEED) && !defined(__OPTIMIZE_SIZE__)
  unsigned long *aligned_addr;

  /* Align the pointer, so we can search a word at a time.  */
  while (UNALIGNED (_s))
    {
      if (!*_s)
	return _s - start;
      _s++;
    }

  /* If the string is word-aligned, we can check for the presence of
     a null in each word-sized block.  */
  aligned_addr = (unsigned long *)_s;
  while (!DETECTNULL (*aligned_addr))
    aligned_addr++;

  /* Once a null is detected, we check each byte in that block for a
     precise position of the null.  */
  _s = (char *) aligned_addr;

#endif /* not PREFER_SIZE_OVER_SPEED */

  while (*_s)
    _s++;
  return _s - start;
}
