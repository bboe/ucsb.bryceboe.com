#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>

/* In this class you will need to declare:
   - a constructor that specifies the size of the vector
   - a constructor that takes pointer to int array, and its size
   - a destructor for MyVec
   - getters and setters for vector elements
   - add_immediate method for MyVec
   The implementation for each function should go in vec.cpp.
*/
class MyVec {
 public:

  /* Do not modify the following line. If you see the message "Pass by value
     fail." in your output, it means you aren't using a reference somewhere
     that you should be.
  */
  MyVec(const MyVec &other) { std::cout << "Pass by value fail.\n"; }

  MyVec(int size);
  MyVec(const int *array, int size);
  ~MyVec();

  int get_element(int position);
  void set_element(int position, int value);

  /* Add the values of other to the values in the called-upon MyVec object.

     When the vectors are of different sizes, only iterate over the minimum
     number of shared items.
  */
  void add_immediate(const MyVec &other);

 private:
  int *vector;  // This should point to the array you allocate
  int vector_size;  //vector size
};

#endif  /* MYVECTOR_H */
