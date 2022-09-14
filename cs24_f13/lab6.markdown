---
title: Lab 6 &raquo; CS24 Fall 2013
---
{%- assign base = site.baseurl | append: "/cs24_f13" -%}
## Lab 6: Sorting

### Goals for this lab

By the time you have completed this lab, you should be able to sort a list
in an ascending order.

### Lab Pairing

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
mkdir -p cs24/lab6
```

Change into the lab directory and copy the files you will need for this lab:

```sh
cd cs24/lab6
cp ~bboe/public_html/cs24_f13/code/lab6/* .
```

### Overview

This lab intentionally has minimal directions. You are provided two files. In
those files you will figure out what you are being asked to do. Note that you
will only submit `sort.cpp` so only make changes to that file.

__Note__: If you follow one or more guides on a particular sort algorithm
please link to your sources in your `sort.cpp`.

For more information about different sorts check out
[some slides from a previous class]({{ site.baseurl }}/cs32_m12/slides/sort/).


### Example Execution

When completed, the following is an example of the expected execution of your
program:

    $ ./a.out beta gamma alpha delta
    0: alpha
    1: beta
    2: delta
    3: gamma

### Submitting the project

Only one person in a group need submit the assignment but make sure that both
you and your partner can view the submission on the submission site. If you
cannot, you need to complete the making a group process. Please review the
[submission instructions]({{ base }}/submission) as needed. Note that you may resubmit
this assignment as many times as necessary up until the deadline.
