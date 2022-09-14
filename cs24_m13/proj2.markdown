---
title: Project 2 &raquo; CS24 Summer 2013
---
## Project 2: Virtual Directory Trees

__Note__: You must work independently on this assignment.

In this project, you will complete a binary search tree implementation and use
the BST to store references to other directories thus representing a virtual
directory tree. You will dynamically list, create, and destroy directories
based on input to the program.

### Goals for this project

By the time you have completed this project, you should:

* fully understand the use and implementation of a binary search tree

* be comfortable working with a general tree (a directory can have any number
  of subdirectories)


### Project Preparation

This project will use almost the same files as lab5. However, you will have to
make some modificiations to your `bst.cpp` in order to define the new
functions, and alter the return values of a few functions.

To begin create a proj2 directory (assuming you haven't already done so):

```sh
mkdir -p cs24/proj2
```

Change into the proj2 directory and copy the files you will need for this
project:

```sh
cd cs24/proj2
cp ~bboe/public_html/cs24_m13/code/proj2/* .
```

Then you will want to copy your `bst.cpp` file from your lab5 directory.

```sh
cp ../lab5/bst.cpp .
```

### Starting the project

Open up `virtual_directory.cpp` and start reading the comments. They explain
which functions you should start first. You should __not__ start working on
`BST::remove` and `remove_directory` until you have everything else working
perfectly. However, make sure you save plenty of time as `BST::remove` is the
most complicated piece of this assignment.


### Part 2

You will need to have make_directory, list_directory and change_directory
working 100% before starting part 2. Send a private piazza message to receive a
copy of my part1 code.

In part two you must complete the following tasks (you should write them in
this order):

0. Implement the `BinaryNode<T> *BST<T>::remove(T item)` method
(`bst.cpp`). Return NULL if `item` is not found in the BST, otherwise remove
the Binaryode from the tree and return a pointer to the BinaryNode (do not
deallocate the BinaryNode in this function). You will need to implement the
`BinaryNode<T> *find_max(BinaryNode<T> *node)` method to help you. When it
comes time to call `find_max` from within your recursive delete function you
would call it via `BST::find_max(root_of_subtree)`.

0. Implement the `remove_directory` function (`virtual_directory.cpp`). The
function takes in the current directory and a string containing the name of the
directory to remove. The directory matching `name` should be removed from
`cwds` list of children if it exists, otherwise output the error message if the
directory does not exist. Make sure to deallocate any memory at this point that
requires deallocation.

0. Implement the `Binarynode<T> *BST<T>::remove_root()` method
(`bst.cpp`). Remove and return the root of the tree if such a BinaryNode
exists, otherwise return NULL.

0. Implement the Directory destructor `Directory::~Directory` (just add this
function somewhere near the top of `virtual_directory.cpp`). When a Directory
is destructed it should clean up any allocations that are associated with that
directory. That includes deallocating any of its subdirectories (use
`BST::remove_root` as many times as necessary, which will implicitly
recursively remove any of its children and so on).

0. Implement the BST destructor `BST::~BST` (`bst.cpp`). The destructor should
deallocate any memory it directly allocated, i.e., the BinaryNode instances,
but it is not responsible for deallocating items that are stored within them
(nor should it as you cannot assume T is a freeable type). __NOTE__: This
function needs to deallocate memory in all cases, even if you don't end up
using one of those cases directly in project 2.


### Part 2 Hints

#### Recursive remove helper function

The recursive remove helper function can be pretty tricky to delcare correctly
so the following is how I recommend you declare the function:

```c++
template <class T>
BinaryNode<T> *remove_recursive(BinaryNode<T> *node, T item,
                                BinaryNode<T> **retval) {
    // Below is an example of how you might structure this function.
    if (MATCH) {
        // Write the code for the three remove cases
        // Update retval and return the appropriate new root of the subtree
    }
    else if (GO_LEFT)
         node->set_lhs(remove_recursive<T>(node->get_lhs(), item, retval));
    else if (GO_RIGHT)
         node->set_rhs(remove_recursive<T>(node->get_rhs(), item, retval));
    else { /* Do you need this? */ }

    /* The return value should point at the updated root of the subtree.
       If the current node isn't being removed then the return should
       not be altered. If the current node is being removed *retval should
       be set to the node that has been removed from the tree (and contains
       the T that is being removed) and the return value should point to
       the new root of the subtree.
     */
    return node;
}
```

__Note__ that the compiler has a hard time determining whether or not the T
item is a reference. To disambiguate we need to specify the template that is
used when we call the funciton. To help a bit more since I don't want you to
struggle with this part, I'll provide you with the base function that you
should use (should be in `bst.cpp`):

```c++
template <class T>
BinaryNode<T> *BST<T>::remove(T item) {
    BinaryNode<T> *retval = NULL;
    root = remove_recursive<T>(root, item, &retval);
    return retval;
}
```


### Building and testing the project

To build the project run:

    make

If successful that will produce `virtual_directory` which you can run via:

    ./virtual_directory

This program has it's own set of commands which you can list via the command
`help`. You will need to get all these commands works.
