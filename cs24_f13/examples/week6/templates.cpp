#include <iostream>

using namespace std;  // prevent the need of std::

/* Provide an explicit output function that takes an int and a double */
void output(int a, double b) {
  std::cout << "(explicit)\n\tfirst: " << a << "\n\tsecond: " << b << endl;
}

/* Provide a generic output function for any two types */
template <class T1, class T2>
void output(T1 a, T2 b) {
  cout << "(generic)\n\tfirst: " << a << "\n\tsecond: " << b << endl;
}

/* Provide a generic output function for any two _pointer_ types. */
template <class T1, class T2>
void output(T1 *a, T2 *b) {
  cout << "(generic ptr)\n\tfirst: " << *a << "\n\tsecond: " << *b << endl;
}

/* Provide a generic output funciton for any two arguments of the same type. */
template <class T>
void output(T a, T b) {
  cout << "(same types)\n\tfirst: " << a << "\n\t  second: " << b << endl;
}

/* Define a class "Container" that holds any two types. */
template <class T, class U>
class Container {
 public:
  T data;
  U foo;
};

/* Overload the << operator so that we can directly output Container types */
template <class T1, class T2>
ostream& operator<<(ostream &outs, const Container<T1, T2> &obj) {
  return outs << "Container(data=" << obj.data << ", foo=" << obj.foo << ")";
}


int main() {
  // Which version of output will the following call?
  output(1, 1.25);
  output(1.25, 1);
  output(1, 1);
  output("hello", 'c');
  output(new int(1), new double(2));  // This results in a memory leak

  Container<int, double> a;
  a.data = 1;
  a.foo = 2.3;

  Container<string, string> b;
  b.data = "hello world";
  b.foo = "foo bar";

  output(a, b);

  Container<Container<int, int>, string> c;
  c.data.data = 1;
  c.data.foo = 1;
  c.foo = "some string";

  output(c, 0);

  return 0;
}
