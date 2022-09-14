#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: ./a.out NUM\n");
    return 1;
  }
  int num = atoi(argv[1]);

  if (num > 0) {
    int a = 100;
  }
  if (num > 1) {
    int b = 200;
  }
  if (num > 2) {
    int c = 300;
  }
  if (num > 3) {
    int d = 400;
  }
  if (num > 4) {
    int e = 500;
  }

  int tmp[] = {-1};

  printf("Address of num: 0x%08x\n", (int)&num);
  printf("Address of tmp: 0x%08x\n", (int)&tmp);
  printf("Difference: %d bytes\n", (int)&num - (int)&tmp);

  for (int i = 0; i < 7; ++i)
    printf("tmp[%d] = %d\n", i, tmp[i]);
}
