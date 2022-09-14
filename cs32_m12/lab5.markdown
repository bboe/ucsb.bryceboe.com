---
title: Lab 5 &raquo; CS32 Summer 2012
---
{%- assign base = site.baseurl | append: "/cs32_m12" -%}
## Lab 5, Inspecting object/load modules

### Goals for this lab

By the time you have completed this lab you should be able to:

* Identify and interpret file types with the file command.
* Inspect object and load module contents and structure with command line tools
  `strings`, `nm`, `objdump` and `readelf`.
* Explain key memory concepts for C and C++ programs.


### Pairing Reminder

You must work as a pair on the labs. If you were paired up last week, you need
to work with the same pair. If you did not get paired up last week, or your
pair is no longer in the class, please see the TA.

### Lab Preparation

Change into the cs32 directory, and create a lab directory:

    cd cs32
    mkdir lab5

Change into the lab4 directory and copy the file you will need for this lab:

    cd lab5
    cp ~cs32/public_html/code/lab5/* .


### Compile, link separately, and begin exploring the binaries

First compile with both -g and -c flags to provide debugging information and
write the object module, lab5.o to disk:

    clang++ -g -c lab5.cpp

Now create the executable file from this object file:

    clang++ -o lab5 lab5.o

Next, read and interpret the output of the file command for the three
files. Executing `file lab5*` will produce the following output:

    lab5:     ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.32, not stripped
    lab5.cpp: ASCII text
    lab5.o:   ELF 32-bit LSB relocatable, Intel 80386, version 1 (GNU/Linux), not stripped

ELF stands for "Executable and Linking Format" as you learned from the Reader
and lecture, LSB means "Linux Standard Base" (a collection of APIs meant to be
supported by all Linux systems), and SYSV abbreviates "UNIX System V." What
else can you learn from these results? And what do you suppose "not stripped"
means?

The strings command can be used to list the strings in a binary file. For
example, the relocatable object file (lab5.o) has two strings:

    $ strings lab5.o
    element 
     is 

Did you read the source code? If so, then these strings should look
familiar. Meanwhile, the executable file contains many more strings. Try
`strings lab5` to see them.


### Inspect object module names/sections with `nm`

The command `nm` lists the "names" (symbols) in an object or load module, and
`objdump` displays various information about such files. Both commands have
useful options that are worth learning.

Show the names in lab5.o via `nm lab5.o`:

    00000130 t _GLOBAL__I_a
             U _ZNSolsEPFRSoS_E
             U _ZNSolsEi
             U _ZNSt8ios_base4InitC1Ev
             U _ZNSt8ios_base4InitD1Ev
             U _ZSt4cout
             U _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
    00000028 b _ZStL8__ioinit
             U _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
    00000028 d _ZZ4mainE1k
             U __cxa_atexit
    00000000 t __cxx_global_var_init
             U __dso_handle
    00000000 D a
    00000000 B b
    00000050 T main

The values on the left side are addresses in hexadecimal, and you can show
these values in decimal with the `-td` option. The next column shows the class
of each symbol, where `T` and `t` are functions, `D` and `d` are data (global
variables), B and b are uninitialized data, and U is undefined.

Notice the names are shown in their `mangled` form by default. For example,
`_ZZ4mainE1k` is really just the static variable `k` in `main`, `_ZNSolsEi`" is
`std::ostream::operator<<(int)` in more familiar notation. The `-C` option will
decode (demangle) such symbols for you. Try it now.

By the way, the default format for nm, "BSD format" is in some cases more
difficult to read than "System V format" which can be achieved with the `-f
sysv` option. Try that now too.


### Inspect object module names/sections with `objdump`

Using `objdump` can reveal more details about object files. At least one option
must be specified.

Try it first with the `-S` option. I recommend piping the results through
`less` to view one screenful at a time. Hit `q` when you want to exit `less`:

    objdump -S lab5.o | less

According to `man`, the `-S` option will "display source code intermixed with
disassembly, if possible. Implies -d." The `-d` option means disassemble the
code.

Use `man objdump` or read the [man
 page](https://sourceware.org/binutils/docs/binutils/objdump.html) to
 learn about more options. You might like the `-l` option in particular. Use it
 along with the `-d` option as follows:

    objdump -d -l lab5.o | less

Try some other option switches. Notice for example that `-C` serves the same
purpose it did for the `nm` command. Do you remember that purpose? The `-j`
option lets you specify _just_ particular sections. Interesting sections
include `.text`, `.data`, `.rodata`, and `.ctors`, among others.


### Inspect executable module with `readelf`

Although you could use `objdump` to inspect this load module, the `readelf`
tool gives more information about load modules (so called because they are
ready to be loaded into memory for execution). As with `objdump`, at least one
option must be specified.

First learn about `readelf` from its [man
page](https://sourceware.org/binutils/docs/binutils/readelf.html).

Did you notice that the `-S` option has a different meaning for `readelf` than
it does for `objdump`? For `readelf` it means "Displays the information
contained in the file's section headers, if it has any." Use it now to find out
the names of the sections in lab5:

    readelf -S lab5


### Answer some questions

Create a file `answers.txt` and store your answers the following questions in
it. Place each answer on its own line and separate answers by at least a single
blank line:

0. What is the name of the section with the program's instructions?

0. In what section is the array named `a` stored?

0. What happened to the constant `M`? In what section is its value storred?

0. In what section is the static variable `k` stored?

0. How is the array `b` handled differently than other variables?

0. The variable `i` is handled differently too. How?


### Submission Instructions

Please make only one submission per pair; this isn't essential, it just makes
life easier for the TA.

    ~cs32/submit lab5@cs32 answers.txt

Please check the feedback email to ensure you submitted correctly. For this
lab, you will only receive a verification score (`0 out of 1` or `1 out of 1`)
to indicate that your submission was suitable for manual grading. Your actual
scores will be sent out via Piazza either Friday or Saturday following the lab.


### Special Thanks

Special thanks to [Michael Costanzo](https://sites.cs.ucsb.edu/~mikec/) for
allowing me use of his CS32 material. This lab was copied almost verbatim from
his Spring 2012 CS32 class.
