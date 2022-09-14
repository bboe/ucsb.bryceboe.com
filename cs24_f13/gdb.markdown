---
title: GDB &raquo; CS24 Fall 2013
---
# The GNU Debugger

* * *

## Command quick reference

* **run** [arg1 arg2 ...] - execute program with command line arguments
* **list** - print source code
* **print** [var] - print value of variable
* **break** [line number|function] - set breakpoint at _line number_ or _function_
* **info break**- list all breakpoints
* **delete** [n] - delete breakpoint n
* **continue** - resume execution after breakpoint
* **next** - execute next line and pause
* **step** - descend into function call an pause
* **backtrace** - show function call stack

* * *

## What is gdb?

The GNU Debugger is a program that you can use to examine your code while it is
running. It allows you to do things like pause execution of the program,
inspect variables, and view the stack. The debugger is extremely useful in
tracking down bugs because it provides you with a lot of information about the
running state of your program.

## Starting gdb

Before we can use gdb, it requires some extra information from the
compiler. We'll use the timeless *hello.c* program as our example code:

```c
#include <stdio.h>

void hello() {
  char *a = NULL;
  a[1] = "I'm a segfault!";
  printf("Hello world!\n");
}

int main() {
  hello();
  return 0;
}
```

We must compile our program with the `-g` flag to include debugging
information in the executable:

    $ clang -g hello.c # compile hello.c with debugging information

To start the debugger, we simply use the `gdb` command followed by the name of
the executable:

    $ gdb a.out # run the debugger on a.out

The gdb prompt is `(gdb)`. We can enter commands after this prompt to control
execution of our program. To run the executable in gdb we use the `run` command
followed by any command line arguments the program takes:

    (gdb) run arg1 arg2 # run a.out with the arguments "arg1" and "arg2"

## Backtrace

We can use the `backtrace` command at any time to see which functions are on the
stack. This is particularly useful after the program has been interrupted (for
example by a segmentation fault or a `^C` interrupt); we can see exactly where
the error occurred:

    Program received signal SIGSEGV, Segmentation fault.
    0x000000000040053e in hello () at hello.c:5
    5               a[1] = "I'm a segfault!";
    (gdb) backtrace # print the function stack
    #0  0x000000000040053e in hello () at hello.c:5
    #1  0x0000000000400574 in main () at hello.c:10
    (gdb)

Here we see that the segmentation fault occurred while executing line 5 of
hello.c. The backtrace shows us that it occurred in the function `hello()`
which was called by `main()`.


## Breakpoints

One of the most useful features of gdb is the ability to stop our code at
specific points called breakpoints. Breakpoints are set with the `break`
command. We can break at a line number:

    (gdb) break hello.c:4  # program will pause at line 4 of hello.c

or at a function call:

    (gdb) break hello.c:hello  # program will pause before executing hello()

We can view the breakpoints that are set using `info break`:

    (gdb) info break # list all breakpoints
    Num     Type           Disp Enb Address    What
    1       breakpoint     keep y   0x080483da in hello at hello.c:4
    2       breakpoint     keep y   0x080483ee in main at hello.c:9
    (gdb)

Breakpoints must be referenced by their number. To delete the break at line 4:

    (gdb) delete 1 # delete breakpoint 1

We can resume the program using the `continue` command:

    (gdb) continue # resume execution

Alternatively we can walk through the code using `next` and `step`. `next` will
execute the next line of code, stepping *over* any function calls and then stop:

    Breakpoint 1, main () at hello.c:9
    9               hello();
    (gdb) next # execute line 9 of hello.c and then pause at line 10
    Hello world!
    10              return 0;
    (gdb)


The `step` command will step *into* any function calls. We can use it to walk
through the function being called:

Breakpoint 1, main () at hello.c:9
9               hello();
(gdb) step # pause at the first line of the function hello()
hello () at hello.c:4
4               printf("Hello world!\n");
(gdb)

## Inspecting variables

We can examine the values of variables in our program during executing with
the "print" command:

    Breakpoint 1, hello () at hello.c:4
    4               char *a = NULL;
    (gdb) print a # print the current value of a
    $1 = 0x0
    (gdb)

Here we see that `a` is `NULL` (so we get a segmentation fault when we try to
dereference it!)

## Other useful commands

The "list" command allows you to view the source code of the program
executing.

The "help" command gives detailed instructions on how to use different gdb
commands.

Almost all of the commands in gdb can be abbreviated. For instance `r` is
equivalent to `run`, `bt` is equivalent to `backtrace` and so on. Use the help
command to see acceptable abbreviations.
