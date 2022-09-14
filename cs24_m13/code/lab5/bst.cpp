#include <iostream>
#include "bst.h"


template <class T>
BST<T>::BST(): root(NULL) {}

template <class T>
BST<T>::~BST() {
  // Intentionally blank. Complete for extra credit.
}

template <class T>
bool BST<T>::contains(T item) {
  // Complete this function
  return false;
}

template <class T>
void BST<T>::insert(T item) {
  // Write this function
}

template <class T>
void BST<T>::queue_output() {
  // Write this function
}

template <class T>
void BST<T>::stack_output() {
  // Write this function
}


// Separate compilation and templates don't play nice together
// http://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
template class BST<int>;
