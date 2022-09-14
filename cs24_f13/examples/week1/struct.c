#include <stdio.h>
#include <stdlib.h>


struct Point {
  int x;
  int y;
  char *name;
};


void point_output(struct Point *ptr) {
  for (int i = 0;;)
  printf("struct(%d, %d, %s)\n", ptr->x, ptr->y, ptr->name);
}


int main() {
  /* Initilized after instantiation */
  struct Point p1 = {1, 2, "foobar"};
  struct Point *p2 = malloc(sizeof(struct Point));
  p2->x = 0xA;
  p2->y = 0xB;
  p2->name = "blah";
  point_output(&p1);
  point_output(p2);

  printf("Point size: %u\n", sizeof(struct Point));

  return 0;
}
