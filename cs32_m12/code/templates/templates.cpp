#include <iostream>

using namespace std;

template <class T>
void add_and_output(const T &arg1, const T &arg2) {
  cout << (arg1 + arg2) << endl;
}

template <class T>
T add(const T &arg1, const T& arg2) {
  return arg1 + arg2;
}

template <class T1, class T2>
class Pair {
public:
  Pair(T1 a, T2 b): a(a), b(b) {}
  T1 a;
  T2 b;
};

int main() {
  add_and_output(1, 2);
  add_and_output(1.1, 2.2);
  add_and_output((double)1, 2.1);
  add_and_output(string("hello "), string("world"));

  cout << add(1, 2) << endl;


  Pair<int, int> a(1, 2);
  Pair<string, string> b("hello ", "world");

  Pair<Pair<int, int>, Pair<string, string> > c(a, b);
  return 0;
}
