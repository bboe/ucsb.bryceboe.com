#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("argc <-- %d\n", argc);
  printf("argv <-- {\n");


  /* Easier to read version of the loop */
  for (int i = 0; i < argc; ++i) {
    printf("          %s,\n", argv[i]);
  }

  printf("---\n");

  /* This loop is destructive, otherwise does the same */
  while (argc--)
    printf("          %s,\n", *argv++);  // Precedence: *(argv++)

  printf("         }\n");
  return 0;
}
