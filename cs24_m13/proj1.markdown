---
title: Project 1 &raquo; CS24 Summer 2013
---
{%- assign base = site.baseurl | append: "/cs24_m13" -%}
## Project 1: List Abstract Data Type (ADT)

In this project, you will individually (no partners for non-lab assignments) be
required to implement a `List` ADT in two ways. You will implement the List ADT
using arrays, and using linked lists.


### Goals for this project

By the time you have completed this project, you should:

* understand what an abstract data type is
* understand how the concept of separate compilation works (`.h` and `.c`
  files) -- review the [separate compilation
  example](/~bboe/cs24_m13/code/week3/separate_compilation) if necessasry
* become familiar with working with linked structures (necessary for the
  remainder of this class)
* be able to discuss the trade-offs in performance between an array-based
  implementation and a linked-list implementation of the List ADT


### Project Preparation

Before you begin, let's prepare a cs24 directory in your home directory if you
don't already have one. In that directory we'll create a subdirectory for the
files for this project. Note that these instructions assume you are using
either a CSIL machine or one of the lab machines:

After logging in, create the directory (assuming you haven't already done so):

```sh
mkdir -p cs24/proj1
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

Change into the proj1 directory and copy the files you will need for this
project:

```sh
cd cs24/proj1
cp ~bboe/public_html/cs24_m13/code/proj1/* .
```


### The provided files

You are provided with the following files:

* __Makefile__: If you haven't seen a makefile before, this is a special file
  that contains the command-lines arugments required to build the project. By
  typing in `make` in the terminal both executables for this assignment will
  attempt to build. You can also run `make array` to just build the
  `array_list` binary, or `make linked` to just build the `linked_list` binary.

* __main.c__: This is a complete example program that can be used to test your
  implementations of the List ADT. While you do not need to modify this file,
  you are expected to understand __100%__ of the code in it. Pay particular
  attention to how we can easily switch between using the array-based
  implementation and the linked-implementation by using MACRO-conditionals
  around the `#include` for the `.h` file.

* __array_list.h__: This file provides the interface to the array-based
  implementation of the `List` ADT. You may _not_ modify this file, thus you
  must work with the `List` structure as provided.

* __linked_list.h__: This file provides the interface to the linked list-based
  implementation of the `List` ADT.  You may _not_ modify this file, thus you
  must work with the `List` structure as provided.


### Tips

#### Resizing the array When creating the array-based implementation it should
be apparent that you will need to start with some initial size array that will
need to be dynamically _expanded_ when the List needs to store more items than
available in the array. First, it's usually a good idea to work with initial
sizes that are a power of two, so 2, 4, 8, 16, 32 are all good starting
sizes. To dynamically resize the array you will want to look at the
[realloc](https://pubs.opengroup.org/onlinepubs/009696899/functions/realloc.html)
function that's part of the malloc family.

You can choose any scheme you want for how much to increase the size of the
array, but keep in mind a trade-off between time complexity (how much time it
takes to copy items), and space complexity (how much wasted space you have). In
general, the accepted approach is to double the size each time the limit is
reached. There's no need to reduce the size of the array as items are removed,
but you're free to do it if you want.

#### list_output format

The format string for the list_output function needs to be

    "%3d: %s\n"

Where the first parameter is the position of the item (0 through `size-1`), and
the second is the item itself.


### Completing the project

For this project you need to complete the two files: `array_list.c` and
`linked_list.c`. In both files you need to write the code for each of the
following functions (as declared in both the `.h` files):

* `char *list_at(struct List *list, int position)`
* `struct List *list_construct()`
* `void list_destruct(struct List *list)`
* `int list_get_size(struct List *list)`
* `int list_is_empty(struct List *list)`
* `void list_output(struct List *list)`
* `int list_push_back(struct List *list, char *item)`
* `char *list_remove_at(struct List *list, int position)`

To get started, you first need to define all the functions and provide minimal
functionality for each. For example, I suggest you start by creating
`array_list.c` first and define __all__ of the functions such that they
minimally return the error case. Once __all__ of the functions are defined for
`array_list.c` you should be able to compile the program via `make array`
without receiving any warnings.

When you can compile without errors and warnings, implement each function one
at a time and test each individually to convince yourself that the function
works as expected. You may want to write your own test program (or modify
main.c) to perform more testing than what is provided. You can implement the
functions in any order you wish. However, I strongly encourage you to think
about the dependencies between functions and implement the ones without
dependencies first.


### Deallocating Memory (8% of project grade)

None of the project tests verify that you properly deallocate memory. Thus we
will manually inspect both `array_list.c` and `linked_list.c` to verify that
you have properly implemented your `list_destruct` functions and any other
functions that require memory deallocation (hint: there is one other function
in one of the implementations).


### Submitting the project

Please review the [submission instructions]({{ base }}/submission) as
needed. On the submission site you will find the command you need to use to
submit the project. Note that you may resubmit this project as many times as
necessary up until the deadline.
