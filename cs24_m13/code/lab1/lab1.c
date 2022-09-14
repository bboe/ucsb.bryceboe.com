#include <stdio.h>
#include <stdlib.h>

// you may NOT #include the string library!

// forward declarations
int stringlength(char *str);
int countchars(char c, char *str);
char *safestringconcat(char *str1, char *str2);


int main(int argc, char **argv) {

  char *sa[] = {"Hello, how are you?",
                "I.m just fine, thank you.",
                "Monkeys are awesome.",
                "I complete agree, though I also really like platypi."};
  int i = 4;
  int size;
  FILE *file;
  char buf[256];

  printf("Enter a test string.\n");
  printf("To quit, make the first letter 'Q'\n");
  fgets(buf, 256, stdin);
  while(buf[0] != 'Q') {
      char *str;
      printf("String: %s", buf);
      printf("The length of string, counting return character: %d\n",
             stringlength(buf));

      printf("There are %d a's in the string\n",
             countchars('a', buf));

      printf("There are %d c's in the string\n",
             countchars('c', buf));

      str = safestringconcat(buf, sa[i++ % 4]);
      if (str == NULL)
        printf("safestringconcat not yet implemented\n");
      else {
        printf("Safe concat returned: %s\n", str);
        free(str);
      }

      printf("Enter a test string.\n");
      printf("To quit, make the first letter 'Q'\n");
      fgets(buf, 256, stdin);
    }
  return 0;
}


/* stringlength
 * input: str, pointer to a string
 * output: integer representing the length of string str,
 * not counting the terminating character.
 *
 * You may NOT call ANY functions within this function.
 */
int stringlength(char *str) {
  // count the number of characters in str.

  return -1;
}


/* countchars
 * inputs: character c, string str
 * output:  The number of instances of c in the string str
 * You may NOT call ANY function calls within this function.
 */
int countchars(char c, char *str) {
  // count the number of times c is found in str

  return -1;
}


/* safestringconcat
 * inputs: two strings
 * output: a new string containing the two input strings
 * concatenated together
 * YOu may ONLY call functions you wrote in this file
 */
char *safestringconcat(char *str1, char *str2) {
  // allocate space for your new string

  // copy str1 into the beginning of the string


  // copy str2 into the end of the string


  // return the resulting string
  return NULL;
}
