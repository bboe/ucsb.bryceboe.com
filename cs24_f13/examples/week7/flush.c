#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("Going to print dots now");
  if (argc > 1)
    printf(" with fflush\n");
  else
    printf(" without fflush\n");
  for (int i = 0; i < 3; ++i) {
    sleep(1);
    printf(".");
    if (argc > 1)
      fflush(stdout);
  }
  printf("\n");
  return 0;
}
