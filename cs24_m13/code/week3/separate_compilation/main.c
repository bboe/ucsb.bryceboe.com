#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "point.h"

/* This is a sample "main" program that utilizes a user-level library. It
   depends on point.h and as such requires point.c to be compiled and linked in
   order to produce the executable.

   There are a few ways to build the executable:

   1) clang main.c point.c

   This first method compiles both files, and links them together to produce
   the executable in one step. There is no optimization here. Note that the
   order of the filenames is irrelevant.

   2) clang -c main.c
      clang -c point.c
      clang main.o point.o

   Running `clang -c <FILENAME>.c` will compile what's called an object file
   (<FILENAME>.o) whose primary use is to speed up the process of later
   "linking" steps (one of the last steps the compiler performs before
   producing an executable).

   Assuming <FILENAME>.c doesn't change, <FILENAME>.o can be used in its place
   to speed up the compilation process.

*/

int main(int argc, char *argv[]) {
  // Create as many Point structs as command line-pairs
  char *tmp;

  if (argc < 2) {
    printf("Usage: points x,y...\n");
    return 0;
  }

  struct Point *points = malloc(sizeof(struct Point) * argc - 1);
  for (int i = 1; i < argc; ++i) {
    // Parse x
    if (!(tmp = strtok(argv[i], ","))) {
      printf("Invalid point spec at argument %d\n", i);
      return 1;
    }
    points[i - 1].x = atoi(tmp);
    // Parse y
    if (!(tmp = strtok(NULL, ","))) {
      printf("Invalid point spec at argument %d\n", i);
      return 1;
    }
    points[i - 1].y = atoi(tmp);
    point_output(&points[i - 1], stdout);
  }
  free(points);
}
