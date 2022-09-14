---
title: Lab 4 &raquo; CS24 Fall 2013
---
{%- assign base = site.baseurl | append: "/cs24_f13" -%}
## Lab 4: File Input and Output

Note that you have until Tuesday night to complete this lab.

### Goals for this lab

By the time you have completed this lab, you should:

* know what a FILE stream is
* know the difference between stdin, stdout, and stderr
* be able to read from files on disk
* be able to parse and validate an input stream
* have reinforced using the List ADT

The purpose of this lab is to have you demonstrate reading and parsing file
input streams.

### Lab Pairing

For this lab you may work with a partner. To facilitate your submissions as a
pair you __MUST__ pair up using the submission system. When you visit the
project page from where you can view all your submission you should see a link
to a page where you can join a group. Of the two people in the group, one of
you must invite the other, and the other must confirm the invitation. Once you
group up, any submissions that either you, or your partner have already made
will be visible to each other in addition to all future submissions.


### Lab Preparation

At this point, everyone should have a COE account. If you do not, you need to
make that a priority and should partner up with someone who already has an
account.

Before you begin, let's prepare a cs24 directory in your home directory if you
don't already have one. In that directory we'll create a subdirectory for the
files for this lab. Note that these instructions assume you are using either a
CSIL machine or one of the lab machines:

