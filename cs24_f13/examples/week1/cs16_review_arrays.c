int main() {

  // Uninitialized Arrays
  int unit_int[10];  // requires 40 bytes
  char unit_char[1024];  // requires 1KB (1024 bytes)

  // Fully initialized Arrays (size not required)
  int init_int[] = {-1, 0, 1, 0xDEADBEEF, 0b00010};
  char init_char[] = "hello world";
  char init_char2[] = {'a', 'b', 99, 'd', 'e', '\0'};

  return 0;

  // Compile via clang - g cs16_review_arrays.c

  /* Debug via gdb a.out
       Set a breakpoint on the return statement (line 12)
         b 12
       Begin debugging (will hit the breakpoint):
         r
       Inspect the values stored at each variable
         x/10x unit_int   # displayed as hex (x)
         x/10d unit_int   # displayed as decimals (d)
         x/32c unit_char  # displayed as characters (c)
         x/5x init_int
         x/5d init_int
         x/12c init_char
         x/6c init_char2
       Alternatively, a naive representation can be obtained via `p varname`
         p unit_int
         p unit_char
         p init_int
         p init_char
         p init_char2
  */

}
