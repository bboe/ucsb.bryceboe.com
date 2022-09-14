#include <iostream>
using namespace std;

extern const bool DEBUG;

/* Comparison functions */
int default_comparison(string, string);
int length_comparison(string, string);
int numerical_comparison(string, string);

/* Sorting algorithms */
void bubble_sort(string *, int, int (*)(string, string));
void insertion_sort(string *, int, int (*)(string, string));
void selection_sort(string *, int, int (*)(string, string));
void mergesort(string *, int, int (*)(string, string));
