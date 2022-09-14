---
title: Lab 8 &raquo; CS24 Fall 2013
---
{%- assign base = site.baseurl | append: "/cs24_f13" -%}
## Lab 8: Recursion

### Updates

* You may __not__ use `static` variables in your recursive functions.

### Goals for this lab

By the time you have completed this lab, you should be familiar with recursion
and merge sort.

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
mkdir -p cs24/lab8
```

Change into the lab directory and copy the files you will need for this lab:

```sh
cd cs24/lab8
cp ~bboe/public_html/cs24_f13/code/lab8/* .
```

### Overview

This lab intentionally has minimal directions. You are provided three files. In
those files you will figure out what you are being asked to do. Note that you
will only submit `recursion.cpp` so only make changes to that file.

The wikipedia article on merge sort adequately describes the various
implementations of merge sort. You may find [this
section](https://en.wikipedia.org/wiki/Merge_sort#Top-down_implementation_using_lists)
of particular value.

__Note__: You must write recursive implementations for the two functions you
write.

### Example execution

When completed, the following is an example of the expected execution of your
program:

    $ ./a.out foo bar flah
    Original array
    foo bar flah 
    
    There are 1 items with value foo in the array.
    Sorted array
    bar flah foo 
    
    For 3 items there were the following merges:
     * 1 merge(s) of 2 items
     * 1 merge(s) of 3 items
    
    Total: 5
    n*log(n) = 4.75


__Note__: You must divide the problem such that your merge counts of various
sizes match what is expected (this shouldn't be an issue).

### Hints

The bulk of this assignment is to figure out how to use recursion to solve
these problems. If you find yourself writing a lot of code, you are not doing
it _properly_. For reference, my solution only requires 8 additional lines of
code.

### Submitting the assignment

Only one person in a group need submit the assignment but make sure that both
you and your partner can view the submission on the submission site. If you
cannot, you need to complete the making a group process. Please review the
[submission instructions]({{ base }}/submission) as needed. Note that you may resubmit
this assignment as many times as necessary up until the deadline.
