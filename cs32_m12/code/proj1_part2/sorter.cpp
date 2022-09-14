#include <iostream>
#include "helper.h"
using namespace std;

const bool DEBUG = false;

/* comparison_func is a type that represents a pointer to a compare function */
typedef int (*comparison_func)(string, string);
/* sort_func is be a type that represents a pointer to a sorting function */
typedef void (*sort_func)(string *, int, comparison_func);


/* Reads an integer, and only an integer, from the input stream. Stores the
   result in integer. Returns true if only an integer was read from the
   line. Returns false otherwise.

   Function adapted from example at https://stackoverflow.com/a/8631962/176978
*/
bool read_integer(int &integer) {
  int success = true;
  cin >> integer;

  /* Verify that an integer was read, and we're at the end of the line. */
  if (cin.fail() || cin.get() != '\n') {
    success = false;
    cin.clear();

    /* Read whatever data is left on the line. */
    while (cin.get() != '\n');
  }
  return success;
}


/* Prompt the user for the desired sort algorithm function

   Returns a pointer to the desired function.
*/
sort_func algorithm_selection() {
  int selection = -1;
  string options[] = {"bubble sort", "insertion sort", "selection sort",
                      "mergesort"};
  sort_func algorithms[] = {bubble_sort, insertion_sort, selection_sort,
                            mergesort};
  int num_options = 4;

  while (selection < 0 || selection >= num_options) {
    cout << "Which sort algorithm would you like to use?\n";
    for (int i = 0; i < num_options; ++i)
      cout << "  " << i << ". " << options[i] << endl;
    if (!read_integer(selection)) {
      cout << "Invalid selection, try again.\n";
      selection = -1;
    }
  }
  cout << options[selection] << " selected\n";
  return algorithms[selection];
}


/* Prompt the user for the desired comparison function

   Returns a pointer to the desired function.
*/
comparison_func comparison_selection() {
  int selection = -1;
  string options[] = {"default", "string length", "numerical"};
  comparison_func comparisons[] = {default_comparison, length_comparison,
                                   numerical_comparison};
  int num_options = 3;

  while (selection < 0 || selection >= num_options) {
    cout << "Which comparison function would you like to use?\n";
    for (int i = 0; i < num_options; ++i)
      cout << "  " << i << ". " << options[i] << endl;
    if (!read_integer(selection)) {
      cout << "Invalid selection, try again.\n";
      selection = -1;
    }
  }
  cout << options[selection] << " selected\n";
  return comparisons[selection];
}


string *read_lines(int &n) {
  int array_size = 8;
  string *retval = new string[array_size];
  n = 0;
  while (!cin.eof()) {
    /* Resize the array if needed */
    if (n == array_size) {
      array_size *= 2;
      string *tmp = new string[array_size];
      copy(retval, retval + n, tmp);
      delete [] retval;
      retval = tmp;
    }

    cin >> retval[n];
    if (!cin.fail() && retval[n] != "")
      /* When the read succeeds, only consider non-blank lines */
      ++n;
  }
  return retval;
}


int main(int argc, char *argv[]) {
  int num_lines;
  sort_func sort = algorithm_selection();
  comparison_func comparison = comparison_selection();
  string *the_strings = read_lines(num_lines);
  sort(the_strings, num_lines, comparison);

  /* output the results */
  for (int i = 0; i < num_lines; ++i)
    cout << the_strings[i] << endl;

  return 0;
}
