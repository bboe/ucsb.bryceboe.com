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
  Data(int first, int second, string part1, string remainder):
    first(first), second(second), part1(part1), remainder(remainder) {}
};

ostream& operator<<(ostream &outs, const Data &item) {
  outs << "(" << item.first << ", " << item.second << ") \"";
  outs << item.part1 << "\" \"" << item.remainder << "\"";
  return outs;
}


/* Parses lines formatted like:

   NUM space NUM space SOME STRING HYPEN SOME MORE STRING

 */
Data parse_line() {
  int first, second;
  string part1, remainder;
  if (!(cin >> first))
    throw 1;
  cin >> second;
  cin.get();  // Ignore the space
              // alt(1): cin.ignore();
              // alt(2): getline(cin, part1, ' ');
  getline(cin, part1, '-');
  getline(cin, remainder);
  return Data(first, second, part1, remainder);
}


int main() {
  vector<Data> parsed;
  while (cin) {
    try {
      parsed.push_back(parse_line());
    }
    catch (int e) {}
  }

  while (!parsed.empty()) {
    cout << parsed.back() << endl;
    parsed.pop_back();
  }
}
