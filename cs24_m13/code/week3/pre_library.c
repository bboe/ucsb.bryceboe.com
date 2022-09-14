#include <stdio.h>

/* This code demonstrates a program before the functions are converted into a
   library. */

/* Output an array of C-strings, numbered with one per line.

   Assumes the C-string does not span multiple lines.

   :param array: The array of C-strings
   :param n: The number of elements in array
   :param outs: A writable output stream to output the contents of the array
       to. If outs is NULL, write to stdout.
 */
void output_array(char **array, int n, FILE *outs) {
  if (outs == NULL)
    outs = stdout;
  for (int i = 0; i < n; ++i)
    fprintf(outs, "%d: %s\n", i, array[i]);
  fprintf(outs, "\n"); // Add an extra new line just because
}

/* Swap two pointers a and b */
void swap(void **a, void **b) {
  void *tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  char *strings[] = {"This array simply contains some strings.",
                     "The quick brown fox jumps over the lazy dog.",
                     "Given good manners you will go far."};
  printf("The initial array\n");
  output_array(strings, 3, NULL);
  swap((void*)&strings[0], (void*)&strings[1]);
  printf("The array after swapping the first and second element\n");
  output_array(strings, 3, NULL);
}
