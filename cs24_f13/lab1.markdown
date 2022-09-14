---
title: Lab 1 &raquo; CS24 Fall 2013
---
{%- assign base = site.baseurl | append: "/cs24_f13" -%}
## Lab 1, FizzBuzz

### Motivation

The purpose of this assignment is to write a C program that demonstrates a
basic understanding of programming using C. The core concepts demonstrated by
this assignment are the handling of _command line arguments_, _looping_,
_conditionals_, and _output_. You are expected to have already learned, each of
these concepts save for command line arugments. I encourage you to attempt to
complete this assignment without consulting any outside resources. However,
should you need to look something up, please make a mental note of the topic in
order to track your progress toward mastery of the topic.


### Description

This assignment requires you to write a program, __fizzbuzz.c__, that
produces a single-line output for each number, _i_, from 1 up to and including
the given number _NUM_. Each line of output is one of the following:

* _i_ when _i_ is not divisible by 3 and not divisible by 5
* `fizz` when _i_ is divisible by 3
* `buzz` when _i_ is divisible by 5
* `fizzbuzz` when _i_ is divisible by both 3 and 5

The number, _NUM_, should be read in as the first command line argument. Your
program should check for the following error cases and produce the associated
error output message. Note that each error message should be followed by a
newline:

* The number of command line arguments is not 2: `Usage: fizzbuzz NUM`
* The number, _NUM_ is too small to produce any output: `NUM is too small`



### Compiling and running your program

In this class we will use the clang/clang++ compiler for all assignments. The
clang compiler has a number of benefits over the gcc/g++ compiler, most notably
with respect to the usefulness of its error and warning messages.

To compile the project:

    clang fizzbuzz.c

To run the project:

    ./a.out NUM


### Example input and corresponding output

No command line arguments:

    $ ./a.out
    Usage: fizzbuzz NUM

Negative value command line argument:

    $ ./a.out -1024
    NUM is too small


A valid input:

    $ ./a.out 15
    1
    2
    fizz
    4
    buzz
    fizz
    7
    8
    fizz
    buzz
    11
    fizz
    13
    14
    fizzbuzz


### Submitting the project

Note that you may resubmit this project as many times as necessary up until the
deadline. Please review the [submission instructions]({{ base }}/submission) as
needed.


### Appendix A: Reading command line arguments

Command line arguments can be read by declaring your `main()` function as
follows:

```c++
int main(int argc, char *argv[]) {
```

`argc` is the number of arguments that the program was run with, while `argv`
is an array with each of the command line arguments listed in order.
Therefore, `argc` will always tell you the number of elements in `argv`.

Keep in mind that the program name itself (`./a.out` in this lab) counts as one
argument, and will occupy `argv[0]`.  Any additional arguments can be found in
`argv[1]`, `argv[2]`, etc.

In the following example, our program prints out all of its command line
arguments in the order they were specified in:

```c++
#include<stdio.h>

int main(int argc, char *argv[]) {
    for(int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;
}
```

Compiling and running yields the following behavior:

One argument:

    $ ./a.out hello!
    hello!

Multiple arguments:

    $ ./a.out a b c d e
    a
    b
    c
    d
    e


### Appendix B: Converting char* to int

During the course of this lab, you may need to convert `char*` values to
`int`s.  This can be done using the `atoi` function, which is included in the
`stdlib.h` library.  `atoi` can be used as follows:

```c++
#include<stdio.h>
#include<stdlib.h>

int main() {
    char* aStr = "5";
    int b = atoi(aStr) + 1; //not possible without atoi
    printf("%d\n", b);
    return 0;
}
```

Compiling and running yields the following behavior:

    $ ./a.out
    6


### See also

* [CodingHorror: Why Can't Programmers Program?](https://blog.codinghorror.com/why-cant-programmers-program/)
