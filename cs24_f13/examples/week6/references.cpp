#include <iostream>

using namespace std;

/* This code attempts to show the difference between pass by / return by value,
   and pass by / return by reference (&).

   Note that the "pointer" type is very different from a reference, and that by
   default (without the & present) pointers are simply passed by value (copied).
*/


/* The following is a function which uses both pass by and return by value.
   The parameter is incremented by 1 and then returned.

   When this function is called the integer is copied on to the activation
   record, and it's return value is also copied.
*/
int inc_vv(int val) {
  return ++val;
}

/* The following function is passed the argument by reference and returns by
   value. The ++val increments the caller's value, and then returns a copy of
   that value.
*/
int inc_vr(int &val) {
  return ++val;
}

/* The following function is both passed the argument by reference and returns
   by reference. That means the data is never copied and only addresses are
   used.
*/
int &inc_rr(int &val) {
  return ++val;
}

/* The following commented out function does not work.

   int &inc_rv(int val);

   Because val's data would be on the stack of this function, returning a
   reference is not valid.
*/


int main() {
  int a = 1;
  cout << "Before: " << a << endl;
  cout << "vv one time: " << inc_vv(a) << endl;
  cout << "After: " << a << endl << endl;

  cout << "Before: " << a << endl;
  cout << "vv nested 3x: " << inc_vv(inc_vv(inc_vv(a))) << endl;
  cout << "After: " << a << endl << endl;


  cout << "Before: " << a << endl;
  cout << "vr one time: " << inc_vr(a) << endl;
  cout << "After: " << a << endl << endl;

  // inc_vr cannot be nested as the unbound copy from the return value cannot
  // be used as a reference parameter
  //cout << "vr nested 3x: " << inc_vr(inc_vr(inc_vr(a))) << endl;

  a = 1;
  cout << "Before: " << a << endl;
  cout << "rr one time: " << inc_rr(a) << endl;
  cout << "After: " << a << endl << endl;

  a = 1;
  cout << "Before: " << a << endl;
  cout << "rr nested 3x: " << inc_rr(inc_rr(inc_rr(a))) << endl;
  cout << "After: " << a << endl << endl;
  return 0;
}
