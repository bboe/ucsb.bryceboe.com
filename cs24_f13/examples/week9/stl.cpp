#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

/* To compile this program you need to add -std=c++11 to the compile line */


using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "Usage: ./a.out ARG...\n";
    return 1;
  }

  // For each data structure we're going to add all the elements, iterate over
  // those elments sorted if possible, and then iterate over them again in a
  // destructive manner.

  // A vector is a dynamic-array similar to what you implemented for project 1.
  // There are other ways to interact with the vector, this is just an example
  cout << "Construct vector\n";
  vector<string> v;
  cout << "Add items to vector\n";
  for (int i = 1; i < argc; ++i)
    v.push_back(argv[i]);
  cout << "Sort the vector's items\n";
  sort(v.begin(), v.end());
  cout << "Iterate over the vector's items: ";
  for (vector<string>::iterator iter = v.begin(); iter != v.end(); ++iter)
    cout << *iter << " ";  // An interator is a "pointer-like" object
  cout << endl;
  cout << "Destructively iterate over the vector's items: ";
  while (!v.empty()) {
    cout << v.back() << " ";
    v.pop_back();  // This does not return a value (silly I know)
  }
  cout << endl;


  // A stack class as you would expect
  cout << "Construct stack\n";
  stack<string> s;
  cout << "Add items to stack\n";
  for (int i = 1; i < argc; ++i)
    s.push(argv[i]);
  cout << "Destructively iterate over the stack's items: ";
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();  // This does not return a value (silly I know)
  }
  cout << endl;


  // A queue class as you would expect
  cout << "Construct queue\n";
  queue<string> q;
  cout << "Add items to queue\n";
  for (int i = 1; i < argc; ++i)
    q.push(argv[i]);
  cout << "Destructively iterate over the queue's items: ";
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();  // This does not return a value (silly I know)
  }
  cout << endl;

  // The unordered_map is a hash table
  cout << "Construct hash table, mapping the value to itself\n";
  unordered_map<string, string> h;
  cout << "Add items to hash table\n";
  for (int i = 1; i < argc; ++i)
    h[argv[i]] = argv[i];
  cout << "Iterate over the vector's items: ";
  // auto is a special keyword that in c++11 will automatically determine the
  // type. Below it is equivalent to unordered_map<string, string>::iterator
  for (auto i = h.begin(); i != h.end(); ++i)
    cout << i->first << ":" << i->second << " ";
  cout << endl;
  cout << "Destructively iterate over the hash tables's items: ";
  while (!h.empty()) {
    auto tmp = h.begin();
    cout << tmp->first << ":" << tmp->second << " ";
    h.erase(tmp);
  }

  return 0;
}
