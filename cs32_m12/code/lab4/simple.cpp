#include <iostream>
using namespace std;

class Parent {

public:
  Parent() : age(45) { }

  void setAge(int years) {
     cout << "SetAge method from Parent class" << endl;
     age = years;
  }

  int getAge() { return age; }

  int increaseAge() {
     cout << "This is Parent::increaseAge: My age: " << age
          << " And now I am one year older" << endl;
     return age = age + 1;
  }

protected:
  int age;

private:
  int ssn; //Social Security Number
};

class Child : public Parent {

public:
  Child() { age = 7; }

  int change() {
    age = increaseAge();
    return age;
  }

  void setAge(int years) {
    age = years;
    Parent::setAge(years);
    cout << "This is Child::setAge" << endl;
  }

  void printAge() {
      cout << "Parent::age " << Parent::age << endl;
      //A1// cout << "getAge() " << getAge() << endl;
      //A2// cout << "Parent::getAge() " << Parent::getAge() << endl;
      //A3// cout << "age " << age << endl;
 }

  /*** C1 ****/
  /*
  void printSSN()
  {
    cout << "My SSN number is: " << ssn << endl;
  }
  */
};

int main() {
  cout << "sizeof(Parent) = " << sizeof(Parent) << endl;
  cout << "sizeof(Child) = "
       << sizeof(Child) << endl;

  Child C;

  /*** B1 ***/
  /*
  C.change();
  C.printAge();
  */

  /*** B2 ***/
  /*
  C.increaseAge();
  C.printAge();
  */

  /*** B3 ***/
  /*
  C.Parent::setAge(50); //Invoke parent version
  C.setAge(55);
  C.printAge();
  */

  /*** B4 ***/
  /*
  Parent P;

  P.increaseAge();
  P.printAge();
  */
}
