#include <iostream>
#include "directory.h"

// compile via clang++ test_dir.cpp bst.cpp

using namespace std;

int main() {
  // Create a root directory
  Directory root("/");
  cout << "Add: " << root.add_subdirectory("a") << endl;
  cout << "Add: " << root.add_subdirectory("b") << endl;
  cout << "Add: " << root.add_subdirectory("b") << endl;
  cout << "Add: " << root.add_subdirectory("0") << endl;
  cout << "Add: " << root.add_subdirectory("10") << endl;
  root.list_directory();

  cout << "Remove: " << root.remove_subdirectory("10") << endl;
  cout << "Remove: " << root.remove_subdirectory("10") << endl;
  cout << "Remove: " << root.remove_subdirectory("a") << endl;
  root.list_directory();

  return 0;
}
