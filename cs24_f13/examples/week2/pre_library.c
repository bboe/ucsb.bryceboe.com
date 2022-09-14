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
  void *tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  char *strings[] = {"This array simply contains some strings.",
                     "The quick brown fox jumps over the lazy dog.",
                     "Given good manners you will go far."};

  printf("The initial array: \n");
  output_array(strings, 3, NULL);
  swap((void**)&strings[0], (void**)&strings[1]);

  printf("The array after swapping the first and second element:\n");
  output_array(strings, 3, NULL);


  /* We can also swap other pointer-size values this way as the swap function
     we wrote is meant to handle pointers.
  */
  if (sizeof(int) == sizeof(void*)) { // 32 bit architecture
    int a = 128;
    int b = -64;
    printf("swap on type int works: sizeof(int) == sizeof(void*)\n");
    printf("a = %d, b = %d\n", a, b);
    swap((void**)&a, (void**)&b);
    printf("a = %d, b = %d\n", a, b);
  }
  if (sizeof(double) == sizeof(void*)) { // 64 bit architecture
    double a = 3.14159;
    double b = 1.61803;
    printf("swap on type double works: sizeof(double) == sizeof(void*)\n");
    printf("a = %f, b = %f\n", a, b);
    swap((void**)&a, (void**)&b);
    printf("a = %f, b = %f\n", a, b);
  }

  /* Note that attempting to swap types of a different size will not work
     as intended.
  */
  char c = 'c';
  char d = 'd';
  printf("swap on type char does not work: sizeof(char) != sizeof(void*)\n");
  printf("c = '%c', d = '%c'\n", c, d);
  swap((void**)&c, (void**)&d);
  printf("c = '%c', d = '%c'\n", c, d);

  return 0;
}
