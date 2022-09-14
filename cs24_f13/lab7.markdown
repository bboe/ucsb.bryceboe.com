---
title: Lab 7 &raquo; CS24 Fall 2013
---
{%- assign base = site.baseurl | append: "/cs24_f13" -%}
## Lab 7: Binary Search Trees

### Deadline Note

This lab is a bit more complex than some of the previous labs, thus you will
have until Wednesday (2013/11/13) just before midnight (23:59:59) to complete
this lab.

### Goals for this lab

By the time you have completed this lab, you should

 * learn about Tree ADT
 * implement parts of the Binary Search Tree ADT
 * get familiar with using Stack and Queue ADT
 * understand depth first and breadth first tree traversals

The purpose of this lab is for you to get familiar with the tree ADT. A tree is
another basic abstract data type, which is widely used in computer
science. Because of the tree-like structure, there are multiple ways to
traverse data in a tree.  In this lab you will get familiar with and implement
some frequently used BST operations.


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
mkdir -p cs24/lab7
```

Change into the lab7 directory and copy the files you will need for this lab:

```sh
cd cs24/lab7
cp ~bboe/public_html/cs24_f13/code/lab7/* .
```

### Trees and Binary Search Trees

#### Trees

A tree, in general is a data structure that, similar to a List, consists of
nodes with data and, this time, one or more pointers to other nodes. However, a
tree structure has an important requirement: no two pointers point to the same
node. This property is important, because tree must not have any loops.  From
the requirement it follows that each node may have only one parent (the node,
that is pointing to it), except for the very top one, which is called root. The
root has no parents, (similar to the head node in the List).  Nodes that don't
have any children (no nodes pointed to) are called leaf nodes.  (Similar to the
tail node in the List).  More about the trees are on the [wiki
page](https://en.wikipedia.org/wiki/Tree_(data_structure)).

#### Binary Trees, Binary Search Trees

There is a special type of tree called the Binary Tree. Each of its nodes must
have no more than two children, usually distinguished as left and right. Among
the Binary Trees there are Binary Search Trees, for which there are additional
requirements, enforcing data in the tree to be structured in some way. First of
all, there must be no duplicate nodes in the tree (nodes with the same data
value). Secondly, for every node its left subtree (a tree that has its left
child as a root) should consist only of nodes whose values (the data contained
within it) are all less than its value.  Additionally, for every node its right
subtree (a tree that has its right child as a root) should consist only of
nodes with values greater than its value.  Finally, left and right subtrees
should also be a BST themselves.  More on
[BSTs](https://en.wikipedia.org/wiki/Binary_search_tree). Below is an example
BST created when inserting the following integers: 5, 3, 7, 4, 2, 6, 8

Insert the 5:

         5

Insert the 3:

         5
       -/
      3

Insert the 7:

         5
       -/ \-
      3     7

Insert the 4:


         5
       -/ \-
      3     7
       \
        4

Insert the 2:

         5
       -/ \-
      3     7
     / \
    2   4


Insert the 6:

         5
       -/ \-
      3     7
     / \   /
    2   4 6

And finally, insert the 8:

         5
       -/ \-
      3     7
     / \   / \
    2   4 6   8

#### Inserting and searching in BST

Since the data in a BST follows the aforementioned structure, BSTs have an
advantage in search operation over the List.  The search algorithm itself is
very easy. You start at the root node and compare its data with one you are
looking for. If it matches, you return and appriopriate value. When it does not
match and the value you are searching for is greater than the node's value
traverse down the right child (why?). If the value you are searching for is
less than the node's value traverse down the left child (why?). This process is
repeated until a match is found, or there are no children in the appropriate
search direction.

When inserting a node in a BST it is important that the new tree still has
original properties.  Therefore, it is important to select proper position for
a new node. The insertion algorithm is similar to search, for except when we
will reach a NULL pointer, we create a node and insert it in that position.

#### Templates in C++

Thus far we have discussed abstract data values in the BST node without
mentioning the type we want to store specifically. In theory, BST nodes can
contain data of any type: integers, chars, strings, etc. But in C++ , when you
declare a node class, you must specify the data type in the very beginning. If
later we want to have the same structure with a different data type, we will
have to duplicate the code and only change the type.  We will have to keep
adding code for every new type we want to use. For someone writing code, this
quite inefficient and error prone. To avoid this routine, C++ provides
templates. Templates allow you to create functions and classes with a generic
type.  The type is then passed as template parameter to the newly created
function or class. Here is an example.

Creating a template class:

```c++
template <class T>
Node{
  private:
    T data;
  public:
    Node(T data): data(data) {}
};
```

Creating an integer and char nodes:

```c++
Node<int> node_int(20);
Node<char> node_char('z');
```

For more on templates see the
[week 6 example]({{ base }}/examples/week6/templates.cpp) and/or
[this tutorial](https://www.cplusplus.com/doc/tutorial/templates/).


### Creating a BST

For this lab you are given a few source files and your goal is to complete the
implementation of the BST class in `bst.cpp`. The specification for each of
those functions (and all the other BST functions) are provided in `bst.h`.

Initially, when you create a BST, the constructor should create only a root
pointer equal to NULL (an empty tree).  If you want to grow your tree, you
should implement and use the `insert` method for creating and adding nodes to
the tree.


### Breadth First Search vs Depth First Search

After you've created your BST, it is time to traverse it!  As you might notice,
there are multiple possibilities to traverse the BST because at every step you
have an option to move to the left child or to the right child or to the node
on the same level (same number of nodes away from the root as the current one).

Commonly, __depth first search__ (traversal) is the one where you consistently
move towards left or right children and when you've reached the leaf node go
one level up and move towards the child you haven't checked out (the right or
left one, respectively).  If you've checked out all of the _descendants_ of
this node, go one level up.

For example, a depth first traversal of the above tree will output nodes in the
following order (this assumes you first output the node you are "visiting" and
then "visit" the left hand side before the right hand side):

    5 3 2 4 7 6 8 

The provided `stack_output` function (in `bst.h`) output should match the above
exactly (note that there is trailing space before the newline (for
simplicity). More on [dfs](https://en.wikipedia.org/wiki/Depth-first_search).

Depth first traversal of a tree can be conveniently implemented with the help
of stack. We initialize the stack with the root node, and then loop until the
stack is empty. The first step of the loop is to do "something" with the value
of the node we're currently looking at (may be to output it in the case of
`stack_output`) and then we push both of its children (if they exist) on to the
stack. Note that because of the way items are added/removed from the stack we
push the right-hand side on before the left-hand side to acheive the expected
left-to-right output.

__Breadth first search__ (traversal) is the one where you consistently move to
the nodes on the same level from left to right or in opposite directions. For
example, a breadth first traversal of the above tree will output nodes in the
following order:

    5 3 7 2 4 6 8 

Your `queue_output` function output should match the above output exactly (note
that there is trailing space before you output the newline. More on
[bfs](https://en.wikipedia.org/wiki/Breadth-first_search).

Conveniently, breadth first search can be implemented by using queues rather
than stacks in a manor similar to how depth first search was implemented
(replace `push` with `enqueue` and `pop` with `dequeue`).


### Provided Files

* _Makefile_ A simple makefile for building the lab. Just run `make` to compile
  everything.

* _bst.h_ - This file contains the definition of the BST class. You do not have
  to modify this file but you are responsible for understanding all of the
  code.

* \_data_structures.h This file contains the definitions for the BinaryNode
  class as well as the Queue and Stack data structures.  You do not have to
  modify this file but you are responsible for understanding all of the code.

* _bst.cpp_ This file contains stubs for the functions that you will implement.
  To complete the lab you must write the following methods for BST:

	* destructor
	* insert
	* queue_output (BFS traversal)

* _driver.cpp_ Provides an interface for inserting nodes into the BST (based
  off the command line arguments), and testing whether or not the integers 0
  through 10 are contained in the BST.

### Hints

#### Traversing the BST using a Stack or Queue

The linear structure of a List allows us to traverse the elements without
having to keep track of the ones we've already visited. However BSTs do not
afford us this convenience. Consider the BST in the example above:

          5
        -/ \-
       3     7
      / \   / \
     2   4 6   8

Let's say we are in the midst of a DFS and we are currently at node 4. How are
we to find the next node (7)? Trying to individually store each node we
traverse would lead to messy and inefficient code. A much better solution is to
store the nodes in another data structure to keep track of them. Consider a DFS
using a stack. We initialize by pushing 5 onto the stack:

          5         Stack: 5
        -/ \-
       3     7
      / \   / \
     2   4 6   8

We then iterate over the following steps until the stack is empty:

	WHILE stack is not empty:
		POP the last element
		PUSH its left child
		PUSH its RIGHT child
		PRINT the element
	END WHILE

After 1 iteration (the star indicates that we've printed this node):

         *5         Stack: 3 7
        -/ \-
       3     7
      / \   / \
     2   4 6   8

After 2 iterations:

         *5         Stack: 2 4 7
        -/ \-
      *3     7
      / \   / \
     2   4 6   8

After 2 iterations:


         *5         Stack: 4 7
        -/ \-
      *3     7
      / \   / \
    *2   4 6   8

After 3 iterations:

         *5         Stack: 7
        -/ \-
      *3     7
      / \   / \
    *2  *4 6   8

After 4 iterations:

         *5         Stack: 6 8
        -/ \-
      *3    *7
      / \   / \
    *2  *4 6   8

Until we've traversed all of the elements. In this lab you will have to perform
a BFS in a similar manner using a Queue.

#### Declaring the Stack and Queue

To implement `queue_output` and `stack_output` you need to respectively declare
both a templated version of the Stack class, and one of the Queue class. If the
Stack, or Queue needed to store integers, you could declare them like:

```c++
Stack<int> stack_variable_name;
Queue<int> queue_variable_name;
```

However, you want to store a pointer to the proper tree node type,
`BinaryNode`. To make things slightly more confusing, the BinaryNode type is
also templated so you need to specify what type the BinaryNode should be. If
you knew for certain the BinaryNode is to store a character, then you might
declare the Stack and Queue like:

```c++
Stack<BinaryNode<char>*> char_stack;
Queue<BinaryNode<char>*> char_queue;
```

However, your BST implementation is templated so it should work with whatever
type the _user_ of your program uses. That's where the magic `T` variable as
declared in the line `template <class T>` comes in handy. `T` specifies what
type the class holds so you can simply replace `char` in our previous example
with `T` like the following in order to declare the Stack and Queue for the
respective functions:

```c++
Stack<BinaryNode<T>*> stack;
Queue<BinaryNode<T>*> queue;
```

### Submitting the project

Only one person in a group need submit the assignment but make sure that both
you and your partner can view the submission on the submission site. If you
cannot, you need to complete the making a group process. Please review the
[submission instructions]({{ base }}/submission) as needed. Note that you may resubmit
this assignment as many times as necessary up until the deadline.
