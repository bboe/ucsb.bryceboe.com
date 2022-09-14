#include <stdio.h>
//#include "cs24lib.c"
/* If the above line is uncommented you will receive a compiler error due to
   redefinition errors. This is one reason why .c files should never be
   included. Yes, it is correct that because cs24lib_ext is included, that
   redundantly includes cs24lib, however, that is something that you needn't
   be aware of as libraries include other libraries all the time, thus redundant
   includes are something that needs to be supported. */

#include "cs24lib_ext.c"

int main() {
  char *tmp[] = {"hello", "world", "foobar"};
  output_array(tmp, 3, NULL);
  advanced_output_array(tmp, 1, 2, NULL);
}
