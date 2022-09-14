---
title: Lab 1 &raquo; CS32 Summer 2012
---
{%- assign base = site.baseurl | append: "/cs32_m12" -%}
## Lab 1, Linux programs and Shell scripting

In this lab you will write a bourne shell script that computes the average
number of lines contained by files in a given directory.

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

Change into the cs32 directory, and create a lab1 directory:

    cd cs32
    mkdir lab1

Note that you do not need to change the permissions of the lab1 directory or
any files inside of cs32 because permissions cascade. If you wanted to lock
down your entire account you could run `chmod 700 ~`; however, no one would be
able to access your website if that were the case.

Change into the lab1 directory and create the empty files you will need for
this lab:

    cd lab1
    touch README line_average.sh


### Exploring a few linux programs

Below is a list of linux programs you will need to use to complete this
lab:

* cut
* echo
* expr
* ls
* wc

For each program, do the following:

0. Use the `man` program to look up what each does: `man PROG`
0. In the README, indicate the program name by providing an example invocation
   of the program such as `man ls`. Additionally, describe what that invocation
   of the program should produce assuming it runs successfully.

Example README for other programs:

    mkdir blah
     - Will create the directory blah in the current working directory if blah
       does not already exist.

    touch foo bar
    - Will update both the access and modification times of the files foo and
      bar. Will create a zero byte version of the files if they do not already
      exist.

### Bourne shell scripting: line_average.sh

To review the bourne shell scripting concepts that you will need to complete
this lab, please see the [introduction to bourne shell scripting]({{ base }}/bourne).

In this part of the lab, you will write a bourne shell script that computes the
average number of lines for all the regular files in a given directory.

For testing and demonstration purposes, the following commands are how I
created a simple test directory:

    mkdir tests
    echo -e "foo\nbar\nbaz" > tests/file1
    touch tests/zero

Running `ls -l` on the tests directory should produce a similar output:

    total 4
    -rw-r--r-- 1 bboe grad 12 Aug  8 22:55 file1
    -rw-r--r-- 1 bboe grad  0 Aug  8 22:55 zero

Conceptually, `file1` has 3 lines, and `zero` has zero lines. You can confirm
that using `wc`. Thus the shell script you will write should confirm that the
average is 1 (using integer division is required).

Execution via `./line_average.sh tests` should produce the following output:

    # files: 2
    avg lines: 1

#### Error checking

Your script should output the following error message verbatim if the number
of command line arguments is not 1:

    Usage line_average.sh DIRECTORY

If the provided argument `DIRECTORY` is not actually a directory, your script
should output the following error message verbatim:

    {DIRECTORY} is not a directory

The `{DIRECTORY}` part of the error message should be replaced with whatever
the user input as the first argument. Here is an example:

    $ ./line_average.sh nope
    nope is not a directory

#### Successful output

Your program should iterate through the list of regular files contained in
DIRECTORY and produce an output containing the number of regular files and the
average number of lines contained within those regular files, if any.

For instance, if there are no regular files in DIRECTORY, then the output
should be exactly:

    # files: 0

If there is a single regular file with 5 lines in DIRECTORY, then the output
should be exactly:

    # files: 1
    avg lines: 5


#### Hints

0. At some point you should need to extract a portion of a process's
   output. Look carefully through the man pages for the programs referenced
   earlier in the lab on how to do this. Make sure your solution doesn't depend
   on numbers being in the same column location.
0. You also will need to perform some basic math. This isn't trivial in shell
   scripts as it relies on external programs. Again, I suggest looking through
   the previously referenced programs.


### Submission Instructions

Please make only one submission per pair; this isn't essential, it just makes
life easier for the TA. In either case, ensure the TA has recorded with whom
you are working. For your comfort, you may include both of your names in the
README file.

    ~cs32/submit lab1@cs32 README line_average.sh

You may submit up to 20 times. Please check the feedback email to ensure you
submitted correctly, and are satisfied with your final score. If you are not,
feel free to revise and submit again.
