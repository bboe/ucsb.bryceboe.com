---
title: Project 1, Part 2 &raquo; CS32 Summer 2012
---
{%- assign base = site.baseurl | append: "/cs32_m12" -%}
## Project 1, Part 2: Sorting algorithm implementations

### Motivation

The purpose of this part of the assignment is for you to implement and test a
few of the sorting algorithms we have described in class. By doing so, you
should gain a complete knowledge of how the sorting algorithms work.

### Project Setup

I am providing you with the code that handles all the input and output that the
feedback system will use to test your sorting algorithms. To setup this project
change into whatever directory you plan on working in (make sure its
permissions are such that others cannot access your files) and run the
following:

```sh
cp ~cs32/public_html/code/proj1_part2/* .
```

Running this command will provide you with four files in your current
directory:

__helper.cpp__: This is the file that you will need to edit to provide the
correct implementation for the functions described in the next section.

__helper.h__: This is the header file that specifies the interface to the
functions contained within helper.cpp.

__Makefile__: This file specifies the commands to build the project. By typing
`make` the first target, `all` is run that runs the command listed to compile
the project. Cleanup is also defined and can be performed by running `make
clean`.

__sorted.cpp__: This file contains the code to handle the input and output for
the program. While not necessary for this project, you should be able to
understand all the code contained in this file. I strongly recommend that you
look over it and ask questions if you aren't sure what something is doing.

### Implementation

All the code you need to modify is contained in the file `helper.cpp` and
conveniently labled with `TODO` comments. For convenience, I will describe each
of the changes you need to make.

#### Comparison Functions

There are three string comparison functions that the `sorter` program
provides. A comparison function is a function that takes two arguments, I will
call them `lhs` and `rhs` for left-hand-side and right-hand-side
respectively. The comparison function compares the lhs to the rhs according to
some criteria and returns one of the following:

* a negative value, when the lhs is less than the rhs
* zero, when the lhs is neither less than, nor greater than the rhs
* a positive value, when the lhs is greater than the rhs

Note that it is up to the comparison function to define what is meant by `less
than` and `greater than`. Also, note that two items may compare similarly (a
return value of zero) but may in fact not be equivalent.

The first two comparison functions are already provided for you. The first is
the `default_comparison` function that sorts strings according to the ASCII
value of the first character in the string. If the first character matches
between the lhs and rhs, then subsequent characters are compared until an
ordering can be provided, or the strings are found to be similar. The second
comparision function is is `length_comparison`. This function simply compares
strings according to their length, with shorter strings being less than longer
strings. For strings of equal length, the `length_comparison` function will
perform a secondary comparison using the same logic as the `default_comparison`
function previously mentioned.

The third comparison function, `numerical_comparison`, is one you will have to
write. In the provided code, this function simply uses the same method as the
`default_compare` function. However, you need to implement this function such
that it attempts to compare the values as integer values with smaller numbers
being less than larger numbers. Strings that completely represent an integer
should compare less than strings that aren't completely integers. When neither
string is completely an integer, then the default comparison logic should be
used.

As an example, the following items (separated by whitespace) are in their
correct sort order as defined above:

    -1 0 1 02 10 * 1.1 1a apple zebra

