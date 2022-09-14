---
title: Lab 1 &raquo; CS24 Summer 2013
---
{%- assign base = site.baseurl | append: "/cs24_m13" -%}
## Lab 1: C Review

### Goals for this lab

By the time you have completed this lab, you should be able to

* remember memory allocation and string functions.
* know how to submit assignments in this class with the new submit program.

The purpose of this lab is to get you back in the swing of things by completing
small coding exercises in C involving strings and malloc.

To get full credit for this lab, you need to complete all of the functions
specified.


### Lab Pairing

For this lab (and all following labs), you may work with a partner. If you do
work with a partner (please do), you will need to use the same partner
throughout the quarter. When working with a partner, I strongly encourage you
follow the pair programming method of working together. If you are not familiar
with pair programming please
[watch this video](https://www.youtube.com/watch?v=rG_U12uqRhE).


### Lab Preparation

Before you begin, let's prepare a cs24 directory in your home directory if you
don't already have one. In that directory we'll create a subdirectory for the
files for this lab. Note that these instructions assume you are using either a
CSIL machine or one of the lab machines:

After logging in, create the directory (assuming you haven't already done so):

```sh
mkdir -p cs24/lab1
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

Change into the lab2 directory and copy the files you will need for this lab:

```sh
cd cs24/lab1
cp ~bboe/public_html/cs24_m13/code/lab1/* .
```

Open up README.txt with your favorite text editor and be sure to add your and
your partner's name so that you both receive credit.


### Building string functions

The task for this lab is to complete three string functions. The purpose is to
practice two things: the first is to treat strings as nothing more complex than
an array of characters ending with the `\0` character; we never know how long a
string is except by detecting that end of string character. The second purpose
is to reinforce how to use pointers vs arrays.
In lab1.c, the skeletons are already provided. Make sure you do not
call any string functions - you must implement these yourself.

You are to complete three functions:

* __stringlength__ - counts the number of characters in a string, not counting
  the terminating character

* __countchars__ - counts the number of occurrences of a character in the
  string

* __safestringconcat__ - creates new memory, copies in two strings
  concatenated, and returns the resulting pointer

The reason you are writing `safestringconcat` is a) to practice allocating
memory and b) to emphasize that `strcat` in the strings library does NOT do
this - instead, it adds the second string to the first one WITHOUT allocating
more memory. That is dangerous if you are not aware of it.


### Compile and test your implementation

I suggest you complete and test each function individually. That is, start with
code that compiles (the template) and slowly add functionality and verify that
the code continues to compile as you make changes. When you've completed a unit
of work (i.e., one of the three functions) test your program to verify that
function works correctly before moving on. You will not receive partial credit
for `units` that don't work.

To compile `lab1.c` execute:

    clang -g lab1.c

Note that the `-g` argument to the clang compiler (this is consistent with gcc
as well) means to build the executable (`a.out` in this case) with debugging
information.

If the compilation fails make the necessary changes (clang should be more
useful than gcc at reporting potential problems -- that's why we are using
clang rather than gcc) and then repeat until your code compiles successfully.

To run the executable, execute:

    ./a.out

Verify that your code produces the expected results. If not repeat this process
until it does.

If you code crashes, I strongly encourage you to load it in gdb to easily
detect which line resulted in the failure. To do that, you first want to load
the executable in gdb:

    gdb a.out

In the gdb shell, you want to begin the execution of the program. Do that by
typing `run`, or just `r`.

The location the program crashed at should be reported by gdb. However, to see
the source code around the crash location you can type `list`. If the crash
location is in code you didn't write, then you'll want to type `up` to move up
the function-call stack until you reach your own program's code.


### Gotchas

* Remember that fgets retains the `\n`, so your stringlength will be one more
  than what you think.



### Submitting the project

Only one person in a group need submit the project. If both members of a group
submit we will only score the last submission made between the two group
members. Please review the
[submission instructions]({{ base }}/submission) as needed. On the submission site
you will find the command you need to use to submit the project. Note that you
may resubmit this project as many times as necessary up until the deadline.



### Special Thanks

Special thanks to Diana Franklin for allowing
me use of her CS24 material. This lab was adapted from one of her Spring 2013
CS24 labs.
