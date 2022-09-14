#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(int argc, char *argv[]) {
  struct List *words = list_construct();
  struct List *reversed = list_construct();
  for (int i = 1; i < argc; ++i) {
    list_push_back(words, argv[i]);
  }
  while(!list_is_empty(words)) {
    list_push_back(reversed, list_remove_at(words, -1));
  }
  list_output(reversed);
  list_destruct(words);
  list_destruct(reversed);
  return 0;
}
