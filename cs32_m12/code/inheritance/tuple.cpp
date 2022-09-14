#include <cstdlib>
#include "tuple.h"

Tuple::Tuple(): num_items(0), items(NULL) {
  cout << "Tuple default constructor\n";
}

Tuple::Tuple(int num_items): num_items(num_items) {
  cout << "Tuple int n constructor\n";
  /* How do you delete this? */
  items = new int[num_items];
}

/* Copy constructor */
Tuple::Tuple(const Tuple &other) {
  cout << "Copy constructor called\n";
  num_items = other.num_items;
  items = new int[num_items];
  for (int i = 0; i < num_items; ++i)
    items[i] = other.items[i];
}

Tuple::~Tuple() {
  cout << "Tuple Destructor called\n";
  if (num_items > 0) {
    for (int i = 0; i < num_items; ++i)
      /* -1 the elements for demonstration purposes */
      items[i] = -1;
    delete []items;
  }
}

/* Assignment operator */
const Tuple& Tuple::operator =(const Tuple &other) {
  cout << "Tuple Assignment operator\n";

  if (this == &other)
    return *this;

  if (num_items > 0) {
    for (int i = 0; i < num_items; ++i)
      /* -1 the elements for demonstration purposes */
      items[i] = -1;
    delete []items;
  }
  num_items = other.num_items;
  items = new int[num_items];
  for (int i = 0; i < num_items; ++i)
    items[i] = other.items[i];

  return *this;
}

void Tuple::output() const {
  cout << *this;
}

void Tuple::set_item(int index, int value) {
  if (index > num_items) {
    cout << "Index is too large. Goodbye\n";
    exit(1);
  }
  items[index] = value;
}

ostream& operator <<(ostream &outs, const Tuple &tuple) {
  outs << "( ";
  for (int i = 0; i < tuple.num_items; ++i) {
    outs << tuple.items[i];
    if (i < tuple.num_items - 1)
      outs << ", ";
    else
      outs << " ";
  }
  outs << ")";
  return outs;
}
