#include <stdio.h>

/* The purpose of this example is to demonstrate that fields within
   a structure are padded to be word-aligned (4 bytes).

   Compile via `clang -m32 alignment.c`.

   If you want to pack the elements in you can add `__attribute__((packed))`
   after the `}` and before the `;`, however, it's almost never a good idea to
   do so.
*/

struct charint {  // Expected to be 6 bytes
  char a;
  int b;
  char c;
};

struct intchar {  // Expected to be 9 bytes
  int a;
  char b;
  int c;
};


int main() {
  printf("   char: %u\n", sizeof(char));
  printf("    int: %u\n\n", sizeof(int));

  printf("charint: %u\n", sizeof(struct charint));
  printf("intchar: %u\n\n", sizeof(struct intchar));

  struct charint a;
  struct intchar b;


  printf("%p (charint.a (char))\n", (void*)&a.a);
  printf("%p (charint.b (int))\n", (void*)&a.b);
  printf("%p (charint.c (char))\n\n", (void*)&a.c);

  printf("%p (intchar.a (int))\n", (void*)&b.a);
  printf("%p (intchar.b (char))\n", (void*)&b.b);
  printf("%p (intchar.c (int))\n", (void*)&b.c);

  return 0;
}
