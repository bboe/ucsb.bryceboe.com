#include <cstdio>
#include <string>

/* Compile via clang++ -m32 types.cpp

   Note: In this example we are using printf (from cstdio). This is only for
   the purposes of this example. When we use c++ in this class you will not be
   allowed to use cstdio and must use iostream.
*/

struct Foo {
  bool a;
  std::string b;
};

class Bar {
  bool a;
  std::string b;
};

int main() {
  printf("Size of bool: %u\n", sizeof(bool));
  printf("Size of string: %u\n", sizeof(std::string));
  printf("Size of struct Foo: %u\n", sizeof(struct Foo));
  printf("Size of Bar: %u\n", sizeof(Bar));

  /* Output the value of a bool */
  bool a = 5;
  printf("a = 5 == %d\n", a);
  a = -1;
  printf("a = -1 == %d\n", a);

  /* Output the initial value of a string */
  std::string b;
  printf("b == %s\n", b.c_str());

  /* Append a c-string to a string */
  b += "hello world";
  printf("b == %s\n", b.c_str());

  /* Append another string to a string */
  std::string c = "even more data";
  b += "! " + c;
  printf("b == %s\n", b.c_str());

  /* Perform some operations on the string */
  printf("Length: %d\n", b.length());  // you can also use b.size()
  printf("First character: %c\n", b[0]);
  printf("Substring: %s\n", b.substr(1, 5).c_str());

  /* Comparison */
  std::string d = "even more data";
  printf("c == d: %d\n", c == d);

  return 0;
}
