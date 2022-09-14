---
title: Lab 2 &raquo; CS24 Summer 2013
---
{%- assign base = site.baseurl | append: "/cs24_m13" -%}
## Lab 2: Testing a program


### Goals for this lab

By the time you have completed this lab, you should

* get expirience in testing a program
* get familiar with possible error cases in the code

The purpose of this lab is to get you familiar with simple code testing.


### Lab Pairing

For this lab (and all following labs), you may work with a partner. If you do
work with a partner (please do), you will need to use the same partner
throughout the quarter. When working with a partner, I strongly encourage you
follow the pair programming method of working together. If you are not familiar
with pair programming please
[watch this video](https://www.youtube.com/watch?v=rG_U12uqRhE).

### Lab Preparation

Before you begin, let's create a subdirectory for the files for this lab. Note
that these instructions assume you are using either a CSIL machine or one of
the lab machines:

After logging in, create the directory (assuming you haven't already done so):

```sh
mkdir -p cs24/lab2
```

Change into the lab2 directory and copy the files you will need for this lab:

```sh
cd cs24/lab2
cp ~bboe/public_html/cs24_m13/code/lab2/* .
```

Open up README.txt with your favorite text editor and be sure to add your and
your partner's name so that you both receive credit.


### Testing the code

In this lab you are given an executable named `find_bugs`. This is a buggy
version (intentionally) of a program to evaluate a single math expression in
infix-notation entered via standard input. The program operates only on base10
integers, and only performs addition (+), subtraction (-), and division
(/). The operator and the numbers must be separated by a single space.

For example:

    ./find_bugs
    >Enter arithmetical expression
    >1 + 2
    3

However, some of the inputs might break the normal operation of the
executable. In this case you will see the output:

    BUG FOUND: Save as input_[n].txt

Please store your input in the corresponding txt file.


There is no source code for this executable, so that you can't see all the
issues right away.  However, I can tell you that there are 9 known bugs in the
code. Try to catch them all!


### Submitting the project

Only one person in a group need submit the project. If both members of a group
submit we will only score the last submission made between the two group
members. Please review the
[submission instructions]({{ base }}/submission) as needed. On the submission site
you will find the command you need to use to submit the project. Note that you
may resubmit this project as many times as necessary up until the deadline.
