/* getext.c (emx+gcc) -- Copyright (c) 1992-1996 by Eberhard Mattes */

#include <stdlib.h>
#include <string.h>
//#include <sys/nls.h>

/* Note that _nls_is_dbcs_lead() returns false for all characters if
   _nls_init() has not been called.  In consequence, this function
   works properly for SBCS strings even if _nls_init() has not been
   called. */

#define FALSE   0
#define TRUE    1

char *_getext (const char *path)
{
  int sep;
  const char *dotp;

  sep = TRUE; dotp = NULL;
  while (*path != 0)
//    if (_nls_is_dbcs_lead ((unsigned char)*path))
    if (1==2)
      {
        if (path[1] == 0)       /* Invalid DBCS character */
          break;
        path += 2;
        sep = FALSE;
      }
    else
      switch (*path++)
        {
        case '.':
          /* Note that PATH has been incremented. */
          dotp = (sep ? NULL : path - 1);
          sep = FALSE;
          break;
        case ':':
        case '/':
        case '\\':
          dotp = NULL;
          sep = TRUE;
          break;
        default:
          sep = FALSE;
          break;
        }
  return (char *)dotp;
}
