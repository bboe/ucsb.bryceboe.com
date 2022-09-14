#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: copy src dst\n");
    return 1;
  }

  FILE *src;
  if (!(src = fopen(argv[1], "r"))) {
    perror("Cannot open src");
    return 1;
  }

  FILE *dst;
  if (!(dst = fopen(argv[2], "w"))) {
    perror("Cannot open dst");
    return 1;
  }

  int read;

  fseek(src, 5, 0);

  while((read = fgetc(src)) != EOF)
    fputc(read, dst);


  return 0;
}
