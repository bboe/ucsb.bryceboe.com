---
title: Lab 4 &raquo; CS24 Summer 2013
---
{%- assign base = site.baseurl | append: "/cs24_m13" -%}
## Lab 4: Introduction to C++

### Goals for this lab

By the time you have completed this lab, you should be able to

 * create your own class with custom constructors and destructor
 * create and use methods for your class

The purpose of this lab is to get you familiar with C++ basics.

### Lab pairing

For this lab you may work with a partner. Please, team up with the same person
you were working on the previous labs. When working with a partner, I strongly
encourage you follow the pair programming method of working together.

### Lab preparation

After logging in, create the directory for this lab:

```sh
mkdir -p cs24/lab4
```

Change into the lab2 directory and copy the files you will need for this lab:

```sh
cd cs24/lab4
cp ~bboe/public_html/cs24_m13/code/lab4/* .
```

Open up README.txt with your favorite text editor and be sure to add your and
your partner's name so that you both receive credit.

### Building MyVec class

You are provided with the files Makefile, main.cpp, and vec.h. In this lab, you
will need to add all the functionality that main.cpp expects from the MyVec
class. Given all methods declarations in vec.h, you will have to write the
corresponding implementations in vec.cpp.

#### Step 1: Add the constructors

Completing this step will allow you to build the program main by running make.
You will need to declare and define the two constructors and a destructor. The
first one should only take array size, the second one should also take a
pointer to some int array. Both of the constructors should allocate memory for
integer array (do *not* use `vector` template). The destructor should delete
allocated memory.  Here is an example of allocating and releasing memory in
C++:

```c++
int *tmp = new int[2048];
delete []tmp;
```

Note: starting from this lab you are not allowed to use `malloc` (or associated
functions), `realloc` or `free`. Please, use appropriate C++ syntax.

#### Step 2: Add the getters and setters

Next you will need to define the getters and setters for your class.  Once you
have done that, comment out the appropriate lines in main.cpp to verify you
have correctly done the implementation.

#### Step 3: Add instance method add_immediate

Next, you will need to implement this method in order to be able to add two
vectors.  This method takes a constant reference to another vector as an input
and stores result in the initial object. When you use the method, you will be
making a call

```c++
vec_0.add_immediate(vec_1);
```

The result should be stored in `vec_0`.

Here are few examples of how vector addition works.  For two vectors of the
same size let:

    vec_0 = (1, 2, 3), vec_1 = (4, 5, 6)

After calling `vec_0.add_immediate(vec_1)`:

    vec_0 = (5, 7, 9)

For two vectors of two different sizes let:

    vec_0 = (1, 2), vec_1 = (4, 5, 6)

After calling `vec_0.add_immediate(vec_1)`:

    vec_0 = (5, 7)

Another example of two different sized vectors:

    vec_0 = (1, 2, 3), vec_1 = (4, 5)

After calling `vec_0.add_immediate(vec_1)`:

    vec_0 = (5, 7, 3)

_Hint_: You might want to use the `std::min` function to help you in this
step. Here's an example usage:

```c++
int min_size = std::min(4, 27);  // returns 4 as it is the smaller value
```

Once you have implemented this method, comment out the appropriate lines in
`main.cpp` to verify you have correctly done the implementation.


### Submitting the project

Only one person in a group need submit the project. If both members of a group
submit we will only score the last submission made between the two group
members. Please review the
[submission instructions]({{ base }}/submission) as needed. On the submission site
you will find the command you need to use to submit the project. Note that you
may resubmit this project as many times as necessary up until the deadline.
