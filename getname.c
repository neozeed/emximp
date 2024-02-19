/* getname.c (emx+gcc) -- Copyright (c) 1993-1996 by Eberhard Mattes */

#include <stdlib.h>
#include <string.h>
//#include <sys/nls.h>

/* Note that _nls_is_dbcs_lead() returns false for all characters if
   _nls_init() has not been called.  In consequence, this function
   works properly for SBCS strings even if _nls_init() has not been
   called. */

/* Note: This function is used by emx.dll. */

char *_getname (const char *path)
{
  const char *p;

  p = path;
  while (*path != 0)
      switch (*path++)
        {
        case ':':
        case '/':
        case '\\':
          p = path;             /* Note that PATH has been incremented */
          break;
        }
  return (char *)p;
}
