---
title: Lab 3 &raquo; CS32 Summer 2012
---
{%- assign base = site.baseurl | append: "/cs32_m12" -%}
## Lab 3, Overloading Operators in C++

### Goals for this lab

By the end of this lab you should be comfortable with operator overloading in
C++. Additionally you will gain experience in separating implementation from
interface by using `.h` files for class declarations (the interface) and `.cpp`
files for the definitions (implementation).

### Pairing Reminder

You must work as a pair on the labs. If you were paired up last week, you need
to work with the same pair. If you did not get paired up last week, or your
pair is no longer in the class, please see the TA.

### Lab Preparation

Change into the cs32 directory, and create a lab directory:

    cd cs32
    mkdir lab3

Change into the lab3 directory and copy files you will need for this lab:

    cd lab3
    cp ~cs32/public_html/code/lab3/* .

### Building a Vec3 class

You are provided with the files `Makefile`, `main.cpp`, and `vec.h`. In this
lab, you will need to add all the functionality that `main.cpp` expects from
the `Vec3` class. You will have to both, declare new functions in `vec.h` and
write the corresponding implementation in `vec.cpp`.

#### Step 1: Add the constructors

You will need to declare and define the two constructors. This will allow you
to build the program `main` by running `make`.

#### Step 2: Add the getters and setters

Next you will need to define the getters and setters for `x`, `y` and `z`. Once
you have done that, comment out the appropriate lines in `main.cpp` to verify
you have correctly done the implementation. You will need to complete step 3
before being able to test the setters.

#### Step 3: Overload `<<` for cout

In this step you will need to overload the `<<` operator such that it outputs
Vec3 objects like so:

    ( x, y, z )

Of course, `x`, `y`, and `z` should be replaced with their `double`
values. Again, when this step is completed, uncomment the next set of lines in
`main.cpp` to verify this functionality works.

#### Step 4: Overload `>>` for cin

A Vec3 object should be created when `cin >> some_vec3_object` is contained in
a C++ program. You don't need to do any fancy verification of double
input. Simply read directly into the three doubles that the Vec3 instance
contains. Again, uncomment additional lines in `main.cpp` to test this
functionality.

For convenience, you can run your program via the following command to avoid
having to retype the numbers each time:

    echo "0.1 0.2 0.3 1.8 2.7 3.6" | ./main

#### Step 5: Overload `+` for adding two Vec3 instances

Now you will need to overload `+` so that you can add two Vec3 instances. Think
about what the parameters should be and what the return value should be. Vec3
objects should be added by adding their individual components together. For
instance `Vec3(1, 2, 3) + Vec3(4, 5, 6)` should produce `Vec3(5, 7, 9)`. Test
this functionality as previously described.

#### Step 6: Overload `*` for multiplying a Vec3 instance by a double

Finally, you will need to overload `*` so that you can multiple a Vec3 by a
double. When multiplying a Vec3 by a double, each component of the Vec3 should
be multiplied by the value of the double. For instance `Vec3(1, 2, 3) * 4`
should produce `Vec3(4, 8, 12)`.

To test this uncomment the remaining lines in `main.cpp`. By now you should be
able to successfully run the complete `main.cpp` program. Given the command
listed in step 4, `main` should produce the following output:

    Individual components of 3-param: 5.5 6.6 7.7
    From default constructor: ( 0, 0, 0 )
    From 3-param constructor: ( 5.5, 6.6, 7.7 )
    Input three doubles: Updated using setters: ( 0.1, 0.2, 0.3 )
    Input three doubles: Updated using >> overloading: ( 1.8, 2.7, 3.6 )
    The previous two added together: ( 1.9, 2.9, 3.9 )
    More addition: ( 3.8, 5.8, 7.8 )
    Simple multiplication: ( 0.8, 1.6, 2.4 )
    More multiplication: ( 0.6, 1.2, 1.8 )

### Submission Instructions

Please make only one submission per pair; this isn't essential, it just makes
life easier for the TA.

    ~cs32/submit lab3@cs32 vec.cpp vec.h

You may submit up to 20 times. Please check the feedback email to ensure you
submitted correctly, and are satisfied with your final score. If you are not,
feel free to revise and submit again. Please also review the
[automated feedback]({{ base }}/automated_feedback) instructions as needed.
