#include <iostream>

using namespace std;

class Tuple {
public:
  Tuple();
  Tuple(int n);
  Tuple(const Tuple &other);
  const Tuple& operator =(const Tuple& other);
  virtual ~Tuple();
  virtual void output() const;
  void set_item(int index, int value);

  friend ostream& operator <<(ostream &outs, const Tuple &tuple);

 private:
  int num_items;
  int *items;
};
