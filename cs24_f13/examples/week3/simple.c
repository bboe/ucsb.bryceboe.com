#include <stdio.h>
#include <stdlib.h>

struct simple {
  int _data;
  char _has_data;
};


/* Allocate the structure and initialize its values */
struct simple *simple_construct() {
  struct simple *retval = malloc(sizeof(struct simple));
  if (retval == NULL)  // if malloc fails
    return NULL;
  retval->_has_data = 0;
  return retval;
}

/* Free any allocated memory and the structure.

   Assumes that `s` is on the heap and thus is freeable.
*/
void simple_destruct(struct simple *s) {
  free(s);
};

/* Return 1 if the simple struct does not have data, 0 otherwise. */
char simple_is_empty(struct simple *s) {
  return !s->_has_data;
}

/* Add value to the simple struct if there is space available.

   Return 0 on failure or 1 on success.
*/
char simple_add(struct simple *s, int value) {
  if (s->_has_data)
    return 0;
  s->_data = value;
  s->_has_data = 1;
  return 1;
}

/* Return 1 if the value is contained in the simple struct, 0 otherwise. */
char simple_contains(struct simple *s, int value) {
  return s->_has_data && s->_data == value;
}

/* Return the data on if available otherwise -1.

   On succes is_error is set to 0, and on failure is_error is set to 1.

   Implementation note: This function requires passing a writable parameter (a
   pointer to an int in this case) so that we can differentiate between -1 as a
   valid return value (is_error=0), and an error case (is_error=1).
*/
int simple_get(struct simple *s, int *is_error) {
  if (s->_has_data) {
    *is_error = 0;
    return s->_data;
  }
  else {
    *is_error = 1;
    return -1;
  }
}


/* Return and remove the data if available, otherwise -1.

   On success is_error is set to 0, and on failure is_error is set to 1.
*/
int simple_remove(struct simple *s, int *is_error) {
  if(s->_has_data) {
    *is_error = 0;
    s->_has_data = 0;
    return s->_data;
  }
  else {
    *is_error = 1;
    return -1;
  }
}


int main() {
  struct simple *my_simple = simple_construct();
  int is_error = 0xDEADBEEF;  // initialize to value we don't expect

  if (my_simple == NULL) {
    printf("Could not construct my_simple\n");
    return 1;
  }

  printf("Verify initialization state\n");
  printf("is_empty(): %d\n", simple_is_empty(my_simple));
  printf("contains(-1): %d\n", simple_contains(my_simple, -1));
  printf("contains(0): %d\n", simple_contains(my_simple, 0));
  printf("get(): %d (is error: %d)\n", simple_get(my_simple, &is_error),
         is_error);
  printf("remove(): %d (is error: %d)\n\n", simple_remove(my_simple, &is_error),
         is_error);

  printf("Add an item and verify state\n");
  printf("add(-1): %d\n", simple_add(my_simple, -1));
  printf("is_empty(): %d\n", simple_is_empty(my_simple));
  printf("contains(-1): %d\n", simple_contains(my_simple, -1));
  printf("contains(0): %d\n", simple_contains(my_simple, 0));
  printf("get(): %d (is error: %d)\n\n", simple_get(my_simple, &is_error),
         is_error);

  printf("Try to add a second item and verify state\n");
  printf("add(0xDEADBEEF): %d\n", simple_add(my_simple, 0xDEADBEEF));
  printf("is_empty(): %d\n", simple_is_empty(my_simple));
  printf("contains(-1): %d\n", simple_contains(my_simple, -1));
  printf("contains(0): %d\n", simple_contains(my_simple, 0));
  printf("get(): %d (is error: %d)\n\n", simple_get(my_simple, &is_error),
         is_error);

  printf("Remove an item and verify state\n");
  printf("remove(): %d (is error: %d)\n", simple_remove(my_simple, &is_error),
         is_error);
  printf("is_empty(): %d\n", simple_is_empty(my_simple));
  printf("contains(-1): %d\n", simple_contains(my_simple, -1));
  printf("contains(0): %d\n", simple_contains(my_simple, 0));
  printf("get(): %d (is error: %d)\n", simple_get(my_simple, &is_error),
         is_error);
  printf("remove(): %d (is error: %d)\n\n", simple_remove(my_simple, &is_error),
         is_error);

  simple_destruct(my_simple);
  return 0;
}
