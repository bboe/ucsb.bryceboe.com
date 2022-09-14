#include <iostream>
using namespace std;

class Tuple {
public:
  Tuple();
  Tuple(int n);
  Tuple(const Tuple &other);
  ~Tuple();

  Tuple &operator =(const Tuple &other);

  friend ostream& operator <<(ostream &outs, const Tuple &tuple);
  void set_item(int index, int value);

private:
  int num_items;
  int *items;
};

Tuple::Tuple(): num_items(0), items(NULL) {}

Tuple::Tuple(int n): num_items(n) {
  /* How do you delete this? */
  items = new int[n];
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
  cout << "Destructor called\n";
  delete []items;
}

Tuple& Tuple::operator =(const Tuple &other) {
  cout << "Assignment operator called\n";
  /*
  if (this == &other)
    return *this;
  */
  delete []items;
  num_items = other.num_items;
  items = new int[num_items];
  for (int i = 0; i < num_items; ++i)
    items[i] = other.items[i];
  return *this;
}

void Tuple::set_item(int index, int value) {
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

int main() {
  Tuple tuple_a, tuple_b(5);

  /*
  Tuple *tmp = new Tuple();
  delete tmp;
  */

  for (int i = 0; i < 5; ++i)
    tuple_b.set_item(i, i);

  cout << "tuple_a" << tuple_a << endl;
  cout << "tuple_b" << tuple_b << endl;

  /* Copy constructor */
  Tuple tuple_c(tuple_b);
  cout << "tuple_c from copy of b " << tuple_c << endl;
  tuple_b.set_item(0, 100);
  cout << "tuple_c after b set_item " << tuple_c << endl;


  /* Assignment Operator */
  //Tuple tuple_d = tuple_c; // Compiler optimizes to use copy constructor
  Tuple tuple_d(1024);
  tuple_d = tuple_c;
  cout << "tuple_d from assignment from c " << tuple_d << endl;
  tuple_c.set_item(0, 100);
  cout << "tuple_d after c set_item " << tuple_d << endl;

  cout << "---Placeholder---\n";


  /* Self assignment (completely valid) */
  tuple_c = tuple_c;
  cout << "tuple_c after self assignment " << tuple_c << endl;

  /* Multiple assignment */
  tuple_a = tuple_b = tuple_c = tuple_d;
  cout << "tuple_a after multiple assginment " << tuple_a << endl;
  cout << "tuple_b after multiple assginment " << tuple_b << endl;
  cout << "tuple_c after multiple assginment " << tuple_c << endl;
  cout << "tuple_d after multiple_assignment " << tuple_d << endl;

  cout << "---end of main---\n";
  return 0;
}
