#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 1

int main(int argc, char *argv[]) {
  /* Verify and parse command line arguments */
  if (argc != 2) {
    printf("Usage: realloc NUM\n");
    return 1;
  }
  int items_to_add = atoi(argv[1]);

  /* Initialize the list */
  int *array = malloc(sizeof(int) * INIT_SIZE);
  if (!array) {
    perror("Could not malloc initial list. Goodbye");
    return 1;
  }
  int allocated = INIT_SIZE;
  int size = 0;

  /* Add the appropriate number of items to the list */
  for (int i = 0; i < items_to_add; ++i) {
    if (size == allocated) {  // Expand the array
      int *tmp = realloc(array, sizeof(int) * allocated * 2);
      if (!tmp) {
        /* When reallocation fails we don't want to destroy the array
           so we use a tmp variable to test before updating the array pointer.
        */
        printf("Reallocation failed at %d.\n", i);
        break;
      }
      /* The memory array points to may no longer be valid so we need to update
         it. */
      printf("Realloced from %d to %d\n", allocated, allocated * 2);
      array = tmp;
      allocated *= 2;
    }
    // Actually add the item to the array
    array[size++] = i;
  }

  /* Let's output a sample of the contents of the array */
  int step = size / 256;
  for (int i = 0; i < size; i = i + step)
    printf("%d: %d\n", i, array[i]);

  // It's kind of silly to call free as the last part of a program, but it's
  // still a good practice.
  free(array);
  return 0;
}
