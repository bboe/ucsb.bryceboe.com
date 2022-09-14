#include <stdio.h>
#include <stdlib.h>

struct Point {
  int x;
  int y;
  char *name;
};

/* Output a representation of the Point to outs */
void point_output(struct Point *point, FILE* outs) { // Why is point a pointer?
  fprintf(outs, "Point(%d, %d, \"%s\");\n", point->x, point->y, point->name);
  // Note the following is the same (using `*` to first deference and then `.`
  // to access the attribute
  //fprintf(outs, "Point(%d, %d, \"%s\");\n", (*point).x, (*point).y,
  //        (*point).name);
}

int main() {
  /* Initilized after instantiation */
  struct Point p1;
  p1.x = 15;
  p1.y = 27;
  p1.name = "Point 1";

  point_output(&p1, stdout);  // Use & to get the address (pointer) to the
                              // local memory

  /* Initilized during instantiation */
  struct Point p2 = {-27, 16, "Point 2"};

  point_output(&p2, stdout);

  /* Dynamic Struct (on the heap) */
  struct Point *p3 = malloc(sizeof(struct Point));
  p3->x = 16;
  p3->y = 32;
  p3->name = "Dynamic Struct";
  point_output(p3, stdout);  // p3 is already a pointer so & isn't needed
  free(p3);

  return 0;
}
