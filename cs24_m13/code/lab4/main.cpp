#include <iostream>
#include "vec.h"

using namespace std;

int main(int argc, char *argv[]) {
  int *init_array = NULL;
  int tmp;
  int size_0, size_1;

  /* Uncomment when the first constructors is implemented */
  /*
  cout << "Enter vector_0 size" << endl;
  cout.flush();
  cin >> size_0;
  MyVec vec_0(size_0);
  */

  /* Uncomment when the second constructors is implemented */
  /*
  cout << "Enter vector_1 size" << endl;
  cout.flush();
  cin >> size_1;
  if (size_1 > 0) {
    init_array = new int[size_1];
    for (int i = 0; i < size_1; i++) {
      init_array[i] = i + 5;
    }
  }
  MyVec vec_1(init_array, size_1);
  delete []init_array;
  */

  /* Uncomment when the getters are completed */
  /*
  cout << "vec_1 components:" << endl;
  cout.flush();
  for (int i = 0; i < size_1; i++) {
    cout << vec_1.get_element(i) << " ";
  }
  cout << endl;
  */

  /* Uncomment the following lines when the setters are implemented */
  /*
  cout << "Input " << size_0 << " integers to initialize vec_0:" << endl;
  for (int i = 0; i < size_0; i++){
    cin >> tmp;
    vec_0.set_element(i, tmp);
  }
  cout << "vec_0 components:" << endl;
  cout.flush();
  for (int i = 0; i < size_0; i++){
    cout << vec_0.get_element(i) << " ";
  }
  cout << endl;
  */

  /* Uncomment the following lines when add_immediate method is completed */
  /*
  cout << "Adding vec_1 to vec_0: vec_0 now is:"<< endl;
  cout.flush();
  vec_0.add_immediate(vec_1);
  for (int i = 0; i < size_0; i++){
    cout << vec_0.get_element(i) << " ";
  }
  cout << endl;
  cout << "Adding vec_1 to new vec_0: vec_0 now is:" << endl;
  cout.flush();
  vec_0.add_immediate(vec_1);
  for (int i = 0; i < size_0; i++){
    cout << vec_0.get_element(i) << " ";
  }
  cout << endl;
  */

  return 0;
}
