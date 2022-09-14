#include <iostream>  // This C++ library includes the IO objects/functions

// The following statement means that everything in the std namespace (e.g.,
// cin, cout, min), will be available in the global namespace. If I didn't have
// this statement, I would have to prefix `std::` in front of the items I
// wanted to use from that namespace.
using namespace std;

class Date {
private:  // These attributes are not accessible from outside the class's
          // methods
  int year;
  int month;
  int day;

public:
  Date() {}  // No need to do anything
  Date(int year, int month, int day) {
    if (month < 1 || month > 12 || day < 1 || day > 31)
      throw 0;  // Generate an exception (no more mixing of return values and
                // error handling
    // this is a special self-referencing pointer that you need to use
    // when the parameter name matches an attribute of the class
    this->year = year;
    this->month = month;
    this->day = day;
  }
  void set_year(int yyear) {  // Purposely use yyear here to show not needing
                              // to use the `this` pointer if the class's
                              // member variable is not shadowed
    year = yyear;
  }
  void set_month(int month) {
    if (month < 1 || month > 12)
      throw 0;  // The documentation should specify what these values mean
    this->month = month;
  }
  void set_day(int day) {
    if (month < 1 || month > 31)
      throw 0;  // The documentation should specify what these values mean
    this->day = day;
  }
  void output();  // Let's show an example of how to define the function
                  // outside of the class definition.
};


// Note the addition of `Date::` before the function name. This is so we can
// distinguish this output function as belonging to the class `Date` rather
// than any other class.
void Date::output() {
  // An object-oriented way to produce output.
  cout << year << "/" << month << "/" << day << endl;
}


int main() {
  Date date_a;  // This invokes the default constructor and provides me a Date
                // object that lives on the stack
  date_a.set_year(2013);
  date_a.set_month(7);
  date_a.set_day(16);
  date_a.output();

  Date *date_h = new Date();  // This invokes the default constructor, but by
  date_h->set_year(2013);     // using the new keyword the object comes from
  date_h->set_month(7);       // the heap. I am responsible for deallocating the
  date_h->set_day(16);        // object in that case.
  date_h->output();
  delete date_h;  // This is how you deallocate dynamically allocated memory in
                  // C++

  // The setters on the date object will throw exceptions if I attempt to do
  // any of the following:
  try {  // try...catch blocks are how you can handle exceptions
    date_a.set_month(13);
    date_a.set_day(32);
  }
  catch (int e) {
    cout << "ERROR: Value: " << e << endl;
  }
  date_a.output();
  // And the compiler won't allow me to do the following because the attribute
  // is private (exactly what I wanted to prevent)
  //date_a.month = 13;
  //date_a.day = 32;

  // Similar to before the constructor will throw an exception when executing
  // the following
  try {
    Date date_b(2013, 13, 32);
  }
  catch (int e) {
    cout << "ERROR: Value: " << e << endl;
  }
}
