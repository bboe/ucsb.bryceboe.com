---
title: Lab 3 &raquo; CS24 Summer 2013
---
{%- assign base = site.baseurl | append: "/cs24_m13" -%}
## Lab 3: Starting Project 1


### Goals for this lab

By the time you have completed this lab, you should

* Have an initial version of the array-based implementation of the List
  completed.

### No Lab Pairing

This is not really a lab, but rather an opportunity to require you to start
working on project 1. As such, you may not work with a partner on this
assignment.

### Lab Preparation

Follow the [instructions]({{ base }}/proj1) to obtain the project 1
files if you have not done so already. If you started early, you may want to
update your [test_list.c]({{ base }}/code/proj1/test_list.c) file.

### Implementing `array_list.c`

0. Create the file `array_list.c` if you have not done so already.

0. Add `#include "array_list.h"` at the top of `array_list.c` so that the
implementation is aware of the attributes available in `struct List`.

0. Define all of the functions that are declared in `array_list.h`. Your
initial definition might simply want to return the "error" value (`NULL` for
pointers, `0` for boolean integers).

0. Once all the functions have been sufficiently defined, attempt to compile
`test_array` by running `make test_array`. Fix any issues and repeat until
`test_array` builds.

0. Run `test_array 0 -1` and observe any tests that fail. Make the necessary
additions/corrections and repeat steps 4 and 5 until all the tests are passed.

### Submitting the project

Even though you're working on project 1, your lab 3 grade will depend on
passing all the tests for the array-based implementation of the List that are
included in `test_list.c`.
