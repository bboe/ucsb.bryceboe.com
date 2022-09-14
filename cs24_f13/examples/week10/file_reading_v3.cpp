#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Data {
public:
  int first;
  int second;
  string part1;
  string remainder;

  /* Construct a Data by parsing lines formatted like:

       NUM space NUM space SOME STRING HYPEN SOME MORE STRING
  */
  Data(istream &ins) {
    ins >> first;
    ins >> second;
    ins.ignore();  // Just another way to skip a character
    getline(ins, part1, '-');
    getline(ins, remainder);
  }
};

ostream& operator<<(ostream &outs, const Data &item) {
  outs << "(" << item.first << ", " << item.second << ") \"";
  outs << item.part1 << "\" \"" << item.remainder << "\"";
  return outs;
}


int main() {
  vector<Data> parsed;
  while (cin.peek() && cin.good())
    parsed.push_back(Data(cin));

  while (!parsed.empty()) {
    cout << parsed.back() << endl;
    parsed.pop_back();
  }
}
