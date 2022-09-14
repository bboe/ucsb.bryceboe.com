#include <iostream>
#include "vec.h"

using namespace std;

int main(int argc, char *argv[]) {
  /* The default constructor, and 3-param constructor need to be implemented */
  Vec3 vec_0;
  Vec3 vec_1(5.5, 6.6, 7.7);
  double tmp;

  /* Uncomment the following two lines when the getters are completed */
  //cout << "Individual components of 3-param: ";
  //cout << vec_1.get_x() << " " << vec_1.get_y() << " " << vec_1.get_z() << endl;

  /* Uncomment the following two lines when << is overloaded for ostream */
  //cout << "From default constructor: " << vec_0 << endl;
  //cout << "From 3-param constructor: " << vec_1 << endl;


  /*
   * Everything above here to should work before moving on
   */


  /* Uncomment the following lines when the setters are implemented */
  //cout << "Input three doubles: ";
  //cin >> tmp; vec_1.set_x(tmp);
  //cin >> tmp; vec_1.set_y(tmp);
  //cin >> tmp; vec_1.set_z(tmp);
  //cout << "Updated using setters: " << vec_1 << endl;

  /* Uncomment the following lines when >> is overloaded for istream */
  //cout << "Input three doubles: ";
  //cin >> vec_0;
  //cout << "Updated using >> overloading: " << vec_0 << endl;


  /* Uncomment the following lines when + is overloaded */
  //cout << "The previous two added together: " << (vec_0 + vec_1) << endl;
  //cout << "More addition: " << (vec_0 + vec_1 + vec_0 + vec_1) << endl;

  /* Uncomment the following lines when * is overloaded */
  //cout << "Simple multiplication: " << (vec_1 * 8) << endl;
  //cout << "More multiplication: " << (vec_1 * 3 * 2) << endl;
}
