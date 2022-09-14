#include <stdio.h>
#include <stdlib.h>

/* Lack of Encapsulation

   Why should my data and my operations on that data both be contained in the
   global namespace? Why not make it such that the operations are simply
   performed on the data (or objects)

   This also means that I can only ever use 1 implementation of the List ADT at
   a time unless I rename the List structures to include their implementation
   type. But then I have to update all my code to be aware of which
   implementation I'm working with, which is silly. C++ has a way of resolving
   this situation.
*/

struct Date {  // recall that we prefix attributes with _ we don't want
  int _year;   // directly modified. But we cannot prevent it from happening.
  int _month;
  int _day;
};

struct Date* date_construct() {
  return malloc(sizeof(struct Date));
}

/* Again I cannot overload functions in C with a different prototype
   thus I need to give it a unique funciton name.
 */
struct Date* date_construct_args(int year, int month, int day) {
  if (month < 1 || month > 12 || day < 1 || day > 31)
    return NULL;
  struct Date *retval = malloc(sizeof(struct Date));
  if (!retval) return NULL;
  retval->_year = year;
  retval->_month = month;
  retval->_day = day;
  return retval;
}

int date_set_year(struct Date *date, int year) {
  date->_year = year;
  return 1;
}

int date_set_month(struct Date *date, int month) {
  if (month < 1 || month > 12)
    return 0;
  date->_month = month;
  return 1;
}

int date_set_day(struct Date *date, int day) {
  if (day < 1 || day > 31)
    return 0;
  date->_day = day;
  return 1;
}

void date_output(const struct Date *date) {
  if (date)
    printf("%04d/%02d/%02d\n", date->_year, date->_month, date->_day);
  else
    printf("ERROR: Received NULL pointer\n");
}



int main() {
  struct Date *date_a = date_construct();
  date_set_year(date_a, 2013);
  date_set_month(date_a, 7);
  date_set_day(date_a, 16);
  date_output(date_a);

  // The setter prevents me from doing the following:
  date_set_month(date_a, 13);
  date_set_day(date_a, 32);
  date_output(date_a);
  // However, there is no way in C to prevent me from doing:
  date_a->_month = 13;
  date_a->_day = 32;
  date_output(date_a);

  /* This date won't create because of the checks in the constructor */
  struct Date *date_b = date_construct_args(2013, 13, 32);
  date_output(date_b);

  // Always clean-up
  free(date_a);
  free(date_b);
}
