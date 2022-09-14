---
title: Lab 2 &raquo; CS24 Fall 2013
---
{%- assign base = site.baseurl | append: "/cs24_f13" -%}
## Lab 2: GDB Introduction and C Review

__Note__: You have an additional day for this lab as it requires a bit more
work than we initially hoped for.

### Goals for this lab

By the time you have completed this lab, you should:

* completely understand how char arrays are used to represent c-strings
* be comfortable writing your own c-string manipulation functions
* be able to use gdb to discover where and why your program is crashing

The purpose of this lab is to get you back in the swing of things by completing
small coding exercises in C involving c-strings and malloc.

To get full credit for this lab, you need to complete all of the functions
specified.


### Lab Pairing

For this lab you may work with a partner. If you do work with a partner (please
do), you will need to use the same partner throughout the quarter. When working
with a partner, I strongly encourage you follow the pair programming method of
working together. If you are not familiar with pair programming please [watch
this video](https://www.youtube.com/watch?v=rG_U12uqRhE).

To facilitate your submissions as a pair you __MUST__ pair up using the
submission system. When you visit the project page from where you can view all
your submission you should see a link to a page where you can join a group. Of
the two people in the group, one of you must invite the other, and the other
must confirm the invitation. Once you group up, any submissions that either
you, or your partner have already made will be visible to each other in
addition to all future submissions.


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
mkdir -p cs24/lab2
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
cd cs24/lab2
cp ~bboe/public_html/cs24_f13/code/lab2/* .
```


### Getting your feet wet with gdb

For the first part of the lab you will use gdb to figure out how to execute
`gdb_puzzle`. The first thing you will want to do is try to execute
`gdb_puzzle` by running:

    ./gdb_puzzle

You should notice that the program segfaults. That's because the program
expects to be executed with a specific command line argument to run
successfully.

The first thing you will want to do is to read the awesome [gdb tutorial](gdb)
that Dani has written. That should walk you through the gdb commands you will
need to use to figure out the proper command line argument to use to execute
`gdb_puzzle`.

Once you have discovered the command line arguments that should follow
`./gdb_puzzle` create a text file called `part1.txt` and place the extra
arguments on a single-line in that file.

For instance if you discover that running `./gdb_puzzle hello world` is the
correct command to solve the challenge (it is not) then the contents of
`part1.txt` should be `hello world`. You can verify that you have created this
file correctly by running:

    xargs ./gdb_puzzle < part1.txt

If you see the same _correct_ output, then you have a valid `part1.txt`
suitable for submission on the submission site.

It is important that you go through the process of using gdb, as anytime you
have a segfault in your code this quarter, the first thing either myself, or
the TAs will ask you is where in your code did the execution segfault, and how
did it get there.


### Building string functions

The second task for this lab is to complete three functions that operate on
c-strings. The purpose is to practice two things: the first is to treat
c-strings as nothing more than an array of characters ending with the
null-terminating character, or `'\0'` (also 0 as a 1-byte number). That means
c-strings are arbitrarily long and functions that operate on c-strings continue
processing bytes (characters) until a `'\0'` is found. The second purpose is to
reinforce the difference between pointers and arrays.

### cstring_fun

Take a look at `cstring_fun.c`. In this file, you must fill in the missing code
in the following three functions. __NOTE__ that you may not make use of any of
the functions in string.h.

You are to complete three functions:

* __stringlength__ - counts the number of characters in a string, not counting
  the terminating character

* __countchars__ - counts the number of occurrences of a character in the
  string

* __safestringconcat__ - allocates new memory, copies in two strings
  concatenated, and returns the resulting pointer

The reason you are writing `safestringconcat` is a) to practice allocating
memory and b) to emphasize that `strcat` in the strings library does NOT do
this - instead, it adds the second string to the first one WITHOUT allocating
more memory. That is dangerous if you are not aware of it.


#### Compile and test your implementation

I suggest you complete and test each function individually. That is, start with
code that compiles (the template) and slowly add functionality and verify that
the code continues to compile as you make changes. When you've completed a unit
of work (i.e., one of the three functions) test your program to verify that
function works correctly before moving on (this is also a good point to make a
submission). You will not receive partial credit for `units` that don't work.

To compile `cstring_fun` execute:

    clang -g cstring_fun.c

Note that the `-g` argument to the clang compiler (this is consistent with gcc
as well) means to build the executable (`a.out` in this case) with debugging
information which allows you to more easily use gdb to discover what line any
segfaults occur on.

If the compilation fails make the necessary changes and then repeat until your
code compiles successfully.

To run the executable, execute:

    ./a.out

Verify that your code produces the expected results. If not repeat this process
until it does. If you code crashes, you should now know how to use gdb to
locate the line it crashes on.

#### Gotchas

* Remember that fgets retains the `\n`, so your stringlength will be one more
  than what you think.


### Submitting the assignment

Only one person in a group need submit the assignment but make sure that both
you and your partner can view the submission on the submission site. If you
cannot, you need to complete the making a group process. Please review the
[submission instructions]({{ base }}/submission) as needed. Note that you may resubmit
this assignment as many times as necessary up until the deadline.


### Special Thanks

Special thanks to Diana Franklin for allowing
me use of her CS24 material. Portions of this lab were adapted from one of her
Spring 2013 CS24 labs.
