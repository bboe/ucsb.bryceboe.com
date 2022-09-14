#include "cs24lib.c"


/* NOTE: We did not convert this extension library to the proper format (using
   a .h file). `.c` files should NEVER be included.
 */

/* Like output_array from cs24lib, but can output a partial array. */
void advanced_output_array(char **array, int start, int n, FILE *outs) {
  output_array(&array[start], n, outs);
}

/* Like swap, but log the addresses that are swapped */
void logging_swap(void **a, void **b) {
  printf("Swaping address 0x%08x with 0x%08x\n", (unsigned int)*a,
         (unsigned int)*b);
  swap(a, b);
}
