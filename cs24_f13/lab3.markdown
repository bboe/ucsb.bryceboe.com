---
title: Lab 3 &raquo; CS24 Fall 2013
---
{%- assign base = site.baseurl | append: "/cs24_f13" -%}
## Lab 3: Black-box testing

### Goals for this lab

By the time you have completed this lab, you should:

* have a better understanding of separate compilation
* understand at a high level the array list implementation
* be able to think a bit like a black-box attacker

The purpose of this lab is for you to discover bugs in my array-based
implementation of the list structure.


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
mkdir -p cs24/lab3
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

Change into the lab3 directory and copy the files you will need for this lab:

```sh
cd cs24/lab3
cp ~bboe/public_html/cs24_f13/code/lab3/* .
```


### The provided files

In your directory you will find the following files:

* array_list.o -- This is my implementation of the array-based version of the
  structure library which contains 4 _bugs_. The _separate compilation_ concept
  that clang supports is what allows me to provide you with this _object_ file
  and not the source code (you will not be able to find the source using gdb).

* lab3.c -- This is the file you will edit, and the only file you will submit.

* list.h -- This is the same list.h file provided with [project 1](proj1). In
  this file you will find the comments for all the `list_*` functions which you
  may find useful.

* Makefile - This file specifies how the `test_array` binary should be
  compiled. Notice that it utilizes `array_list.o` to build `test_array`.

* test_list.c - This is almost identical to the `test_list.c` provided with
  [project 1](proj1). However, it adds `#include "lab3.c"` so that the code you
  write in `lab3.c` is incorporated into the test set.

### Compiling and running the test suite

As given, you can compile the `test_array` executable by simply running:

    make

The, you can run all the tests in the test suite by running:

    ./test_array 0 20

which will initially provide the output:

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
    Test 17: find_list_at_bug               Failed
    Test 18: find_list_destruct_bug         Failed
    Test 19: find_list_push_back_bug        Failed
    Test 20: find_list_remove_at_bug        Failed

Your task is to update the four functions in `lab3.c` such that each of the
functions triggers the appropriate bug (and only the appropriate bug). When
completed the final should be:

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
    Test 17: find_list_at_bug               discovered list_at bug
    Failed
    Test 18: find_list_destruct_bug         discovered list_destruct bug
    Failed
    Test 19: find_list_push_back_bug        discovered list_push_back bug
    Failed
    Test 20: find_list_remove_at_bug        discovered list_remove_at bug
    Failed

Notice the addition of the messages `discovered list_??? bug` for the
appropriate function. These messages are output in certain cases the provided
array-based list structure implementation in `array_list.o`.

### Writing the test cases to find the bug

In each respective function in `lab3.c` you have to trigger the exact bug that
function is looking for. This will require some (maybe a lot) of
experimenting. Take the time to think about what has already been tested
(notice that all the existing tests already pass), and more importantly what
hasn't been tested. When you think you're on to something code it up, compile
it, and then test it locally (you don't need to submit to test).


### Hints

Note that each function may require more than one `list_*` function call, and
may require calls to `list_*` functions other than the one you're attempting to
find the bug for. Also, you should _not_ directly manipulate the list structure
as that will likely result in an unexpected bug which is not part of the
challenge. It is desirable for libraries to assume their structures are valid,
hence why it is not ideal to directly manipulate structure contents and why the
list structure attributes are all prefixed with `_`.

### Circumvention Warning

So that there is no confusion: if you make a submission that directly outputs
(or attempts to directly output) one of the expected messages you will receive
a 0 on this assignment. The __only__ acceptable way to pass the tests is
through the correct cominbation of calls to the `list_*` functions.

### Submitting the assignment

Only one person in a group need submit the assignment but make sure that both
you and your partner can view the submission on the submission site. If you
cannot, you need to complete the making a group process. Please review the
[submission instructions]({{ base }}/submission) as needed. Note that you may resubmit
this assignment as many times as necessary up until the deadline.
