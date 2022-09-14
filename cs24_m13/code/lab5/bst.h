#ifndef BST_H
#define BST_H
#include "data_structures.h"
#include "node.h"


template <class T>
class BST {
 private:
  BinaryNode<T> *root;
 public:
  BST();
  ~BST();
  bool contains(T item);
  void insert(T item);
  void queue_output();
  void stack_output();
};


#endif /* BST_H */