After logging in, create the directory (assuming you haven't already done so):

```sh
mkdir -p cs24/lab4
```

Change the permissions of the cs24 directory such that only your account can
access the files inside this directory. This step is __incredibly__
important. If omitted, other students can peek at your work and you may be held
partially responsible. It should also go without saying that you may __not__
give other students access to your account. If you've done that in the past
please [change your password](https://accounts.engr.ucsb.edu/maintain/login) at
this time.

```sh
chmod 700 cs24
```

Change into the lab4 directory and copy the files you will need for this lab:

```sh
cd cs24/lab4
cp -r ~bboe/public_html/cs24_f13/code/lab4/* .
```


### The provided files

In your directory you will find the following files:

* linked_list.o and list.h -- The combination of these files allow you to make
  use of `struct List` and the associated functions.

* Makefile - This file specifies how the `group_by` binary should be
  compiled.

* tests/MIXED_INPUT - A sample input file which contains both valid lines and
  invalid lines.

* tests/MIXED_OUTPUT - The combined output (stderr and stdout) that should be
  produced when running `group_by` on the MIXED_INPUT input file.

* tests/SAMPLE_INPUT - A simple input file that contains only valid input
  lines.

* tests/SAMPLE_OUTPUT - The output that should be produced when running
  `group_by` on the SAMPLE_INPUT input file.


### Your task

Your task is to write a program, `group_by.c`, that:

0. Reads lines from an input stream (either from stdin or a named file)
0. Parses valid lines for `[AGE] [NAME]`
0. Discards invalid lines with _the_ appropriate error message
0. Adds the name to the end of a list for the associated age
0. For each valid age (1-99 inclusive) output the age and list of names
   associated with that age if there are any.
0. Deallocates any memory allocated before exiting.

For instance, if the input is the contents of `SAMPLE_INPUT`:

    57 George Washington
    61 John Adams
    57 Thomas Jefferson
    57 James Madison
    58 James Monroe
    57 John Quincy Adams
    61 Andrew Jackson
    54 Martin Van Buren
    68 William Harrison
    51 John Tyler

then the output should be:

    Age 51
      0: John Tyler
    Age 54
      0: Martin Van Buren
    Age 57
      0: George Washington
      1: Thomas Jefferson
      2: James Madison
      3: John Quincy Adams
    Age 58
      0: James Monroe
    Age 61
      0: John Adams
      1: Andrew Jackson
    Age 68
      0: William Harrison


### Compiling and executing your program

Type `make` to compile your program. On successful compilation the file
`group_by` should be created.

The program you create needs to execute in two ways. The first is simply via:

    $ ./group_by

With no arguments, your program should read lines from the standard input
stream (stdin).

The second way is by providing a named file as the only argument to the
program:

    $ ./group_by some_input_filename

In this case your program should (1) attempt to read lines from the named file
`some_input_filename` and gracefully fail (exactly as described below) if the
file cannot be opened.

With any other number of arguments your program should output `Usage: group_by
[FILENAME]\n` to the standard error stream.


### Standard FILE streams

In previous labs we have utilized command line arguments to give our programs
input. Another common way to take input in a program is through an input
stream, likewise all program output is handled through an output
stream. Simply, a stream is a pointer to a `FILE` structure, or `FILE *` that
can be _readable_ and/or _writable_. An input stream is a stream that is
readable and an output stream is a stream that is writable.

Any time you have the code `#include <stdio.h>` three global streams are made
available. Those are:

* stdin - A read-only stream (from the program's point of view) that represents
  input to the program. Under normal execution this stream is provided via
  keyboard input.

* stdout - A write-only stream that is used to produce normal program
  output. You implicitly use the stdout stream every time you make a call to
  `printf`.

* stderr - A write-only stream that is typically used to produce error
  output. Under normal program execution the `stderr` stream is printed to the
  terminal along with the `stdout` stream.


### Outputting to writable streams

We already know how to output to `stdout` using `printf`, but how would we
output to `stderr`? It turns out that `printf(...)` is essentially the same as
`fprintf(stdout, ...)`
[[ref](https://pubs.opengroup.org/onlinepubs/000095399/functions/printf.html)].
Thus if we wanted to output "hello world\n" to `stderr` we could write:

```c++
fprintf(stderr, "hello world\n");
```

Likewise let's assume we had another writable stream assigned to the variable
`FILE *my_stream`. We could provide output to that stream by:

```c++
fprintf(my_stream, "hello world\n");
```

Three other useful functions for writing to stream are
[fputc](https://pubs.opengroup.org/onlinepubs/000095399/functions/fputc.html),
for writing single characters (includes `'\0'`);
[fputs](https://pubs.opengroup.org/onlinepubs/000095399/functions/fputs.html),
for writing complete c-strings without `%?` replacement; and
[fwrite](https://pubs.opengroup.org/onlinepubs/000095399/functions/fwrite.html),
for writing a fixed amount of data from a buffer (includes `'\0'`).

__WARNING__: As the clang compiler will warn you, you should never call any
form of `printf` with a c-string that is not hard-coded in your program
code. If you only want to output the contents of a c-string (let's call it
`str`) to stream `stream`, use either `fputs(str, stream)` or `fprintf(stream
"%s", str)`. Using `fprintf(stream, str)` makes your program vulnerable to
[format string
exploits](https://en.wikipedia.org/wiki/Uncontrolled_format_string).


### Inputting from readable streams

There are a number of functions to read input from readable streams.

#### fgetc

The simplest is
[fgetc](https://pubs.opengroup.org/onlinepubs/000095399/functions/fgetc.html)
that reads in one character at a time. Astute readers will not that rather than
return a `char` type, this function returns an `int` type. The reason is that
`fgetc` needs some value to indicate that an error has occurred and both 0 and
-1 (255 unsigned) are valid characters. Thus `fgetc` returns an integer and
uses the additional bytes for error conditions. For instance `fgetc` will
return the magic value `EOF` when the stream has no more data. `EOF` stands for
end-of-file.

The following is a simple program that _echos_, or repeats the data it reads
from the standard input stream to the standard output stream.

```c++
#include <stdio.h>
int main() {
  int c;
  while ((c = fgetc(stdin)) != EOF) {
    fputc(c, stdout);
  }
  return 0;
}
```

When running this program, you can terminate the keyboard input stream (thus
triggering `EOF`) by pressing `ctrl+d` (you may need to press it
twice if you've already input characters on the line).

#### fgets

Another useful function is
[fgets](https://pubs.opengroup.org/onlinepubs/000095399/functions/fgets.html).
`fgets` attempts to read an entire line (up to and including a newline, `'\n'`)
into a pre-allocated `char` array (often referred to as a buffer) and then
null-terminates the buffer so that it can be treated as a c-string. __NOTE__:
`fgets` will read null-terminating characters, `'\0'`, just like any other
character.

The following is a nearly functionally identical example of the former __echo__
example, using `fgets` and `fputs` rather than `fgetc` and `fputc`:

```c++
#include <stdio.h>
#define BUFFER_SIZE 64
int main() {
  char buf[BUFFER_SIZE];
  while (fgets(buf, BUFFER_SIZE, stdin) != NULL) {
    fputs(buf, stdout);
  }
  return 0;
}
```

There are three primary differences between this example and the former. The
obvious one is that the former example reads character-by-character, where as
the second example attempts to read line-by-line.

The second has to do with the `BUFFER_SIZE` constant defined. An array, by
definition, has a fixed sized, however, a line can be arbitrarily long. Thus to
prevent buffer overflows, `fgets` requires the programmer to specify the size
of the buffer to copy the data to, and copies in at most that size - 1
bytes. The last byte is used to copy the null-terminating character.

The final difference is that `fgets` returns NULL when there is no more data to
read, i.e., it is at the end of the stream.

#### Other read functions

In addition to
[fgetc](https://pubs.opengroup.org/onlinepubs/000095399/functions/fgetc.html)
and
[fgets](https://pubs.opengroup.org/onlinepubs/000095399/functions/fgets.html) is
[fread](https://pubs.opengroup.org/onlinepubs/000095399/functions/fread.html).
`fread` is the complement function to `fwrite` which allows read an fixed
amount of data into a buffer (includes '\0').

### Working with named files

So far we've only looked at working with `stdin`, `stdout`, and `stderr`. Often
it is useful to read or write to a named file. In C, we can think of the `FILE`
structure and its associated functions as an ADT for handling input and
output. Thus, just like our list ADT, there are similar constructor and
destructor functions for named files. Those are
[fopen](https://pubs.opengroup.org/onlinepubs/000095399/functions/fopen.html)
and
[fclose](https://pubs.opengroup.org/onlinepubs/000095399/functions/fclose.html)
respectively.

#### Echo from a named file

Below is a simple example of the character-by-character `echo` program, this
time echoing data from the named file `foobar` rather than standard input:

```c++
#include <stdio.h>
int main() {
  FILE *input = fopen("foobar", "r");
  int c;
  while ((c = fgetc(input)) != EOF) {
    fputc(c, stdout);
  }
  fclose(input);
  return 0;
}
```

Note that we use `"r"` as the second argument to `fopen` to indicate open the
file for reading only. Also, note that the program will segfault if the file
`foobar` does not exist relative to the present working directory at
runtime. Just like our `list_construct` function, `fopen` will return NULL if
the `FILE` structure cannot be _created_, or (opened in this case).

#### Gracefully handling `fopen` errors

There are actually a number of reasons why `fopen` might fail. The most obvious
is the file does not exist (when opening for reading), but another failure case
is that the user does not have permission to open the file. In __C__ there is a
convenient
[perror](https://pubs.opengroup.org/onlinepubs/009695399/functions/perror.html)
function to output (to standard error) an appropriate error message.

Let's update our example to gracefully handle errors with opening the file:

```c++
#include <stdio.h>
int main() {
  FILE *input = fopen("foobar", "r");
  if (input == NULL) {
    perror("foobar");
    return 1;
  }
  int c;
  while ((c = fgetc(input)) != EOF) {
    fputc(c, stdout);
  }
  fclose(input);
  return 0;
}
```

Now if when you run the program, the file `foobar` does not exist the following
will be output to the standard error stream:

    foobar: No such file or directory

Likewise, if `foobar` exists, but it is not readable, the following will be
output:

    foobar: Permission denied


#### Echo to a named file

The previous example took input from a named file and output it to the standard
output stream. The following example, takes input from the standard input
stream (normally keyboard) and outputs it to the named file "foobar". Note that
you should read the full
[fopen](https://pubs.opengroup.org/onlinepubs/000095399/functions/fopen.html)
description to see what happens when you open files for writing that already
exist and how to get the desired behavior.

```c++
#include <stdio.h>
int main() {
  FILE *output = fopen("foobar", "w");
  if (output == NULL) {
    perror("foobar");
    return 1;
  }
  int c;
  while ((c = fgetc(stdin)) != EOF) {
    fputc(c, output);
  }
  fclose(output);
  return 0;
}
```

Remember that to close the keyboard input stream you should hit `ctrl+d` on
your keyboard.


#### Reading and parsing lines

You should use `fgets` to read in each line of the file. You are to assume that
no lines are longer than 63 characters (include the newline, if available) thus
a buffer of size 64 is sufficient to store the line data plus the null
terminating character that `fgets` will automatically add. __NOTE__: You do
__NOT__ need to check for lines longer than 63 characters (though I encourage
you to think about how you might do that).

Each valid line is of the format `AGE SPACE NAME`. Is a base-10 number in the
range 1-99 (inclusive). Note that `0001` and `00000000099` are valid ages and
should be treated just like `1` and `99` respectively, but you shouldn't have
to do anything special to handle those numbers (if you are you're making things
too complicated for yourself). The SPACE is a _single_ literal SPACE, `' '`,
character. Finally, NAME is all characters following the SPACE character up to
the new line character `'\n'` (if one exists).

Any lines which do not match this format should result in a message to the
standard error stream containing the line that resulted in the error. The exact
format string message you are to use is:

    "Ignored invalid line: %s\n"

See the `MIXED_INPUT` and `MIXED_OUTPUT` file for examples of invalid output.


#### Splitting c-strings

A very useful function for parsing c-strings is the
[strtok](https://pubs.opengroup.org/onlinepubs/009695299/functions/strtok.html)
function. Below is an example program that splits up the individual terms
(separated by either a space character, `' '`, or a new line character,
`'\n'`).

```c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void output_terms(char *msg) {
  char *orig = strdup(msg);  // Save a copy as strtok is destructive
  char *token_arg = msg;  // Non-null only for the first call to strtok
  char *token;
  int index = 0;
  // Loop over each token (split on either space or new line characters)
  while ((token = strtok(token_arg, " \n")) != NULL) {
    token_arg = NULL;  // Subsequent strtok calls require this to be NULL
    printf("Token %d: %s\n", index++, token);
  }
  printf("The original message was: %s\n", orig);
  free(orig);
}

int main() {
  char line1[] = "1 23 456 789\n";
  char line2[] = "hello world";  // Note that this does not end with '\n'
  output_terms(line1);
  output_terms(line2);
  return 0;
}
```

Note that `strtok` is destructive thus we use
[strdup](https://pubs.opengroup.org/onlinepubs/009695299/functions/strdup.html)
to make a copy of the original string in order to use it afterwards.


#### Storing lists of names by ages

Aside from the task of parsing data, this is the primary challenge for this lab
(don't discuss this part outside of your group except with the instructor and
TAs). You are provided with a complete implementation of the List ADT, thus
allowing you to `#include "list.h"`.

You _should_ store each name in a list corresponding to a single age, and use
the appropriate output function to output the contents of the list. The
question you must answer is how do you manage a list for each age such that
after reading all the input, the names associated with each age are output in
age order? Good luck!


### Submitting the assignment

Only one person in a group need submit the assignment but make sure that both
you and your partner can view the submission on the submission site. If you
cannot, you need to complete the making a group process. Please review the
[submission instructions]({{ base }}/submission) as needed. Note that you may resubmit
this assignment as many times as necessary up until the deadline.
