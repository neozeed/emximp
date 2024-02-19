/* getext2.c (emx+gcc) -- Copyright (c) 1993 by Eberhard Mattes */

#include <stdlib.h>
#include <string.h>

char *_getext2 (const char *path)
{
  char *p;

  p = _getext (path);
  return (p != NULL ? p : "");
}
