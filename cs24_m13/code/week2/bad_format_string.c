#include <stdio.h>


/* To see how this can be used maliciously run the program like:

   ./a.out "%d %d %d %d"

   The above will allow you to explore the memory locations from the printf
   function call. Passing in a "%n" will often result in a program crash.

*/


int main(int argc, char *argv[]) {
  if (argc == 2) {
    printf(argv[1]);
    printf("\n");
  }
  return 0;
}
