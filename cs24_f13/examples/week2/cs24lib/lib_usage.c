#include <stdio.h>
#include "cs24lib.h"

/*
  From a development standpoint, this is the code that we actually want to
  write. We want to be able to create an array of c-strings and use the cs24lib
  functions `output_array` and `swap` to interact with those items.

  Additionally, we do not want to have to compile the library source code every
  time so we only #include the header file (.h), which provides the
  declarations of the structures (there are none in this case), and the
  functions that the library provides.

  When we compile our program, we need to give the compiler an additional
  file. We can either give the compiler `cs24lib.c`, or `cs24lib.o` assuming
  `cs24lib.o` was already created. In the former case, the compiler detects
  that it is a source-code file and implicitly compiles the code and links it
  with our program in one step. In the latter case, the compiler detects that
  it is an object file and thus can omit the compilation step thus speeding up
  the process.

  Below are the two methods for compilation:

  Method 1) Compile both files and link together (when using this method
  cs24lib needs to be compiled each time you want to update `lib_usage.c` even
  if `cs24lib.c` was not updated:

      clang lib_usage.c cs24lib.c

  Method 2 step a) Compile the library to an object, which produces `cs24lib.o`
  (this only needs to be done once [well whenever cs24lib.c has changed]):

      clang -c cs24lib.c

  Method 2 step b) Compile `lib_usage.c` and link with cs24lib.o (run this step
  everytime `lib_usage.c` is updated):

      clang lib_usage.c cs24lib.o

  Note: For the int swap example to work, you need to give clang the `-m32`
  command line arugment otherwise sizeof(int) != sizeof(void *).

 */



int main() {
  char *strings[] = {"This array simply contains some strings.",
                     "The quick brown fox jumps over the lazy dog.",
                     "Given good manners you will go far."};

  printf("The initial array: \n");
  output_array(strings, 3, NULL);
  swap((void**)&strings[0], (void**)&strings[1]);

  printf("The array after swapping the first and second element:\n");
  output_array(strings, 3, NULL);


  /* We can also swap other pointer-size values this way as the swap function
     we wrote is meant to handle pointers.
  */
  if (sizeof(int) == sizeof(void*)) { // 32 bit architecture
    int a = 128;
    int b = -64;
    printf("swap on type int works: sizeof(int) == sizeof(void*)\n");
    printf("a = %d, b = %d\n", a, b);
    swap((void**)&a, (void**)&b);
    printf("a = %d, b = %d\n", a, b);
  }
  if (sizeof(double) == sizeof(void*)) { // 64 bit architecture
    double a = 3.14159;
    double b = 1.61803;
    printf("swap on type double works: sizeof(double) == sizeof(void*)\n");
    printf("a = %f, b = %f\n", a, b);
    swap((void**)&a, (void**)&b);
    printf("a = %f, b = %f\n", a, b);
  }

  /* Note that attempting to swap types of a different size will not work
     as intended.
  */
  char c = 'c';
  char d = 'd';
  printf("swap on type char does not work: sizeof(char) != sizeof(void*)\n");
  printf("c = '%c', d = '%c'\n", c, d);
  swap((void**)&c, (void**)&d);
  printf("c = '%c', d = '%c'\n", c, d);

  return 0;
}
