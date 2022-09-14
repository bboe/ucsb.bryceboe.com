---
title: Project 2 &raquo; CS24 Fall 2013
---
{%- assign base = site.baseurl | append: "/cs24_f13" -%}
## Project 2: Virtual Directory Trees

In this project, you and your partner will complete the binary search tree
(BST) implementation you started in [lab 7]({{ base }}/lab7). You will also implement a
few functions for a shell that supports the creation of a virtual directory
hierarchy where there is a root directory, `/`, that can contain zero or more
subdirectories each of which can contain zero or more subdirectories and so on.

### Goals for this project

By the time you have completed this project, you should:

* fully understand the use and implementation of a binary search tree
* understand how to use recursion to traverse a binary tree
* be comfortable working with a general tree (a directory can have any number
  of subdirectories)


### Project Preparation

To begin create a proj2 directory (assuming you haven't already done so):

```sh
mkdir -p cs24/proj2
```

Change into the proj2 directory and copy the files you will need for this
project:

```sh
cd cs24/proj2
cp ~bboe/public_html/cs24_f13/code/proj2/* .
```

The first thing you will want to do is copy the appropriate functions from your
lab 7 `bst.cpp` to the `bst.cpp` for this project.

### Building and testing the project

To build the project run:

    make

If successful that will produce `virtual_directory` which you can run via:

    ./virtual_directory

This program has its own set of commands which you can list via the command
`help`. You will need to implement each of those additional commands (by
default they do nothing).


### Understanding the assignment

The first thing you will want to do is understand what it is your are
attempting to build. The files you copied contains a reference implementation
that will run on the CSIL machines. Below is a complete sample execution of the
reference implementation:

    $ ./reference
    > ls
    > mkdir foo
    > ls
    foo 
    > pwd
    /
    > mkdir blah
    > mkdir zebra
    > ls
    blah foo zebra 
    > cd foo
    foo> mkdir bar
    foo> cd bar
    bar> pwd
    /foo/bar
    bar> cd ..
    foo> cd ..
    > rmdir foo
    > ls
    blah zebra 

### Understanding the code

There are two core pieces of code you need to understand. The first is
`virtual_directory.cpp`. This file contains the code that converts the user
input into the commands to work with the virtual directory tree. All the code
to handle the user input has already been written, however, you need to take
note of how the input is converted into functions that you are to write. Also
pay particular attention to the fact that the root directory is created on
start-up and that the variable `cwd` points to the current (or sometimes called
present) working directory.

That brings us to the second important part of the code, `directory.h`. In this
file you will see the interface for the Directory class. The three attributes
of a Directory are its `name`, its `parent` and its `subdirs` or
subdirectories. Note is that we are using our __BST__ class to store pointers,
well wrapped pointers (for comparison and output purposes), to other Directory
instances. Recall that a __BST__ as well as a __List__ is an implementation of
a generic container ADT. We are using the __BST__ because we want (1) ordered
listings and (2) better than __O__(n) insertion, look-ups and removals. Avoid
confusing the general tree of directories, and the BST that is used to merely
hold a set of subdirectories.

The functions you must write in `virtual_directory.cpp` should directly
interact with functions that are part of the `Directory` class. You must write
some of those functions (in `directory.cpp`) many of which will interact with
the `BST` class.

### Suggested Approach

Before beginning make sure you received 100% on lab 7 as this assignment
depends on your `BST::insert` and `BST::~BST` working properly. The following
is the approach I suggest you take in completing this assignment as there are a
lot of dependencies between parts (e.g., `rmdir` cannot be tested until both
`mkdir` and `ls` work 100%).

#### Part 1 (Goal: complete by Friday, November 15)

__1: ls and mkdir__

The first thing to do is to get the commands `ls` and `mkdir` to work
properly. This will allow you add to root's (`/`) subdirectories and produce
the correct output. You should be able to pass all the `root_mkdir` tests
in addition to a few others (\~12/55) on the submission system at this point.

__Note__: You will need to use recursion over the BST of subdirectories in
order to output the items in the sorted order. You can skip the sorting until
later if you wish. In such a case you will want to use either a stack or queue
to output all the nodes. This will allow you to verify that your other
operations work. However, you won't be able to pass many tests on the
submission system.

__2: cd__

Once you can list directories you need to implement the `cd` command to change
directories. After completing this function you should additionally pass all
the `mkdir_chrdir` tests (\~22/55).


__3: pwd__

Finally write the functionality for the `pwd` command. At this point you should
pass just under half of the tests (\~26/55) and have a pretty good feel for how
all the pieces interact.


#### Part 2: Start after part 1 is complete

The second part of the assignment is technically much more difficult than the
first, despite only having one more command, `rmdir`, to implement.

__1: rmdir__

Implement everything necessary to remove a subdirectory. You will need to
complete the `BST::remove` function for this to work properly. You __must__ use
recursion (you will need a helper function) to complete this process. (You can
also implement it iteratively if you so desire but you must demonstrate that
you can do it recursively).

When rmdir is completed you should pass 52/55 of the tests (assuming everything
works up to this point).

__2: Directory::\~Directory__

The last thing to do is to make sure that when a Directory is deallocated it
does not leak any memory. Completing this part will reward you with those last
three points.


#### Extra Credit

Once you receive 100% you can implement additional commands for up to 15% extra
credit (2.1% of the overall grade). The amount of extra credit will depend on
the quantity and relative difficulty of the extra commands. Please message
"instructors" on Piazza to discuss any extra credit ideas you may have.


### Submitting the project

Please review the [submission instructions]({{ base }}/submission) as needed. On the
submission site you will find the command you need to use to submit the
project. Note that you may resubmit this project as many times as necessary up
until the deadline. If you are working with a partner, make sure to group up
using the submission system.
