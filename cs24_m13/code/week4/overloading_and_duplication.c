#include <stdio.h>

/* Lack of function overloading

   I cannot use the same name to support multiple arguments. There can ONLY be
   one `min` function. All others must be unique which means libraries must
   name their functions such that they don't collide with functions of other
   libraries.

   Also notice that the function contents are identical save for the types. C++
   has support for reducing that code duplication.
*/
int int_min(int a, int b) {
  if (a <= b) return a;
  else return b;
}

//double min(double a, double b) {  //that's what I want to do
double double_min(double a, double b) {
  if (a <= b) return a;
  else return b;
}


int main() {
  printf("Min(%d, %d) = %d\n", 1, 2, min(1, 2));
  printf("Min(%.2f, %.2f) = %.2f\n", .1, .2, double_min(.1, .2));
}
