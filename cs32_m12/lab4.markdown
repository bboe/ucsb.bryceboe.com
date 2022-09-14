---
title: Lab 4 &raquo; CS32 Summer 2012
---
{%- assign base = site.baseurl | append: "/cs32_m12" -%}
## Lab 4, Inheritance in C++

### Goals for this lab

By the time you have completed this lab, you should be able to

* Explain how data and functions are inherited
* Work with base class and derived class objects in applications
* Identify proper and improper use of inheritance

### Pairing Reminder

You must work as a pair on the labs. If you were paired up last week, you need
to work with the same pair. If you did not get paired up last week, or your
pair is no longer in the class, please see the TA.

### Lab Preparation

Change into the cs32 directory, and create a lab directory:

    cd cs32
    mkdir lab4

Change into the lab4 directory and copy files you will need for this lab:

    cd lab4
    cp ~cs32/public_html/code/lab4/* .


### Step 1: Using inheritance

Compile `simple.cpp` and run the resulting program. Start playing with the
commented lines and understand how inheritance works.

For example, uncomment the line labelled `A1` (line number 47 in the original
file) to see another way the class `Child` can access the variable named `age`
in class `Parent` - in this case, by using the __inherited__ method named
`getAge()`. Be sure to notice that no object is specified in the call to
`getAge()`. Do you know which object is _implicitly_ specified in that call?
Then uncomment the `A2` and `A3` lines, both of which access the inherited
`age` data in other ways. Go ahead and compile it now to verify it still is
syntactically correct, but no sense running it until you start making the `B`
labelled changes.

Uncomment the `B1` section next, then compile and run. Trace what just
happened: a `Child` object was used to invoke two `Child` methods, but those
methods in turn invoked `Parent` methods to affect the inherited variable
`age`. Now uncomment the `B2` section, compile and run again. Then pause and
reflect on what that code does: a `Child` object was used to invoke a `Parent`
method directly (`C.increaseAge()`), proof that the `Child` class inherited the
public interface of class `Parent`. Uncomment the `B3` section next, and
compile and run another time. This section demonstrates how the `Child` object
can be used to invoke a `Parent` class method even when that same method is
_redefined_ (or _overridden_ if the function was virtual) in the `Child` class,
and it demonstrates how using the method without scope resolution (`Parent::`)
will __hide__ the Parent method that has the same name.

Uncomment the `B4` section, and try to compile again. Oops. Why? What type of
object is being asked to do the work in this section, a `Child` or a `Parent`?
Whereas a `Child` inherits all of the `Parent`'s interface, the `Parent` does
not have any of the `Child`'s additional features - in this case, `P` does not
have a `printAge()` method. Does it?

For now, turn the `B4` section back into a comment.

Now uncomment the `C1` area (function `printSSN()` in class `Child`) and
compile the program. The error you get is self-explanatory, but ask your TA in
case you don't understand the problem. You will fix this problem one way in the
next step.


### Step 2: Protected members

The `Child` methods that worked with the inherited `age` variable did not
suffer from the same problem as you saw for `printSSN()` above, because age is
declared __protected__ in class `Parent` instead of __private__ like `ssn`. The
protected access specifier allows derived classes access, but not other classes
(to other classes it means the same as private). Purists avoid this type of
access, but you might as well learn about it now, and then learn to get around
the problem a better way.

We'll keep the rest of these instructions short - we believe you will figure
out what to do quickly on your own.

Change the qualifier of the `ssn` variable on `simple.cpp` from step 1, and
modify the constructors accordingly to give an initial value of `1024` to the
variable. Then invoke the `printSSN()` function from main on the instace of
`C`.

The output your program produces at this point should be exactly:

    sizeof(Parent) = 8
    sizeof(Child) = 8
    This is Parent::increaseAge: My age: 7 And now I am one year older
    Parent::age 8
    getAge() 8
    Parent::getAge() 8
    age 8
    This is Parent::increaseAge: My age: 8 And now I am one year older
    Parent::age 9
    getAge() 9
    Parent::getAge() 9
    age 9
    SetAge method from Parent class
    SetAge method from Parent class
    This is Child::setAge
    Parent::age 55
    getAge() 55
    Parent::getAge() 55
    age 55
    My SSN number is: 1024


### Step 3: Redefining versus Overloading

Open up `overloading.cpp` and add to this program a new member variable
`months` - in class `Baby` only.  Modify the constructor in order to initialize
`months` accordingly.  Then add a new __overloaded__ version of the function
`setAge()` to the `Baby` class (leave the existing one alone). This function
should take into account not only the years but also the additional months of a
baby's age and it should print accordingly the age exactly like the following
(with variable years and months of course):

    This is overloaded Baby::setAge: I am <AGE> and <MONTHS> months

Last add a __redefined__ version of the fuction `printAge()` to the `Baby`
class in order to print something identical to the following:

    Baby::age: I am <AGE> and <MONTHS> months

Finally, uncomment the last two statements in main to test out these
features. Your completed program should produce output identical to the
following:

    SetAge method from Parent class
    This is Baby::setAge
    Baby::age: I am 2 and 0 months
    This is my age:2
    This is Baby::increaseAge. I won't tell you my age, because I have redifined my parent's function
    Baby::age: I am 3 and 0 months
    This is my age:3
    This is overloaded Baby::setAge: I am 3 and 5 months
    Baby::age: I am 3 and 5 months


### Submission Instructions

Please make only one submission per pair; this isn't essential, it just makes
life easier for the TA.

    ~cs32/submit lab4@cs32 overloading.cpp simple.cpp

You may submit up to 20 times. Please check the feedback email to ensure you
submitted correctly, and are satisfied with your final score. If you are not,
feel free to revise and submit again. Please also review the
[automated feedback]({{ base }}/automated_feedback) instructions as needed.


### Special Thanks

Special thanks to [Michael Costanzo](https://sites.cs.ucsb.edu/~mikec/) for
allowing me use of his CS32 material. This lab was copied almost verbatim from
his Spring 2012 CS32 class.
