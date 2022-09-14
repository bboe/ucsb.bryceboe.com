#include <iostream>
#include "node.h"

template <class T>
class Tree {
 private:
  BinaryNode<T> *root;
 public:
  static int get_node_height(BinaryNode<T> *node);
  static int compute_node_sum(BinaryNode<T> *node);

  Tree(BinaryNode<T> *root): root(root) {}

  ~Tree() { /* intentionally blank for now */ }

  int get_height() { return get_node_height(root); }
  int compute_sum() { return compute_node_sum(root); }
};

/* This function uses recursion to compute the height of the node.

   A null value indicates that a node does not exist, which is represented
   by a height of -1. A node with no children (a leaf) has a height of 0.

   By using recursion (calling our own function with a subproblem (in this case
   for each subtree) we can incrementally return the result up the call-stack.

*/
template <class T>
int Tree<T>::get_node_height(BinaryNode<T> *node) {
  if (!node)
    return -1;
  return 1 + std::max(get_node_height(node->get_lhs()),
                      get_node_height(node->get_rhs()));
}

template <class T>
int Tree<T>::compute_node_sum(BinaryNode<T> *node) {
  if (!node)
    return 0;
  return (node->get_data()
          + compute_node_sum(node->get_lhs())
          + compute_node_sum(node->get_rhs()));
}


int main() {
  // Statically build the example tree
  BinaryNode<int> *h = new BinaryNode<int>(8, NULL, NULL);
  BinaryNode<int> *g = new BinaryNode<int>(7, NULL, NULL);
  BinaryNode<int> *f = new BinaryNode<int>(6, g, h);
  BinaryNode<int> *e = new BinaryNode<int>(5, NULL, NULL);
  BinaryNode<int> *d = new BinaryNode<int>(4, NULL, NULL);
  BinaryNode<int> *c = new BinaryNode<int>(3, NULL, f);
  BinaryNode<int> *b = new BinaryNode<int>(2, d, e);
  BinaryNode<int> *a = new BinaryNode<int>(1, b, c);
  Tree<int> tree(a);

  std::cout << tree.get_height() << std::endl;
  std::cout << tree.compute_sum() << std::endl;
}
