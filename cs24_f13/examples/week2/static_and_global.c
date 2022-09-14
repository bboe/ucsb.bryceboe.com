#include <stdio.h>
#include <stdlib.h>


int counter = 0;

void global_count() {
  printf("global_count has been called %d time(s).\n", ++counter);
}

void static_count() {
  static int counter = 0;
  printf("static_count has been called %d time(s).\n", ++counter);
}


int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: a.out global_count static_count\n");
    return 1;
  }

  for (int i = 0; i < atoi(argv[1]); ++i)
    global_count();

  for (int i = 0; i < atoi(argv[2]); ++i)
    static_count();

  printf("global counter: %d\n", counter);
}
