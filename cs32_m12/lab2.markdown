---
title: Lab 2 &raquo; CS32 Summer 2012
---
{%- assign base = site.baseurl | append: "/cs32_m12" -%}
## Lab 2, A simple C++ class

### Goals for this lab

By the time you have completed this lab, you should be able to:

* Fundamentally define a C++ class, and know how it differs from a struct
* Use objects of a class in application progroms
* Implement a class's methods outside the class definition
* Better understand the distinction between an abstraction, its application and
  its implementation - and how it can be realized with C++


### Pairing Reminder

You must work as a pair on the labs. If you were paired up last week, you need
to work with the same pair. If you did not get paired up last week, or your
pair is no longer in the class, please see the TA.


### Lab Preparation

Before you begin, let's prepare your cs32 directory in your home directory if
you don't already have one. Note that these instructions assume you are using
either a CSIL machine or one of the lab machines:

Create the directory:

    mkdir cs32

Change the permissions such that only your account can access the files inside
this directory. This step is incredibly important. If omitted, other students
can peek at your work and you may be held partially responsible.

    chmod 700 cs32

Change into the cs32 directory, and create a lab2 directory:

    cd cs32
    mkdir lab2

Note that you do not need to change the permissions of the lab2 directory or
any files inside of cs32 because permissions cascade. If you wanted to lock
down your entire account you could run `chmod 700 ~`; however, no one would be
able to access your website if that were the case.

Change into the lab2 directory and copy files you will need for this lab:

    cd lab2
    cp ~cs32/public_html/code/lab2/* .


### Distinguish procedural from an object-oriented design

Look over grading1.cpp, the less object-oriented version of today's program. It
does use a `struct` to manage a student's collection of grades, but that's as
object-oriented as it gets. Essentially, this is a C program in C++ clothing -
the overall program design is procedural. Still you should make sure you know
what it does and how it works before improving it.

This program solves the textbook's Programming Project 1 on page 594. Briefly,
it is a grading program for a class with these policies:

* two quizzes worth 10 points each
* one midterm and one final exam worth 100 points each
* overall grade based on 50 percent for the final exam, 25 percent for midterm
  and 25 percent for quizzes. Further, 90+ earns A, 80-90 earns B, 70-80 earns
  C, 60-70 earns D, and otherwise F.

The program reads 4 numbers from `stdin`, and calculates and prints the
associated letter grade. It does no error-checking. Compile via:

    make grading1

Execute grading1 via:

    ./grading1

You should see the following output (note you'll have to type `9 9 40 90`
followed by return):

    Enter scores in this order: 2 quizzes, midterm, final: 9 9 40 90
    Grade is B

Notice an important feature of the code in grading1.cpp: the data values in the
global structure definition are directly accessable to all parts of the
program. Unless otherwise specified, all members of a C++ `struct` are
`public`. These data values are manipulated in three of the external functions:
`getScores`, `overallGrade`, and `main`. It would be difficult to reuse parts
of this code in other programs, and also difficult for multiple programmers to
work together on separate parts of the code.

Be sure you understand why this design is not optimal, before continuing to the
next step.

### Convert a struct to a class

Now it's time to do (a variation of) the textbook's Programming Project 2 on
page 595, which is to "Redo Programming Project 1 ... but this time make the
student record type a class type instead of a structure type."

Open grading2.cpp with an editor (e.g., emacs). No need to read the code, as it
is unchanged from grading1.cpp - only the comments are new. We'll guide you
through this first step of the conversion, to properly define `class
Record`. Make _just_ the following changes to the file:

0. Redefine a Record object to be a `class` instead of a `struct`, by changing
   line 7 as instructed.

0. The first section of a class definition traditionally is its public
   interface. In C++ that means adding the keyword `public` and a colon, `:`,
   on a line by itself - otherwise, all parts of a class by default are
   private. Add that line now.

0. In a moment you will make the data private, but that means you must provide
   a way for clients of the class to set data values, but _only because this
   problem requires that clients have that capability_. To that end, declare a
   method named `setGrades` in the public section. This method should take four
   `double` arguments, and its return type should be `void`. Just declare the
   method here - it will be implemented later. The declaration does not require
   names for the parameters, only types, but if you want to name them here
   anyway, we suggest `q1`, `q2`, `m` and `f`, in that order.

0. _Before_ the data values are declared, add the keyword `private` and a colon
   to identify the rest of the class as private parts.

0. It's time for some cut and paste, and then some editing. Move the function
   _prototype_ of `letterEquiv` into the _private_ section of the class
   definition - it will become a class member function ("method"), but only to
   be used by other class members. Also add the keyword `const` to the end of
   its signature, so it can support constant objects.

0. Now move the function prototype of `overallGrade` into the class's _public_
   section, so it becomes part of a Record's interface. This method will
   calculate a Record object's own letter grade, so it won't need any
   parameter! Therefore, remove the parameter from the signature, and add the
   keyword `const` to the end.

By the way, be sure to leave the function prototype of getScores in-between the
class definition and main - it will remain as an external function.

The program will not successfully compile now, but the part inside the class
definition should compile without errors. Try compiling it now to verify that
the first error is not until the second statement in main:

    make grading2

Verify that the first error reported is located somewhere in main. In case you
need more guidance with the instructions in this section (or the next one),
have a look at example.cpp. The example program defines, applies and implements
a simple date class, in a manor that isvery similar to the grading2.cpp
program.


### Finish implementing the object-oriented design

The (uppercase) comments in the rest of grading2.cpp include specific
instructions as well as hints about what needs to be done to complete the
conversion. Here are some general guidelines to help you understand _why_ these
changes must be made.

* In `main`, the function `overallGrade` is not being used properly anymore,
  because overallGrade is now a member function of the Record class, and it no
  longer accepts an argument. Actually, now the object named `rec` is able to
  calculate and return its own grade. Use the object's name and the dot, `.`,
  operator to invoke the method (without any arguments).

* In function `getScores`, currently the data values of the Record object
  (`result`) are being set directly. That can't work anymore. The only way to
  set the values of the object's data is to use the public method `setGrades`.

* The function definition _signatures_ for `letterEquiv` and `overallGrade`
  both must be changed in two ways: (a) they must identify themselves as part
  of class Record - using the scope resolution operator, `::`, correctly; and
  (b) they must be declared `const` to match their new signatures in the class
  definition.

* Also remember that `overallGrade` has no parameter anymore. So that means no
  variable named `r` to use. That's okay though, because now this function is a
  class member, so it can access the _calling object's_ private data by name
  alone.

Compile and test the program to be sure it works correctly after all your
changes. Fix any problems before submitting.


### Submission Instructions

Please make only one submission per pair; this isn't essential, it just makes
life easier for the TA.

    ~cs32/submit lab2@cs32 grading2.cpp

You may submit up to 20 times. Please check the feedback email to ensure you
submitted correctly, and are satisfied with your final score. If you are not,
feel free to revise and submit again. Please also review the
[automated feedback]({{ base }}/automated_feedback) instructions as needed.


### Special Thanks

Special thanks to [Michael Costanzo](https://sites.cs.ucsb.edu/~mikec/) for
allowing me use of his CS32 material. This lab was copied almost verbatim from
his Spring 2012 CS32 class.
