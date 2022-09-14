#include <stdio.h>
#include <stdlib.h>


/* Allocates and writes NUM characters to a buffer followed by a '\0'.
   The '\0' is written to "invalid" memory that valrind will catch.

   Compile via `clang memoryleak.c`
   Run via `valgrind -q --leak-check=full ./a.out 10`
 */

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: a.out NUM\n");
    return 1;
  }
  int num = atoi(argv[1]);

  // Needs to be dynamically allocated for valgrind to report an error
  char *buf = malloc(sizeof(char) * num);

  for (int i = 0; i < num; ++i)
    buf[i] = 0x43 + i;

  buf[num] = '\0';

  printf("%s\n", buf);
  free(buf);
  return 0;
}