Your `numerical_comparision` function should produce this exact sort order for
these items. I found [this stackoverflow
question](https://stackoverflow.com/questions/4917265/can-i-tell-if-a-stdstring-represents-a-number-using-stringstream)
useful in writing of the numerical comparison function.

#### Sorting Algorithms

There are four sorting algorithms that need to be implemented. Those are:

* bubble_sort
* insertion_sort
* selection_sort
* mergesort

The prototype for each of the sort functions is:

```c++
void sort_name(string *string_array, int n, int (*compare)(string, string));
```

The first argument, `string_array`, is a pointer to an array of strings. This
variable holds the data you will need to sort. The second argument, `n`, is the
number of elements contaned in `string_array`. This variable indicates how many
elements you will need to sort. Finally, you may be confused about the last
parameter. Many of you may never have seen a pointer to a function before. Let
me break it down for you:

```c++
int (*compare)(string, string)
```

As I just indicated, this parameter represents a pointer to a function. Since
we are in C++, we must describe exactly the prototype for the function
pointer. The initial `int` informs the compiler (and the developer) that the
function will return an integer. The `(*compare)` section informs the compiler
that we have a function pointer, the value of which will be assigned to the
variable compare. The `(string, string)` represents the parameters that the
passed in function must take. In this case, the passed in function must take
two strings as parameters.

When the sorter program is invoked, the user must select both a sorting
algorithm, and a comparison function. In order to support any one of the three
comparison functions in your sort algorithms you must only compare values by
using the function pointed to by the `compare` variable. You can use `compare`
just like any other declared function. Below is an example:

```c++
string a = "some string";
string b = "another string";
int retval = compare(a, b);
```

In the above, if `compare` is a pointer to either `default_comparison` or
`numerical_comparison`, then the return value will be positive as "another
string" is less than "some string" according to both those comparisons. If
`compare` is a pointer to `length_comparison`, then the return value will be
negative as "some string" is less (shorter) than "another string".

You __must__ manually write the sort algorithm for each of these. While you are
free to use external resources to assist you, you may not plagiarize, and you
will be expected explain any code in your submitted project. Finally, any
attempt to circumvent the feedback system (such as using the same sort code in
more than one of these functions) will result in a zero on the entire project 1
assignment.


### Testing your program

Now that you have a wonderful test_it.sh script, you are expected to use it to
test this project. I will describe setting up a simple test environment in a
manor that does not require you to modify your test_it.sh script.

First, copy test_it.sh into the same directory as the files you previously
copied. Assuming you are in the directory containing the files, run the
following:

```sh
mkdir -p tests/sorter
echo -e "0\n0\nc b a" > tests/sorter/input_bubble_default_01
```

The second line above will produce a file with the following contents:

    0
    0
    c b a

__Note__: To end the input stream you will need to press `<ctrl>+d`.

If you run this against sorter before making any changes, the following output
will be produced:

    Which sort algorithm would you like to use?
      0. bubble sort
      1. insertion sort
      2. selection sort
      3. mergesort
    bubble sort selected
    Which comparison function would you like to use?
      0. default
      1. string length
      2. numerical
    default selected
    c
    b
    a

You'll notice that the last three lines are not sorted (you haven't written the
sorts yet). Nevertheless, you know how `c b a` should be sorted, thus create a
file `tests/sorter/output_bubble_default_01` with the following contents:

    Which sort algorithm would you like to use?
      0. bubble sort
      1. insertion sort
      2. selection sort
      3. mergesort
    bubble sort selected
    Which comparison function would you like to use?
      0. default
      1. string length
      2. numerical
    default selected
    a
    b
    c

Now that you have one test case written, let's verify that it works as expected
with your `test_it.sh` script and the provided `sorter` program. First, if you
haven't already compiled the project, run `make`. Now you'll want to run
`test_it`. However, due to the fact that `test_it.sh` expects the programs to
be found in a directory pointed to by the `PATH` environment variable, we will
have to adjust the path as part of our command line. Assuming you've copied
your `test_it.sh` script into the same directory as your sorter program, run
the following:

```sh
PATH=$PATH:. test_it.sh tests/
```

The `PATH=$PATH:.` part before the command will temporarily update your path
for the remainder of the command line. In this case, we are appending `.`, the
current directory, to the end of the PATH variable. Recall that PATH components
are separated by `:`.

When you run the above you should get the following output:

    Testing sorter
    Failed: bubble_default_01

Great! That means it works, but it's not super useful as you cannot see what
the errors are. Recall that your test_it.sh script is sending the diff output
to `/dev/null`. If you remove the `> /dev/null` from the line containing diff,
then the output should print to the screen (as long as you aren't capturing the
output by running the command inside `$(...)`). You may also want to add the
`-u` option to your diff program invocation to get easier to read diff
output. Edit your `test_it.sh` script to allow diff to output to the screen and
add `-u` as an argument to diff. Re-run the tests. You should now see something
similar to:

    Testing sorter
    --- ../proj1_part2/tests//sorter/output_bubble_default_01       2012-08-18 16:19:27.000000000 -0700
    +++ -                                                           2012-08-18 16:23:37.800290894 -0700
    @@ -9,6 +9,6 @@
       1. string length
       2. numerical
     default selected
    -a
    -b
     c
    +b
    +a
    Failed: bubble_default_01

As you can see everything matches, except the order of the lines containing
`a`, `b`, and `c`.

That's the basic process for creating test cases to be used with your
`test_it.sh` script. You'll want to create a few test cases for each of the
combination of sorts and comparison functions. Given that there are a total of
twelve combinations, you'll probably want to write at least 36 test cases. Of
course, you can build the test cases incrementally as you implement more
functionality.

### Submission Instructions

For this project you will only be allowed 6 submissions, and you will receive
no `diff` output in the feedback. You are expected to extensively test your
project on your own before submitting.

Again, I want to mention that any attempt to circumvent the feedback system
(such as using the same sort code in more than one of the functions) will
result in a zero on the entire project 1 assignment (12% of the class grade).

Finally, you will only be submitting `helper.cpp`. Your code must __not__
depend on any changes you made outside `helper.cpp`. Additionally, all the
input and output is handled by the already provided code. Thus the code you
write should not produce any output when the `debug` variable is `false`.

To submit, run the following:

    ~cs32/submit pj1part2@cs32 helper.cpp

You may submit up to 6 times. Please check the feedback email to ensure you
submitted correctly, and are satisfied with your final score. If you are not,
feel free to revise and submit again. Please also review the
[automated feedback]({{ base }}/automated_feedback) instructions as needed.
