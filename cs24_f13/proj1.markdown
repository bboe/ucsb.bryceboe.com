---
title: Project 1 &raquo; CS24 Fall 2013
---
{%- assign base = site.baseurl | append: "/cs24_f13" -%}
## Project 1: List Abstract Data Type (ADT)

In this project, you (and at most one partner) will be required to implement a
`List` ADT in two ways. You will implement the List ADT using arrays, and using
linked lists.

### Important Updates

* Your initial array size may not exceed 32 entries (realloc must be called at
  least once to store 33 items).
* You may not use __static__ or __global__ variables. Any state that you need
  to maintain persistance for is available through the proper `struct List`.
* Even though there isn't a test for it, you must check to ensure all memory
  allocations succeed. If a memory allocation fails you must handle it
  gracefully as indicated by the function.


### Goals for this project

By the time you have completed this project, you should:

* understand what an abstract data type is
* understand how the concept of separate compilation works (`.h` and `.c`
  files) -- review the [separate compilation
  example](/~bboe/cs24_f13/examples/week2/separate_compilation) if necessary
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
cp ~bboe/public_html/cs24_f13/code/proj1/* .
```


### The provided files

You are provided with the following files:

* __list.h__: This file provides the interface to the `List` ADT. You may _not_
  modify this file, thus you must work with the `List` structure as
  provided. This file provides the declarations for all the functions you must
  implement. The comments in this file indicate exactly how each function
  should perform. Read this entire file and understand it. Pay particular
  attention to how we can easily switch between using the array-based
  implementation and the linked-implementation by using MACRO-conditionals
  around the structure declaration(s).

* __main.c__: This is a complete example program that can be used to test your
  implementations of the List ADT. While you do not need to modify this file,
  you are expected to understand __100%__ of the code in it.

* __Makefile__: If you haven't seen a makefile before, this is a special file
  that contains the command-line arguments required to build the project. By
  executing `make` in the terminal you will see the list of available make
  options. When working on the array-based implementation you will likely want
  to run `make array` and `make test_array`. For the link-based implementation
  `make linked` and `make test_linked`.

* __test_list.c__: This program provides unit-like testing of individual
  functions and has been provided to you as a convenience. You are not expected
  to know exactly how the code in this program works (it makes use of passing
  function pointers around). The submission system uses a version of this file
  that defines many more tests (__NOTE__: the test numbers do not correspond
  between the submission system and the numbers in this file). You are
  encouraged to add your own tests to this file to help you test your program
  without the help of the submission system. To add a test you need to (1)
  define a function that takes a `struct List *` as its only argument, and
  returns an integer, 0 for failure and non-zero for success. You then (2) need
  to add the name of the function, and an _output name_ to the `TESTS` array.


### Completing the project

For this project you need to create and complete the two files: `array_list.c`
and `linked_list.c`. In both files you need to write the code for each of the
following functions (as declared in both the `.h` files):

* `char *list_at(struct List *list, int position)`
* `struct List *list_construct()`
* `void list_destruct(struct List *list)`
* `int list_get_size(struct List *list)`
* `int list_is_empty(struct List *list)`
* `void list_output(struct List *list)`
* `int list_push_back(struct List *list, char *item)`
* `char *list_remove_at(struct List *list, int position)`

#### Getting Started

The very first thing you should do is finish reading this document. There is
useful information that you'll want to be aware of so you can refer back to it
when you reach the appropriate point.

The second thing you should do is read all the comments in `list.h` so it is
clear what each function should do. Always make sure you understand what it is
that you are being asked to do before attempting to do it.

Once you understand what you are being asked to do, literally draw out some of
the operations. What should the structure look like after it's allocated? What
does the structure look like after a number of insert operations? What about
after a number of remove operations? What are the error cases that you need to
handle in each function?

Only after you've got an idea in your head about how the functions should
create/manipulate/destroy the structure(s) should you start coding.

To start coding, you first need to define all the functions that are declared
in `list.h` in their respective `.c` files: `array_list.c` for the array-based
implementation, and `linked_list.c` for the link-based implementation. A proper
definition requires a minimal implementation, so functions that have a non-void
return type must return something of that type, and functions that are void
must at least have an empty body, `{}`. In general when defining a minimal
version of a function that returns a value, you should return a value that
indicates failure.

Once __all__ of the functions are defined for `array_list.c` you should be able
to compile the program via `make array` without receiving any errors and
warnings.

When you can compile without errors and warnings, implement each function one
at a time and test each individually to convince yourself that the function
works as expected. Use the provided `test_list.c` and `main.c` programs to help
you test your functions. You can implement the functions in any order you
wish. However, I strongly encourage you to think about the dependencies between
functions and implement the ones without dependencies first.


### Sample Execution

You are provided with two programs to help you test your code. Here we'll give
a sample of how to compile and run both.

#### test_list.c

If you want to test your array list implementation using the `test_list.c`
program, you will want to compile via:

    $ make test_array

Assuming there are no errors (can't proceed) and warnings (you should always
fix your warnings) then you can run the test program a few ways:

    ./test_array 0 -1

The above will attempt to run all tests available, starting at test 0, and
running through the remainder (a negative second argument means run the
remainder). Assuming your program works correctly you should see output like:

    Test 00: construct_destruct             Passed
    Test 01: at_0_after_push_back_one       Passed
    Test 02: at_minus1_after_construct      Passed
    Test 03: at_minus1_after_push_back_one  Passed
    Test 04: at_neg1_after_push_back_one    Passed
    Test 05: at_plus1_after_construct       Passed
    Test 06: at_plus1_after_push_back_one   Passed
    Test 07: get_size_after_construct       Passed
    Test 08: get_size_after_push_back_one   Passed
    Test 09: is_empty_after_construct       Passed
    Test 10: is_empty_after_push_back_one   Passed
    Test 11: output_after_construct         Passed
    Test 12: output_after_push_back_one     Passed
    Test 13: push_back_remove_at_0          Passed
    Test 14: push_back_remove_at_neg1       Passed
    Test 15: remove_at_0_after_construct    Passed
    Test 16: remove_at_neg1_after_construct Passed

It's possible that your program segfaults (or results in some other crash) on
one of the tests. In such a case the output might look like:

    Test 00: construct_destruct             Passed
    Test 01: at_0_after_push_back_one       Segmentation fault (core dumped)

First, this is a hint that something broken in your code as a result of the
`at_0_after_push_back_one` test. You should look at what that test does in
`test_list.c` and fix it. However, should you want to see the result of the
other tests, you can run the test program like so:

    $ ./test_array 2 -1
    Test 02: at_minus1_after_construct      Passed
    Test 03: at_minus1_after_push_back_one  Passed
    Test 04: at_neg1_after_push_back_one    Segmentation fault (core dumped)

Note that we changed the `0` to a `2` to begin testing at test 2. In the output
that follows you see that we result in another segfault on test 4,
`at_neg1_after_push_back_one`. We can then start at test 5 if we so desired,
and continue this process to see all the tests that result in segfaults.

The testing process is the same for the link-based implementation. However,
rather than running `make test_array` in combination with `./test_array` you
will want to use `make test_linked` in combination with `./test_linked`.

#### main.c

`main.c` defines a program that allows you to enter in strings from standard
input (or a given file) and add them to the list. It then outputs the contents
of various items in the list, and attempts to remove each. If you want to test
your array-based implementation compile via `make array` (`make linked` for the
link-based implementation). Execute via:

    ./array_list

(replace `./array_list` with `./linked_list` if you compiled via `make linked`)
You will be prompted to enter strings via standard input. Assuming you insert
the same strings as I have entered (shown along with the output) a sample run
might look like:

    Enter a string to add to the list (or empty to stop): one apple
    Enter a string to add to the list (or empty to stop): two bananas
    Enter a string to add to the list (or empty to stop): three something elses
    Enter a string to add to the list (or empty to stop): 
      0: one apple
      1: two bananas
      2: three something elses
     First+: one apple
     First-: one apple
    Middle+: two bananas
    Middle-: three something elses
      Last+: three something elses
      Last-: three something elses
         -1: (null)
         +1: (null)
    remove -1: (null)
    remove +1: (null)
    Removed: two bananas
      0: one apple
      1: three something elses
    Removed: one apple
      0: three something elses
    Removed: three something elses

You can also give a file as the input to the program. Execute like so:

    ./array_list Makefile


### Tips and recommendations

#### Negative position values

Both `list_at` and `list_remove_at` require you to handle negative position
values. While you can attempt to add additional conditionals to handle the
positional value as both negative in positive in both of these functions, it's
much simpler (trust me) to simply convert negative values into a positive
value. Because this conversion code should be identical in both `list_at` and
`list_remove_at`, it makes sense to move that functionality into its own
function. You'll have to duplicate that function in both of your `*.c` files,
but you should only have to write it once.

#### Resizing the array

When creating the array-based implementation it should be apparent that you
will need to start with some initial size array that will need to be
dynamically _expanded_ when the List needs to store more items than available
in the array. First, it's usually a good idea to work with initial sizes that
are a power of two, so 2, 4, 8, 16, 32 are all good starting sizes. To
dynamically resize the array you will want to look at the
[realloc](https://pubs.opengroup.org/onlinepubs/009696899/functions/realloc.html)
function that's part of the malloc family as it'll save you from having to (1)
call `malloc` and (2) copy all the existing elements.

You can choose any scheme you want for how much to increase the size of the
array, but keep in mind a trade-off between time complexity (how much time it
takes to copy items), and space complexity (how much wasted space you have). In
general, the accepted approach is to double the size each time the limit is
reached. There's no need to reduce the size of the array as items are removed,
but you're free to do it if you want.


### Submitting the project

Please review the [submission instructions]({{ base }}/submission) as needed. On the
submission site you will find the command you need to use to submit the
project. Note that you may resubmit this project as many times as necessary up
until the deadline. If you are working with a partner, make sure to group up
using the submission system.
