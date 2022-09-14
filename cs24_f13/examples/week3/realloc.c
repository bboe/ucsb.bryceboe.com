#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* This function does almost exactly what realloc does.
   However: (1) realloc may not need to copy in some cases as it may just be
            able to increase the size of the chunk allocated
            (2) realloc does not need to know the old size as it can figure out
            the size from the metadata associated with the allocated chunk
*/
void *my_realloc(void *source, int old_size, int additional_size) {
  void *retval = malloc(old_size + additional_size);
  if (retval == NULL)  // malloc failed
    return NULL;
  memcpy(retval, source, old_size);  // copy from old to new
  free(source);  // don't leak memory
  return retval;
}


/* Destructively update orig such that it is a string containing orig + new.

   Assume that orig is on the heap and is freeable (it will be destroyed).

   Return 0 on success and -1 on failure. On failure orig is untouched.
 */
int append_char(char **orig, char new) {
  int prev_size = strlen(*orig);
  //char *new_str = my_realloc(*orig, sizeof(char) * (prev_size + 1), 1);
  char *new_str = realloc(*orig, sizeof(char) * (prev_size + 2));
  if (new_str == NULL)  // realloc failed
    return -1;
  *orig = new_str;  // update the caller's pointer
  new_str[prev_size] = new;
  new_str[prev_size + 1] = '\0';
  return 0;
}


int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: a.out STRING\n");
    return 1;
  }
  char *str = strdup(argv[1]);  // str must be on the heap for append_char
  printf("orig: %s\n", str);
  for (char chr = 0x41; chr < 0x40 + 26; ++chr) {
    append_char(&str, chr);
    printf("Append %c: %s\n", chr, str);
  }
  free(str);
  return 0;
}
