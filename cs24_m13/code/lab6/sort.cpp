#include <iostream>
#include "data_structures.h"

template <class T>
void List<T>::sort() {
  // TODO: Write the code to in-place sort the items of the List.
  // You should write one of bubble, insertion, or selection sort.
  
}

int main(int argc, char *argv[]) {
  List<std::string> list;
  for (int i = 1; i < argc; ++i) {
    list.insert_at(-1, argv[i]);
  }
  list.sort();
  list.output();
}
