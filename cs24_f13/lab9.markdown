---
title: Lab 9 &raquo; CS24 Fall 2013
---
{%- assign base = site.baseurl | append: "/cs24_f13" -%}
## Lab 9: Validating a min heap

### Goals for this lab

By the time you have completed this lab, you should:

* understand the internal structure of a min heap
* understand how an array can be used to represent a tree
* determine whether or not items in an array are in a valid min heap order


### Lab pairing

For this lab you may work with a partner. To facilitate your submissions as a
pair you __MUST__ pair up using the submission system. When you visit the
project page from where you can view all your submission you should see a link
to a page where you can join a group. Of the two people in the group, one of
you must invite the other, and the other must confirm the invitation. Once you
group up, any submissions that either you, or your partner have already made
will be visible to each other in addition to all future submissions.


### Lab preparation

After logging in, create the directory for this lab:

```sh
mkdir -p cs24/lab9
```

Change into the lab directory and copy the files you will need for this lab:

```sh
cd cs24/lab9
cp ~bboe/public_html/cs24_f13/code/lab9/* .
```

### Min heap

#### Definition

A min heap is a tree like data structure that satisfies the min heap
properties: (__1__) it is a
[complete](https://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees)
binary tree, and (__2__) each node's value is smaller than or equal to the
value of its children. Given these properties, the root value of the tree will
always be the smallest value contained in the tree.

__Note__: A max heap is similar to a min heap, except each node's value is
larger than or equal to the value of its children.

#### Array-based implementation

The _complete_ property of the tree makes using an array the ideal data
structure for storing heaps. Thus far we have not considered using an array to
represent a tree. Let's look at the following heap example to see how it's
done:

         1
       /   \
      5     3
     /\    /
    7  9  8

This heap can be represented by the integer array:

    {1, 5, 3, 7, 9, 8}

Note that the order is simply the breadth-first traversal order assuming we
visit the left-hand-side before the right-hand-side.

Let's assume we're looking at the element `i` in the array. With respect to the
tree, at what position in the array are its children located? What about its
parent?

The computation is relatively simple:

Element `i`'s left child is at position `2 * i + 1`, and its right child is at
position `2 * i + 2`. Working in the other direction, element `i`'s parent can
be found at position `(i - 1) / 2`. Recall that when dividing integers, the
result is always rounded down (also known as the floor).

For completeness here is our array with the element values and their positions:

    element   1 5 3 7 9 8
    position  0 1 2 3 4 5

Element 5, at position 1, has children at `2 * 1 + 1`, position 3, and `2 * 1 +
2`, position 4, which correspond to values 7 and 9 respectively. Likewise its
parent is `(1 - 1) / 2`, position 0, which corresponds to value 1 as expected.

### Testing for valid heaps

In this lab you will have to implement a program, `test_heap.cpp`, that takes
command line arguments and checks if its arguments, as integers, satisfies the
min heap property.

Your program should only produce one of two outputs, either `True\n` or
`False\n`, which indicates whether or not the arguments, as integers, are given
in a valid minimum heap order. The following are some example executions:

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


### Submitting the assignment

Only one person in a group need submit the assignment but make sure that both
you and your partner can view the submission on the submission site. If you
cannot, you need to complete the making a group process. Please review the
[submission instructions]({{ base }}/submission) as needed. Note that you may resubmit
this assignment as many times as necessary up until the deadline.
