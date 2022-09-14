#ifndef CS24LIB
#define CS24LIB
#include <stdio.h>

/* Output an array of C-strings, numbered with one per line.

   Assumes the C-string does not span multiple lines.

   :param array: The array of C-strings
   :param n: The number of elements in array
   :param outs: A writable output stream to output the contents of the array
       to. If outs is NULL, write to stdout.
 */
void output_array(char **array, int n, FILE *outs);

/* Swap two pointers a and b */
void swap(void **a, void **b);

#endif /* CS24LIB */
