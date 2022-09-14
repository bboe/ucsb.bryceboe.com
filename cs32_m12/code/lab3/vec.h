#include <iostream>

using namespace std;

/* In this class you will need to declare:
   - a default constructor
   - a constructor that takes three doubles
   - getters and setters for each varaible
   - << operator for ostream
   - >> operator for istream
   - + operator for Vec3 and Vec3
   - * operator for Vec3 and double

   The implementation for each function should go in vec.cpp.
*/
class Vec3 {
 public:

  /* Do not modify the following line. If you see the message "Pass by value
     fail." in your output, it means you aren't using a reference somewhere
     that you should be. */
  Vec3(const Vec3 &other) { cout << "Pass by value fail."; }

 private:
  double x;
  double y;
  double z;
};
