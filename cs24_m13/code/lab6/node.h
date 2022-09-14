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

  void set_data(T data) {
    this->data = data;
  }

  Node<T> *set_next(Node<T> *node) {
    this->next = node;
    return node;
  }
};

#endif /* NODE_H */
