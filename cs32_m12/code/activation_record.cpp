#include <stdio.h>
#include <stdlib.h>

#if defined __clang__
#define ADDR 0x08048430
#define OFFSET 12
#else
#define ADDR 0x08048454
#define OFFSET 14
#endif

void unreachable() {
  printf("This is never called\n");
  exit(1);
}

void main2(int some_addr) {
  int array[] = {0, 1, 2, 3, 4};
  int sum_array[] = {5, 6, 7, 8, 9};
  int i;

  printf("Before\n");
  for (i = 22; i >= -1; --i) {
    printf("%2d 0x%08x ", i, sum_array[i]);
    if (i == OFFSET) {
      sum_array[i] = some_addr;
      printf("+");
    }
    else
      printf(" ");
    printf("0x%08x\n", sum_array[i]);
  }
}


int main() {
  int marker = 0xDEADBEEF;
  main2(ADDR);
  return marker;
}
