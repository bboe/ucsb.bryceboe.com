#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
 private:
  T data;
  Node<T> *next;
 public:
  Node(T data, Node<T> *next): data(data), next(next) {}

  T get_data() const {
    return data;
  }

  Node<T> *get_next() const {
    return next;
  }

  Node<T> *set_next(Node<T> *node) {
    this->next = node;
    return node;
  }
};

template <class T>
class BinaryNode {
 private:
  T data;
  BinaryNode<T> *lhs;
  BinaryNode<T> *rhs;
 public:
 BinaryNode(T data, BinaryNode<T> *lhs, BinaryNode<T> *rhs):
  data(data), lhs(lhs), rhs(rhs) {}

  T get_data() const {
    return data;
  }

  BinaryNode<T> *get_lhs() const {
    return lhs;
  }

  BinaryNode<T> *get_rhs() const {
    return rhs;
  }

  void set_data(T data) {
    this->data = data;
  }

  BinaryNode<T> *set_lhs(BinaryNode<T> *node) {
    lhs = node;
    return node;
  }

  BinaryNode<T> *set_rhs(BinaryNode<T> *node) {
    rhs = node;
    return node;

  }
};

#endif /* NODE_H */
