#include <iostream>
#include "node.h"

template <class T>
class Tree {
 private:
  BinaryNode<T> *root;
 public:
  Tree(BinaryNode<T> *root): root(root) {}
  ~Tree() { /* intentionally blank for now */ }

  void output_pre_order();
  void output_in_order();
  void output_post_order();
};

template <class T>
void pre_order(BinaryNode<T> *node) {
  if (!node)
    return;
  std::cout << node->get_data() << " ";
  pre_order(node->get_lhs());
  pre_order(node->get_rhs());
}

template <class T>
void Tree<T>::output_pre_order() {
  pre_order(root);
  std::cout << std::endl;
}


template <class T>
void in_order(BinaryNode<T> *node) {
  if (!node)
    return;
  in_order(node->get_lhs());
  std::cout << node->get_data() << " ";
  in_order(node->get_rhs());
}

template <class T>
void Tree<T>::output_in_order() {
  in_order(root);
  std::cout << std::endl;
}

template <class T>
void post_order(BinaryNode<T> *node) {
  if (!node)
    return;
  post_order(node->get_lhs());
  post_order(node->get_rhs());
  std::cout << node->get_data() << " ";
}


template <class T>
void Tree<T>::output_post_order() {
  post_order(root);
  std::cout << std::endl;
}


int main() {
  // Statically build the example tree
  BinaryNode<char> *h = new BinaryNode<char>('H', NULL, NULL);
  BinaryNode<char> *g = new BinaryNode<char>('G', NULL, NULL);
  BinaryNode<char> *f = new BinaryNode<char>('F', g, h);
  BinaryNode<char> *e = new BinaryNode<char>('E', NULL, NULL);
  BinaryNode<char> *d = new BinaryNode<char>('D', NULL, NULL);
  BinaryNode<char> *c = new BinaryNode<char>('C', NULL, f);
  BinaryNode<char> *b = new BinaryNode<char>('B', d, e);
  BinaryNode<char> *a = new BinaryNode<char>('A', b, c);
  Tree<char> tree(a);

  std::cout << "Pre-order\n";
  tree.output_pre_order();
  std::cout << "In-order\n";
  tree.output_in_order();
  std::cout << "Post-order\n";
  tree.output_post_order();
}
