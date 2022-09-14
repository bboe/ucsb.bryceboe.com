#include <stdio.h>

int main() {
  /* Write a file containing the lower bytes of EOF */
  FILE *output = fopen("tmp", "w");
  fputs("<FILE>", output);  // Write a message
  fputc((char)EOF, output);  // Write lower byte of EOF
  fputs("</FILE>\n", output);  // Write a message
  fclose(output);


  /* Read and output the file character-by-character into an int */
  printf("Read into int (outputs the entire file)\n");
  FILE *input = fopen("tmp", "r");
  int int_c;
  while ((int_c = fgetc(input)) != EOF)
    fputc(int_c, stdout);
  fclose(input);

  /* Read and output the file character-by-character into a char */
  printf("Read into char (thinks '\\xFF' is EOF)\n");
  input = fopen("tmp", "r");
  char char_c;
  while ((char_c = fgetc(input)) != EOF)
    fputc(char_c, stdout);
  fclose(input);

  return 0;
}
