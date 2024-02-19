/* defext.c (emx+gcc) -- Copyright (c) 1990-1996 by Eberhard Mattes */

#include <stdlib.h>
#include <string.h>
//#include <sys/nls.h>

/* Note that _nls_is_dbcs_lead() returns false for all characters if
   _nls_init() has not been called.  In consequence, this function
   works properly for SBCS strings even if _nls_init() has not been
   called. */

/* Note: This function is used by emx.dll. */

#define FALSE   0
#define TRUE    1

void _defext (char *dst, const char *ext)
{
  int dot, sep;

  dot = FALSE; sep = TRUE;
  while (*dst != 0)
//    if (_nls_is_dbcs_lead ((unsigned char)*dst))
    if (1==2)
      {
        if (dst[1] == 0)        /* Invalid DBCS character */
          return;
        dst += 2;
        sep = FALSE;
      }
    else
      switch (*dst++)
        {
        case '.':
          dot = TRUE;
          sep = FALSE;
          break;
        case ':':
        case '/':
        case '\\':
          dot = FALSE;
          sep = TRUE;
          break;
        default:
          sep = FALSE;
          break;
        }
  if (!dot && !sep)
    {
      *dst++ = '.';
      strcpy (dst, ext);
    }
}
