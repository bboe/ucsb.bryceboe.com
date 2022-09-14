#ifndef CS24LIB_H
#define CS24LIB_H
#include <stdio.h>

/* The following are the function declarations.

   Function declarations are all that is needed during the compilation step
   (not linking step) so that calls to these functions can be prepared. The
   compiler need only know what the types are of function parameters and their
   return values to determine how to set-up the function call.
 */

void output_array(char **array, int n, FILE *outs);
void swap(void **a, void **b);

#endif /* CS24LIB_H */
