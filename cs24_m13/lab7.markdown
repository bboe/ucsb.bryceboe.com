---
title: Lab 7 &raquo; CS24 Summer 2013
---
{%- assign base = site.baseurl | append: "/cs24_m13" -%}
## Lab 7: Testing minimal heap

### Goals for this lab

By the time you have completed this lab, you should

* know what minimal heap is
* learn about minimal heap array form
* be able to decide if given array input is a minheap.

### Lab preparation

After logging in, create the directory for this lab:

```sh
mkdir -p cs24/lab7
```

Change into the lab2 directory and copy the files you will need for this lab:

```sh
cd cs24/lab7
cp ~bboe/public_html/cs24_m13/code/lab7/* .
```

Open up README.txt with your favorite text editor and be sure to add your and
your partner's name so that you both receive credit.

### Minimal Heap

#### Definition

Heap is a tree like data structure that satisfies the min-heap properties: it
is a complete binary tree : all levels of the tree (except for the last one)
are fully filled each node is smaler or equal to its children

This way the minimal element of the heap is its root element.

#### Array form

In the heap property it is said that all the levels of heap are completely
filled.  This means that we can use this information to store the heap
compactly in the array.  For example look at this heap:

         1
       /   \
      5     3
     /\    /
    7  9  8

We can store it an array like this: 1 5 3 7 9 8.

For example we are looking at element i in the array.

Where would its children be?

In the array with indexing starting from 0 the first child of element i would
be on `2i + 1` positsion and the second child would be on the `2i + 2`
position.

Where would its parent be? It parent would be on `floor((i - 1)/ 2)` position.

In our array:

    element   1 5 3 7 9 8
    position  0 1 2 3 4 5

Element 5, pos = 1 has its childre on 2*1 + 1 = 3, and 2*1 + 2 = 4 positions,
which correspond to 7 and 9.

### Implementing a program to test for the heap-property

In this lab you will have to implement a program (`test_heap.cpp`) that takes
command line arguments and checks if the arguments, as integers, satisfies the
heap property.

Your program should only produce one of two outputs, either `True\n` or
`False\n` which indicates whether or not the arguments when converted to
integers represents a minumim heap. Here are some examples:

    > ./a.out 1
    True
    > ./a.out 1 10 2
    True
    > ./a.out 2 1
    False
    > ./a.out 1 2 3 4 5 6 7 8 9 10
    True
    > ./a.out 1 2 3 4 5 6 7 8 9 1
    False


### Submitting the project

Only one person in a group need submit the project. If both members of a group
submit we will only score the last submission made between the two group
members. Please review the
[submission instructions]({{ base }}/submission) as needed. On the submission site
you will find the command you need to use to submit the project. Note that you
may resubmit this project as many times as necessary up until the deadline.
