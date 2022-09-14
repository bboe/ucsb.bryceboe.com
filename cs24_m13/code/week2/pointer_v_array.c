#include <stdio.h>

void takes_int_array(int foo[], int n) {
  printf("Enter takes_int_array\n");
  for (int i = 0; i < n; ++i) {
    printf("TIA(%d): %d\n", i, foo[i]);
  }
  printf("Exit takes_int_array\n");
}
void takes_int_pointer(int *foo, int n) {
  printf("Enter takes_int_pointer\n");
  for (int i = 0; i < n; ++i) {
    printf("TIP(%d): %d\n", i, foo[i]);
  }
  printf("Exit takes_int_pointer\n");
}

/* Swap two integer values (must take pointers in order to change the data) */
void swap(int *a, int *b) {
  printf("Swapping %d with %d\n", *a, *b);
  int tmp = *a;
  *a = *b;
  *b = tmp;
}


int main() {
  int nums[] = {4, 8, 15, 16, 23, 42};
  int i = 255, j = -255;

  // Pass an array to functions that expect an array
  takes_int_array(nums, sizeof(nums) / sizeof(int));
  takes_int_pointer(nums, sizeof(nums) / sizeof(int));

  // Pass the address of a single integer to functions that expect an array
  takes_int_array(&i, 1);
  takes_int_array(&j, 2);

  swap(&i, &j);  // Swap two integers by passing their address

  takes_int_array(nums, 6);
  swap(&nums[1], &nums[2]);  // The same procedure for swapping items of array

  takes_int_array(nums, 6);

  swap(&j, nums);  // Swap an integer with the pointer to an array (the first
                   // element of the array)

  return 0;
}
