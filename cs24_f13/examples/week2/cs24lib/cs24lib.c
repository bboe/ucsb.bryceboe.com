#include "cs24lib.h"

/*
  These are the function definitions. They are required in order to actually
  perform the function call.

  A #include guard is not required in this file because `.c` files should not
  be included.
 */

void output_array(char **array, int n, FILE *outs) {
  if (outs == NULL)
    outs = stdout;
  for (int i = 0; i < n; ++i)
    fprintf(outs, "%d: %s\n", i, array[i]);
  fprintf(outs, "\n"); // Add an extra new line just because
}

/* Swap two pointers to pointers a and b */
void swap(void **a, void **b) {
  void *tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
