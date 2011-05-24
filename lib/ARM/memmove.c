/*
FUNCTION
	<<memmove>>---move possibly overlapping memory

INDEX
	memmove

ANSI_SYNOPSIS
	#include <string.h>
	void *memmove(void *<[dst]>, const void *<[src]>, size_t <[_n]>);

TRAD_SYNOPSIS
	#include <string.h>
	void *memmove(<[dst]>, <[src]>, <[_n]>)
	void *<[dst]>;
	void *<[src]>;
	size_t <[_n]>;

DESCRIPTION
	This function moves <[_n]> characters from the block of
	memory starting at <<*<[src]>>> to the memory starting at
	<<*<[dst]>>>. <<memmove>> reproduces the characters correctly
	at <<*<[dst]>>> even if the two areas overlap.


RETURNS
	The function returns <[dst]> as passed.

PORTABILITY
<<memmove>> is ANSI C.

<<memmove>> requires no supporting OS subroutines.

QUICKREF
	memmove ansi pure
*/

#include <string.h>
#include <ansi.h>
#include <stddef.h>
#include <limits.h>

/* Nonzero if either X or Y is not aligned on a "long" boundary.  */
#define UNALIGNED(X, Y) \
  (((long)X & (sizeof (long) - 1)) | ((long)Y & (sizeof (long) - 1)))

/* How many bytes are copied each iteration of the 4X unrolled loop.  */
#define BIGBLOCKSIZE    (sizeof (long) << 2)

/* How many bytes are copied each iteration of the word copy loop.  */
#define LITTLEBLOCKSIZE (sizeof (long))

/* Threshhold for punting to the byte copier.  */
#define TOO_SMALL(LEN)  ((LEN) < BIGBLOCKSIZE)

/*SUPPRESS 20*/
void *memmove (void *_s1, const void *_s2, size_t _n)
{
  char *dst = _s1;
  _CONST char *src = _s2;
  long *aligned_dst;
  _CONST long *aligned_src;
  int   len =  _n;

  if (src < dst && dst < src + len)
    {
      /* Destructive overlap...have to copy backwards */
      src += len;
      dst += len;
      while (len--)
	{
	  *--dst = *--src;
	}
    }
  else
    {
      /* Use optimizing algorithm for a non-destructive copy to closely 
         match memcpy. If the size is small or either SRC or DST is unaligned,
         then punt into the byte copy loop.  This should be rare.  */
      if (!TOO_SMALL(len) && !UNALIGNED (src, dst))
        {
          aligned_dst = (long*)dst;
          aligned_src = (long*)src;

          /* Copy 4X long words at a time if possible.  */
          while (len >= BIGBLOCKSIZE)
            {
              *aligned_dst++ = *aligned_src++;
              *aligned_dst++ = *aligned_src++;
              *aligned_dst++ = *aligned_src++;
              *aligned_dst++ = *aligned_src++;
              len -= BIGBLOCKSIZE;
            }

          /* Copy one long word at a time if possible.  */
          while (len >= LITTLEBLOCKSIZE)
            {
              *aligned_dst++ = *aligned_src++;
              len -= LITTLEBLOCKSIZE;
            }

          /* Pick up any residual with a byte copier.  */
          dst = (char*)aligned_dst;
          src = (char*)aligned_src;
        }

      while (len--)
        {
          *dst++ = *src++;
        }
    }

  return _s1;
}
