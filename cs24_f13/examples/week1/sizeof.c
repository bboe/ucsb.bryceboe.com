#include <stdio.h>

int main() {

  char c, *pc;
  int i, *pi;

  char *str = "foosdflkjsdflksj";
  char str_ar[] = "foosdflkjsdflksj";
  int int_ar[] = {1, 2, 3, 4, 0x10, 16, -1};

  char tmp[] = {'A', 'a', 0xFF, 0x143};

  int int_size = sizeof(int);
  printf("Int size: %d bytes\n", int_size);
  printf("Char size: %u bytes\n", sizeof(char));
  printf("pointer size: %u bytes\n", sizeof(str));
  printf("array size: %u bytes\n", sizeof(str_ar));
  printf("array size: %u bytes\n", sizeof(int_ar));


  for (int i = 0; i < 4; ++i) {
    printf("tmp[%d]: %c %x\n", i, tmp[i], tmp[i]);
  }

  return 0;
}
