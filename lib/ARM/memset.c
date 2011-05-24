/*
FUNCTION
	<<memset>>---set an area of memory

INDEX
	memset

ANSI_SYNOPSIS
	#include <string.h>
	void *memset(void *<[dst]>, int <[c]>, size_t <[length]>);

TRAD_SYNOPSIS
	#include <string.h>
	void *memset(<[dst]>, <[c]>, <[length]>)
	void *<[dst]>;
	int <[c]>;
	size_t <[length]>;

DESCRIPTION
	This function converts the argument <[c]> into an unsigned
	char and fills the first <[length]> characters of the array
	pointed to by <[dst]> to the value.

RETURNS
	<<memset>> returns the value of <[dst]>.

PORTABILITY
<<memset>> is ANSI C.

    <<memset>> requires no supporting OS subroutines.

QUICKREF
	memset ansi pure
*/

#include <string.h>

#define LBLOCKSIZE (sizeof(long))
#define UNALIGNED(X)   ((long)X & (LBLOCKSIZE - 1))
#define TOO_SMALL(LEN) ((LEN) < LBLOCKSIZE)

void *memset (void *_s, int _c, size_t _n)
{
  char *s = (char *) _s;
  int i;
  unsigned long buffer;
  unsigned long *aligned_addr;
  unsigned int d = _c & 0xff;	/* To avoid sign extension, copy C to an
				   unsigned variable.  */

  while (UNALIGNED (s))
    {
      if (_n--)
        *s++ = (char) _c;
      else
        return _s;
    }

  if (!TOO_SMALL (_n))
    {
      /* If we get this far, we know that n is large and s is word-aligned. */
      aligned_addr = (unsigned long *) s;

      /* Store D into each char sized location in BUFFER so that
         we can set large blocks quickly.  */
      buffer = (d << 8) | d;
      buffer |= (buffer << 16);
      for (i = 32; i < LBLOCKSIZE * 8; i <<= 1)
        buffer = (buffer << i) | buffer;

      /* Unroll the loop.  */
      while (_n >= LBLOCKSIZE*4)
        {
          *aligned_addr++ = buffer;
          *aligned_addr++ = buffer;
          *aligned_addr++ = buffer;
          *aligned_addr++ = buffer;
          _n -= 4*LBLOCKSIZE;
        }

      while (_n >= LBLOCKSIZE)
        {
          *aligned_addr++ = buffer;
          _n -= LBLOCKSIZE;
        }
      /* Pick up the remainder with a bytewise loop.  */
      s = (char*)aligned_addr;
    }
  while (_n--)
    *s++ = (char) _c;

  return _s;
}
