#ifndef BST_H
#define BST_H
#include "data_structures.h"
#include "node.h"


template <class T>
class BST {
 private:
  BinaryNode<T> *root;
 public:
  static BinaryNode<T> *find_max(BinaryNode<T> *node);
  BST();

  /* Deallocate all BinaryNode objects from the tree.

     Either define a recursive helper function or use another data structure to
     help remove all the nodes.
  */
  ~BST();
  BinaryNode<T> *contains(T item);
  bool insert(T item);
  void queue_output();

  /* Remove and return the Node from the BST, if it exists, that is equal to
     (==) T item.

     If no matching Node exists return NULL. Note that you should _not_
     deallocate the BinaryNode<T> as part of this call. It is the
     responsibility of the caller to deallocate the returned BinaryNode<T>
     instance.
  */
  BinaryNode<T> *remove(T item);

  /* Remove and return the root Node from the BST, if one exists. Return NULL
     otherwise.

     This method is necessary in order to remove all Nodes from the BST.

     Again it is the responsibility of the caller to deallocated the returned
     BinaryNode<T> instance.

     Hint: you can implement this pretty easily by utilziig `BST::remove`. This
     will allow you to avoid duplicating your work.
   */
  BinaryNode<T> *remove_root();
  void sorted_output();
  void stack_output();
};


#endif /* BST_H */
