#include "helper.h"

/* Compare based on default string comparison

Returns:
 a negative value, when the lhs is less than the rhs
 zero, when the lhs is equal to the rhs
 a positive value, when the rhs is less than the lhs
*/
int default_comparison(string lhs, string rhs) {
  if (DEBUG)
    cout << "Default compare: " << lhs << " and " << rhs << endl;
  return lhs.compare(rhs);
}


/* Compare based on the length of the string

Returns:
 a negative value, when the lhs is shorter than the rhs
 zero, when the lhs is of equal length to the rhs
 a positive value, when the rhs is shorter than the lhs

As a secondary sort, use the default sorting logic.
*/
int length_comparison(string lhs, string rhs) {
  if (DEBUG)
    cout << "Length compare: " << lhs << " and " << rhs << endl;
  int result = lhs.size() - rhs.size();
  if (!result)
    result = lhs.compare(rhs);
  return result;
}


/* Compare according to numerical (int) values

Returns:
 a negative value, when the lhs is less than the rhs
 zero, when the lhs is equal to the rhs
 a positive value, when the rhs is less than the lhs

Non-numeric strings should be greator than all numeric strings.

Non-numeric strings should be compared using the default string compare
function.
*/
int numerical_comparison(string lhs, string rhs) {
  if (DEBUG)
    cout << "Numerical compare: " << lhs << " and " << rhs << endl;
  // TODO: Implement this function
  return lhs.compare(rhs);
}


void bubble_sort(string *string_array, int n, int (*compare)(string, string)) {
  if (DEBUG)
    cout << "Performing bubble sort on " << n << " items.\n";
  // TODO: Implement this function
}


void insertion_sort(string *string_array, int n,
                    int (*compare)(string, string)) {
  if (DEBUG)
    cout << "Performing insertion sort on " << n << " items.\n";
  // TODO: Implement this function
}


void selection_sort(string *string_array, int n,
                    int (*compare)(string, string)) {
  if (DEBUG)
    cout << "Performing selection sort on " << n << " items.\n";
  // TODO: Implement this function
}


void mergesort(string *string_array, int n, int (*compare)(string, string)) {
  if (DEBUG)
    cout << "Performing mergesort on " << n << " items.\n";
  // TODO: Implement this function
}
