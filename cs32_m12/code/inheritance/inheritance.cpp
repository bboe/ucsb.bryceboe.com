#include "tuple.h"

class NamedTuple: public Tuple {
public:
  NamedTuple(string name, int n);
  ~NamedTuple();
  void output() const;
  NamedTuple& operator =(const NamedTuple& other);
private:
  string name;
};

NamedTuple& NamedTuple::operator =(const NamedTuple& other) {
  cout << "NamedTuple assignment operator\n";
  Tuple::operator=(other);
  name = other.name;
  return *this;
}

NamedTuple::NamedTuple(string name, int n): Tuple(n), name(name) {
  cout << "NamedTuple constructor\n";
}

NamedTuple::~NamedTuple() {
  cout << "NamedTuple destructor called\n";
}

void NamedTuple::output() const {
  cout << name;
  Tuple::output();
}

void output_tuple_array(Tuple *array[], int n) {
  for (int i = 0; i < n; ++i) {
    cout << i << ". ";

    /* Using cout << *array[i] would not allow for dynamic dispatch */
    array[i]->output();
    cout << endl;
  }
}

int main() {
  /* Default constructor inherited when no other constructors are defined */
  /*
  NamedTuple tmp;
  cout << tmp << endl;
  */

  /* Other constructors are not inherited */
  //NamedTuple tmp(5);


  NamedTuple named_1("tmp", 5), named_2("named2", 1);

  cout << named_1 << endl;

  named_1.output(); cout << endl;
  cout << (Tuple)named_1 << endl;

  cout << "Placeholder\n";

  named_1 = named_2;
  named_1.output();
  cout << endl;

  //Tuple unnamed;
  Tuple *array[2];
  Tuple *regular = new Tuple(2);
  NamedTuple *tmp2 = new NamedTuple("blah", 4);

  array[0] = regular;
  array[1] = tmp2;

  output_tuple_array(array, 2);


  NamedTuple bar("foo", 5);
  /* Casting directly to a type results in a loss of data */
  cout << "Cast from NamedTuple to Tuple\n";
  ((Tuple)bar).output();
  cout << endl;

  /* Casting to a refernce of the type does no lose data */
  cout << "Cast from NamedTuple to Tuple&\n";
  ((Tuple&)bar).output();
  cout << endl;



  cout << "---End of main--\n";
  return 0;
}
