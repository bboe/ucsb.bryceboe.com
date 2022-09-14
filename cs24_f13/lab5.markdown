---
title: Lab 5 &raquo; CS24 Fall 2013
---
## Lab 5: Intro to C++

### Updates

I've added the `-pedantic` flag to the compilation line. This will warn you if
you attempt to do something like the following:

```c++
int n;
cin >> n;
int numbers[n];
```

The following works using clang++ (and g++) because of a compiler extension
that allows dynamically-sized arrays on the stack. However, this extension is
_not_ part of the C++ standard and thus is not acceptable to use in this lab.

### Goals for this lab
After completing this lab you should be able to:

* Use C++'s `std::cin` and `std::cout`
* Allocate and deallocate memory using `new[]` and `delete[]`
* Define C++ classes

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
mkdir -p cs24/lab5
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

Change into the lab5 directory and copy the files you will need for this lab:

```sh
cd cs24/lab5
cp -r ~bboe/public_html/cs24_f13/code/lab5/* .
```

### Provided files
You will find the following files in your directory:

* _numbers.cpp_ -- This file contains the skeleton code for Part 1. It has the
  `#include`s that you will need and reads the first number in for you.

* _myclass.h_ -- This file contains the skeleton code for Part 2. It defines
  the C++ class MyClass for which you will have to implement the member
  functions.

### Part 1: C++ I/O
In this lab we are going to work with a few features of C++ that diverge from
their C counterparts. Your task in the fist part of the lab is to write a
simple program which does the following:

1. Read a integer from standard input (well call this number _n_ and it will
   always be greater than 0)
2. Read in _n_ more integers from standard input
3. Print these integers (not including _n_) in reverse order to standard output
4. Print the sum of these integers (not including _n_) to standard output
5. Print the average value of these integers (not including _n_) to standard
   output with the correct precision

Here is an sample execution of the program:

    $ ./numbers
    How many numbers will you input? 3
    #1: 1
    #2: 2
    #3: 3
    In reverse: 3 2 1
    Sum: 6
    Average: 2.00
    $

You are to use the C++ I/O library and memory allocation/deallocation operators
that are described below. __Submissions using scanf/printf and malloc/free will
not be accepted!__

### Part 2: C++ classes
For the second part of the lab, you will be writing a simple C++ class. The
class definition is provided for you in _myclass.h_ and it is up to you to
implement the member functions declared in the class. The details and expected
output are described in the comments of _myclass.h_.

### The iostream library

Like C, C++ uses the _stream_ as its primary method of input and output,
however the syntax in C++ is mercifully simpler. The C++ standard I/O
procedures can be found in the `<iostream>` library. The stream for standard
input is named `std::cin` and the stream for standard output is named
`std::cout`. Recall that `::` is the scope resolution operator. All of the
standard library functions and variables are in the `std` namespace so you must
prefix them with `std::` to use them. To write to and read from streams C++
provides the _insertion_ and _extraction_ operators, `<<` and `>>`, which
handle print formatting for you:

```c++
#include <iostream>

int main ()
{
  int i;
  std::cout << "Enter a number: "; // print to standard output
  std::cin >> i;                   // read from standard output
  std::cout << i << " squared is " << i*i << "\n";
  return 0;
}
```

For tighter control of output formatting, C++ provides the `<iomanip>`
libray. In this lab we want to set the precision with which we print floating
point variables. This can be done using the `std::fixed` and
`std::setprecision` stream manipulators:

```c++
#include <iostream>
#include <iomanip>

int main ()
{
  double pi = 3.1415927;
  std::cout << pi << "\n"; // print with default formatting

  std::cout << std::setprecision(2);
  std::cout << pi << "\n"; // print with UP TO 2 digits of precision

  std::cout << std::setprecision(9);
  std::cout << pi << "\n"; // print with UP TO 9 digits of precision

  std::cout << std::fixed;
  std::cout << pi << "\n"; // print with EXACTLY 9 digits of precision
  return 0;
}
```

Output:

    $ ./a.out
    3.14159
    3.14
    3.1415927
    3.141592700

### Memory management
C++ has built-in operators to handle dynamic allocation and deallocation of
memory. Use the `new[]` operator to allocate memory and `delete` to
deallocate. While the syntax is new to you, their functionality should be
familiar:

```c++
int *p1;
int *p2;
p1 = new int;    // allocate memory for 1 int
p2 = new int[5]; // allocate memory for 5 ints
delete p1;       // deallocate memory for 1 int
delete[] p2;     // deallocate memory for 5 ints
```
