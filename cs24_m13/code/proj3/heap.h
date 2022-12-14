#include <algorithm>
#include <vector>


/* This class is internally used by the MaxHeap class. You should not need to
   make instances of it directly.
 */
template <class T>
class PriorityContainer {
public:
  int priority;
  T item;
  PriorityContainer(T item, int priority): item(item), priority(priority) {}
  bool operator<(const PriorityContainer<T> &other) const {
    return priority < other.priority;
  }
};


/* Provide a MaxHeap class that is a simple wrapper around the data structures
   and operations provided in the C++ standard template library (STL).
 */
template <class T>
class MaxHeap {
private:
  std::vector<PriorityContainer<T> > vector;
public:
  MaxHeap(): vector() {}
  void insert(T item, int priority) {
    vector.push_back(PriorityContainer<T>(item, priority));
    std::push_heap(vector.begin(), vector.end());
  }
  /* Return a boolean indicating whether or not the heap is empty. */
  bool empty() {
    return vector.empty();
  }
  /* Return (but do not remove) the highest priority item from the heap. */
  T peek() {
    return vector.front().item;
  }
  /* Remove and return the highest priority item from the heap. */
  T remove() {
    std::pop_heap(vector.begin(), vector.end());
    T retval = vector.back().item;
    vector.pop_back();
    return retval;
  }
};
