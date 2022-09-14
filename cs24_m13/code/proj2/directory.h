#ifndef DIRECTORY_H
#define DIRECTORY_H
#include "bst.h"

/* This class represents a directory.

   A directory contains the name of the directory such as "home" or "bboe".

   A directory also has a pointer to its parent directory. The root-directory's
   parent pointer will be NULL.

   The subdirs attribute (acessible via `get_subdirs`) is a BST containing
   references (they must be references so they can be compared properly) to the
   subdirectories of the directory.
*/
class Directory {
private:
  std::string name;
  Directory *parent;
  BST<Directory&> subdirs;
public:
  Directory(std::string name): name(name), parent(NULL), subdirs() {}

  /* Deallocate the directory.

     This must free any memory that was allocated by its subdirectories (use
     `BST::remove_root`` as many times as necessary). Do not forget to free
     both the data and the BinaryNode instances as `BST::remove_root` should
     not perform either of those actions.
  */
  ~Directory();
  std::string get_name() const { return name; }
  Directory *get_parent() const { return parent; }
  void set_name(std::string name) { this->name = name; }
  void set_parent(Directory *parent) { this->parent = parent; }
  BST<Directory&> *get_subdirs() { return &subdirs; }
};


/* NOTE: You need not understand any of the following code in this file. */

/* The following functions perform operator overloading that support
   comparision between between Directory instances. They implement comparision
   such that only the name of the Directory is compared. This allows for the
   following:

   Directory d1("hello");
   Directory d2("world"):
   Directory d3("hello");
   d3.set_parent(&d2);

   d1 == d2  (false: hello != world)
   d1 != d2  (true: hello != world)
   d1 < d2   (true: hello < world)
   d1 == d3  (true: hello == world, even though d3's parent is different)

   Having these comparisons overloaded allows us to store Directory types in
   the BST and use the simple comparison tests that you have already
   written. Note that `<=` and `>=` are not overloaded thus you can not use
   those comparisons in your BST class.
*/
bool operator==(const Directory &lhs, const Directory &rhs) {
  return lhs.get_name() == rhs.get_name();
}
bool operator!=(const Directory &lhs, const Directory &rhs) {
  return !(lhs == rhs);
}
bool operator<(const Directory &lhs, const Directory &rhs) {
  return lhs.get_name() < rhs.get_name();
}
bool operator>(const Directory &lhs, const Directory &rhs) {
  return rhs < lhs;
}

/* The following overloads the << operator for ostream and directory references.

   Doing this allows us to control what is output when we execute:

   Directory d("hello");
   cout << d << endl;

   In this case the output would be "hello\n".
*/
std::ostream& operator<<(std::ostream& os, const Directory &obj) {
  return os << obj.get_name();
}

#endif /* DIRECTORY_H */
