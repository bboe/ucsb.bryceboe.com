---
title: Lab 6 &raquo; CS24 Summer 2013
---
{%- assign base = site.baseurl | append: "/cs24_m13" -%}
## Lab 6: Sorting

### Goals for this lab

By the time you have completed this lab, you should be able to sort a list
in an ascending order.

### Lab preparation

After logging in, create the directory for this lab:

```sh
mkdir -p cs24/lab6
```

Change into the lab2 directory and copy the files you will need for this lab:

```sh
cd cs24/lab6
cp ~bboe/public_html/cs24_m13/code/lab6/* .
```

Open up README.txt with your favorite text editor and be sure to add your and
your partner's name so that you both receive credit.

### Overview

This lab is a very small one. All you need to do is to write `sort` function
(definition in sort.cpp) for the `List` class. You can implement any of the
bubble, insertion or selection sort algorithms.

For more information about different sorts visit
[this link]({{ base }}/slides/sort/)

Note: You may want to use the `Node` class now has `set_data` method.

### Submitting the project

Only one person in a group need submit the project. If both members of a group
submit we will only score the last submission made between the two group
members. Please review the
[submission instructions]({{ base }}/submission) as needed. On the submission site
you will find the command you need to use to submit the project. Note that you
may resubmit this project as many times as necessary up until the deadline.
