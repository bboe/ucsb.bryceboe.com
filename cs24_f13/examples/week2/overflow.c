#include <stdio.h>

/* As we provide more command line arguments, we overflow `buf`.

   First run via: ./a.out

   Then run via: ./a.out a a a a a a a N E A T O

   In the later example, the "hello" printed at the top is replaed.
*/

void foo(int argc, char **argv) {
  char msg[] = "hello";
  char buf[8];
  char msg2[] = "world";

  // Update buf[i] with the first character if the ith command-line arugment
  for (int i = 0; i < argc; ++i) {
    buf[i] = argv[i][0];
  }
  printf("Begin\n");

  printf("%s\n", msg);

  for (int i = 0; i < argc; ++i) {
    printf("%c\n", buf[i]);
  }

  printf("%s\n", msg2);

}

int main(int argc, char *argv[0]) {
  foo(argc, argv);
  return 0;
}
