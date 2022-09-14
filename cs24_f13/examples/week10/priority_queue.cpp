#include <iostream>
#include <queue>

using namespace std;

class Item {
public:
  string msg;
  int count;
  Item(string msg, int count): msg(msg), count(count) {}
  bool operator<(const Item &rhs) const {
    return count < rhs.count || (count == rhs.count && msg > rhs.msg);
  }
};

ostream &operator<<(ostream &outs, const Item &item) {
  return outs << "Item(msg=\"" << item.msg << "\", count=" << item.count << ")";
}


int main() {
  priority_queue<Item> pq;
  for (int i = 0; i < 10; ++i) {
    pq.push(Item("apple", i));
    pq.push(Item("zebra", i));
    pq.push(Item("dog", i));
  }

  while (!pq.empty()) {
    cout << pq.top() << endl;
    pq.pop();
  }
  return 0;
}
