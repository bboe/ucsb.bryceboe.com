---
title: Lab 5 &raquo; CS24 Summer 2013
---
{%- assign base = site.baseurl | append: "/cs24_m13" -%}
## Lab 5: Binary Search Tree traversals

### Deadline Note

This lab is a bit more complex than some of the previous labs, thus you will
have until Thursday (2013/08/01) just before midnight (23:59:59) to complete
this lab.

### Goals for this lab

By the time you have completed this lab, you should

 * learn about tree ADT
 * implement your own Binary Search Tree ADT
 * get familiar with using Stack and Queue ADT
 * implement depth first search and breadth first search traversals

The purpose of this lab is for you to get familiar with the tree ADT. A tree is
another basic abstract data type, which is widely used in computer
science. Because of the tree-like structure, there are multiple ways to
traverse data in a tree.  In this lab you will get familiar with and implement
two frequently used traversal operations: depth first search and breadth first
search.


### Lab pairing

For this lab you may work with a partner. Please, team up with the same person
you were working on the previous labs. When working with a partner, I strongly
encourage you follow the pair programming method of working together.

### Lab preparation

After logging in, create the directory for this lab:

```sh
mkdir -p cs24/lab5
```

Change into the lab2 directory and copy the files you will need for this lab:

```sh
cd cs24/lab5
cp ~bboe/public_html/cs24_m13/code/lab5/* .
```

Open up README.txt with your favorite text editor and be sure to add your and
your partner's name so that you both receive credit.

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

There are special type of trees called Binary Trees. Each of its nodes must
have no more than two children, usually distinguished as left and right. Among
the Binary Trees there are Binary Search Trees, for which there are additional
requirements, enforcing data in the tree to be sorted in some way.  First of
all, there must be no duplicate nodes in the tree (nodes with the same data
value) [for this lab you needn't enforce this requirement].  Secondly, for
every node its left subtree (a tree that has its left child as a root) should
consist only of nodes with keys less than its key.  Additionally, for every
node its right subtree (a tree that has its right child as a root) should
consist only of nodes with keys greater than its key.  Finally, left and right
subtrees should also be BST themselves.  More on
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

Since the data in BST is already presorted, it has advantage in search
operation over the List.  The search algorithm itself is very easy. You start
at the root node and compare its data with one you are looking for. If it
matches, you return true. When it does not match and node's data is greater
than what you are searching for you traverse down the right child (why?). If
the node's data is less than what you are searching for you traverse down the
left child (why?). This process is repeated until a match is found, or there
are no future nodes to traverse on the path.

When inserting a node in BST it is important that the new tree still has
original properties.  Therefore, it is important to select proper position for
a new node. The insertion algorithm is similar to search, for except when we
will reach a NULL pointer, we create a node and insert it in that position.

#### Templates in C++

Thus far we have discussed abstract data values in the BST node without
mentioning the type we want to store specifically. In theory, BST nodes can
containing data of any type: integers, chars, strings, etc. But in C++ , when
you declare a node class, you must specify the data type in the very
beginning. If later we want to have the same structure with a different data
type, we will have to duplicate the code and only change the type.  We will
have to keep adding code for every new type we want to use. This is very
inefficient.  To avoid this routine C++ provides templates. Templates allow you
to create functions and classes with a generic type.  The type is then passed
as template parameter to the newly created function or class. Here is an
example.

Creating a template class:

```c++
template <class T>
Node{
  private:
    T data;
  public:
    Node(T data) { this->data = data; }
};
```

Creating an integer and char nodes:

```c++
Node<int> node_int(20);
Node<char> node_char('z');
```

More on [templates](https://www.cplusplus.com/doc/tutorial/templates/).


### Creating BST

For this lab you are given a source file and your goal is to complete
functionality of BST class, that is declared in the `bst.cpp`.

Initially, when you create a BST, the constructor should create only a root
pointer equal to NULL (an empty tree).  If you want to grow your tree, you
should implement and use the `insert` method for creating and adding nodes to
the tree.


### Breadth First Search vs Depth First Search

After you've created your BST, it is time to traverse it!  As you might notice,
there are multiple possibilities to traverse BST because at every step you have
an option to move to left child or to the right child or to the node on the
same level (same number of nodes away from the root as the current one).

Commonly, __depth first search__ (traversal) is the one, where you consistently
move towards left or right children and when reached the leaf node go one level
up and move towards the child, you haven't checked out (the right or left one,
correspondingly).  If you've checked out all of the children of this node, go
one level up.

For example, a depth first traversal of the above tree will output nodes in the
following order (this assumes you "visit" the left hand side before the right
hand side):

    5 3 2 4 7 6 8 

Your `stack_output` function output should match the above exactly (note that
there is trailing space before you output the terminal newline. More on
[dfs](https://en.wikipedia.org/wiki/Depth-first_search).

Depth first traversal of a tree can be conveniently implemented with the help
of stack. We initialize the stack with the root node, and then loop until the
stack is empty. The first step of the loop is to do "something" with the value
of the node we're currently looking at (may be to output it in the case of
`stack_output`) and then we push both of its children (if they exist) on to the
stack (you have to figure out which order).

__Breadth first search__ (traversal) is the one where you consistently move to
the nodes on the same level from left to right or in opposite directions. For
example, a breadth first traversal of the above tree will output nodes in the
following order:

    5 3 7 2 4 6 8 

Your `queue_output` function output should match the above exactly (note that
there is trailing space before you output the terminal newline. More on
[bfs](https://en.wikipedia.org/wiki/Breadth-first_search).

Conveniently, breadth first search can be implemented by using queues rather
than stacks in a manor similar to how depth first search was implemented
(replace push with enqueue and pop with dequeue).

For the lab, there are two methods you have to implement: `stack_output` and
`queue_output` which correspond to dfs and bfs.


### Hints

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

As a quick note, if you simply wanted to store copies and not pointers to
BinaryNodes in the Stack (for example) you would need to add a space between
the two closing `>` characters as per the C++ syntax rules (`>>` is the
shift-right operator):

```c++
Stack<BinaryNode<T> > stack;
```

### Submitting the project

Only one person in a group need submit the project. If both members of a group
submit we will only score the last submission made between the two group
members. Please review the
[submission instructions]({{ base }}/submission) as needed. On the submission site
you will find the command you need to use to submit the project. Note that you
may resubmit this project as many times as necessary up until the deadline.
