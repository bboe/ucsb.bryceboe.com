#include <stdio.h>
#include "point.h"

/* This file provides the implementation for the functions declared in point.h.

   Note that this code can be compiled independently in such a manor that does
   not produce an executable by running:

   clang -c point.c

   This will produce point.o which can be used in the compilation of main
   instead of point.c (saves a little work if this file does not often change.
*/

void point_output(struct Point *point, FILE *stream) {
  fprintf(stream, "(%d, %d)\n", point->x, point->y);
}
