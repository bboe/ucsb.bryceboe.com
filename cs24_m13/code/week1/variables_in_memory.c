#include <stdio.h>
#include <stdlib.h>

void output_address(char *name, void *data) {
  printf("0x%08x %s\n", (int)data, name);
}

void another_function() {
  char buf[16];
  char buf2[4];
  output_address("another_function: buf", buf);
  output_address("another_function: buf2", buf2);
}

void some_function(int a, int b) {
  output_address("some_function: a", &a);
  output_address("some_function: b", &b);
  another_function();
}

int main(int argc, char *argv[]) {
  char buf[16];
  char buf2[4];
  output_address("main: argc", &argc);
  output_address("main: argv", &argv);

  output_address("main: buf", buf);
  output_address("main: buf2", buf2);
  for (int i = 0; i < argc; ++i)
    if (i == 0)
      output_address("main: i", &i);

  some_function(1, 2);

  int *dynamic = malloc(4);
  output_address("main: dynamic", &dynamic);  // The address of the pointer

  // Addresses on the heap
  output_address("main: dynamic (value)", dynamic);
  free(dynamic);

  // Addresses in the Code+ segment
  output_address("main: main (function)", &main);
  output_address("main: some_function (function)", &some_function);
  output_address("main: another_function (function)", &another_function);
}
