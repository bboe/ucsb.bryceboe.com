#include <iostream>
#include "data_structures.h"

using namespace std;


PtrWrapper<int*> output_ptrwrapper(PtrWrapper<int*> tmp) {
  cout << "Value: " << tmp << endl;
  return tmp;
}


int main() {
  int a, b;
  // Do things explicitly (this will always work)
  a = 1;
  PtrWrapper<int*> a_ptr(&a);
  b = *output_ptrwrapper(a_ptr).ptr;
  // You can also just call the following to avoid creating `a_ptr`:
  //    output_ptrwrapper(PtrWrapper<int*>(&a))
  cout << "B = " << b << endl;

  // Do things implicitly (depends on lack of `explicit` keyworded-constructor)
  a = 2;
  b = *output_ptrwrapper(&a).ptr;
  cout << "B = " << b << endl;

  return 0;
}
