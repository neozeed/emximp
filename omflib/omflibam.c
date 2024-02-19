/* omflibam.c (emx+gcc) -- Copyright (c) 1993-1996 by Eberhard Mattes */

/* Add an OBJ module to an OMFLIB. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "omflib0.h"
#include <sys/omflib.h>

int omflib_add_module (struct omflib *p, const char *fname, char *error)
{
  FILE *f;
  char name[256];
  char obj_fname[256+4];
  int ret;

  omflib_module_name (name, fname);
  strcpy (obj_fname, fname);
  _defext (obj_fname, "obj");
  f = fopen (obj_fname, "rb");
  if (f == NULL)
    return omflib_set_error (error);
  ret = omflib_copy_module (p, p->f, NULL, f, name, error);
  fclose (f);
  return ret;
}
