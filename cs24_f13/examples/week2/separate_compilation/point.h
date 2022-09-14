#ifndef POINT_H
#define POINT_H

/* Header files most commonly utilize compiler macro conditionals to prevent the
   functions from being included multiple times.

   The #ifndef macro says, if the variable (POINT_H in this case) is not
   defined, then everything from this point to the #endif macro should be
   considererd part of the file. Otherwise, ignore everything between the
   #ifndef and the matching #endif. The first statement often found is the
   #define macro which prevents this file from ever being included more than
   once.
*/

struct Point {
  int x;
  int y;
};

/* Output the point to stream */
void point_output(struct Point *point, FILE *stream);

#endif
