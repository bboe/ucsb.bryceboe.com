#include <iostream>
#include <sstream>
#include "data_structures.h"
#include "bst.h"
using namespace std;


int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "Usage: driver num [num...]\n";
    return 1;
  }

  // Add the numbers to the binary search tree
  BST<int> b;
  for (int i = 1; i < argc; ++i) {
    stringstream ss(argv[i]);
    int n;
    if (!(ss >> n && ss.eof())) {
      cout << "'" << argv[i] << "' is not a valid number. Goodbye!\n";
      return 1;
    }
    b.insert(n);
  }

  b.stack_output();
  b.queue_output();

  for (int i = 0; i < 10; ++i)
    cout << i << " in BST: " << b.contains(i) << endl;

  return 0;
}
