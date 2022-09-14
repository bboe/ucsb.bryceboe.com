#include <stdio.h>

int main(int argc, char *argv[0]) {
  char msg[] = "hello";
  char buf[8];
  char msg2[] = "world";

  for (int i = 0; i < argc; ++i) {
    buf[i] = argv[i][0];
  }

  printf("%s\n", msg);

  for (int i = 0; i < argc; ++i) {
    printf("%c\n", buf[i]);
  }

  printf("%s\n", msg2);

  // To see the overflow run this program by entering more than 8 command line
  // arguments and notice that "hello" starts to get corrupted.

  return 0;
}
