---
title: Bourne Shell Scripting &raquo; CS32 Summer 2012
---
## An introduction to bourne shell scripting

The bourne shell appears to be the most widely distributed shell available on
unix-based systems. While it is not as powerful as newer shells such as bash
(bourne again shell) or csh, we will write bourne shell scripts for their
portability and its compatability with many modern shells.

A bourne shell script is simply a plain text file that contains commands you
might normally run in the bourne shell in addition to a few other useful
constructs we are famililar with from C and C++. In this document, we will
demonstrate each of the following features with simple bourne shell script
examples:

 * Command line arguments
 * String concatenation
 * Variable assignment and usage
 * Conditionals
 * Loops


For a more complete reference please see the
[Bourne Shell Programming](https://www.ooblick.com/text/sh/) page provided by
ooblick.com.

### Hello World

```sh
#!/bin/sh
echo "Hello world"
```

The first line, `#!/bin/sh`, tells the operating system that the file should be
processed with the executable /bin/sh. If this line is omitted, then whatever
script is responsible for launching the shell script will execute the commands.

On the second line we tell the program to invoke the external command `echo`
with the argument "Hello world".

Save the above as `example.sh` and perform the following tasks (you'll want to
follow this proceedure for all examples):

0. Execute the command `chmod +x example.sh` to mark the script as executable
0. Run the script by typing the command `./example.sh`

You can also run the script via the command `sh hello.sh`. Doing so does not
require the script to be executable, and will ignore the `#!/bin/sh` line at
the top of the script. This is useful if you want to run the script in a
different shell wihtout modifing the script contents: `bash hello.sh`.

### Command line arguments and string concatenation

```sh
#!/bin/sh
echo "All arguments: $*"   # Doesn't include the script name
echo "Script name: $0"     # Output the script name
echo "First argument: $1"  # Output the first command line argument
echo "Num args: $#"        # Output the number of arguments
```

If you run the above script via `example.sh a b c` you should see the following
output:

    All arguments: a b c
    Script name: ./example.sh
    First argument: a
    Num args: 3

Take note that `$*` doesn't include the script name `$0` and that this argument
is not counted in `$#`. This differs from the `int argc, char *argv[]`
parameters for C/C++ programs which do count argv[0] as an argument. Also
notice that we are referring to variables from within the strings, in spite of
whatever type that variable holds.

### Variables and capturing external commands' output

```sh
#!/bin/sh
msg_string="Path to script:"
prog_name=$(basename $0) # Assign the output of the command "basename $0"
                         # to the variable prog_name
cur_directory=$(pwd)     # Do something similiar with pwd
echo "$msg_string: $cur_directory/$prog_name"
```

In the above example, we see three examples of variable assignment. On line
two, we directly assign a string to the variable `msg_string`. Note that we do
not use `$` when assigning a value to a variable. However, the `$` must be used
when attempting to recall the stored value.

It is also important to know that the __lack__ of whitespace around `=` is very
important. An `=` character surrounded by whitespace has a completely different
meaning (comparision) in bourne shell scripting.

On lines 3 and 5, we see the usage of $(_COMMAND LINE_). This syntax is used to
execute the command between the `( )` and capture its output. In this case, we
use the program `basename` to convert `./example.sh` into `example.sh` and the
program `pwd` to tell us our present working directory. We store the results of
those commands in the variables `prog_name` and `cur_directory` respectively.

Finally, on line 6, we demonstrate another example of string concatenation,
this time combining three separate variables into a single string.


### Conditionals

```sh
#!/bin/sh
if [ $# -ne 0 ]; then
    echo "There are command line arguments"
else
    echo "There are no command line arguments"
fi
```

In the above example, we demonstrate the use of an if/else conditional on the
condition that the number of arguments does not equal zero. Again, please note
that whitespace is crucial in some places. Here the whitespace after `[` and
before `]` are necessary.

In addition to the typical number comparision operators (`eq`, `ne`, `gt`,
`ge`, `lt`, `le`), bourne shell also allows for the testing of paths to check
if the path points to a regular file, `-f`, a directory, `-d`, or a few
others. In the following example, we confirm that our current directory, `.`, is, in
fact, a directory and not a file.

```sh
#!/bin/sh
if [ -d . -a ! -f . ]; then
    echo ". is in fact a directory and not a file."
else
    echo "This should never be true."
fi
```

In the above conditional, I introduced the _logical and_, `-a`, between two
independent conditions, `-d .` and `! -f .`. The `!` preceding the second
condition is the _logical negation_.

### Basic Looping

```sh
#!/bin/sh
for filename in $(ls); do
    echo $filename
done
```

In the above example, we loop over the list of filenames in the current
directory as reported by the command `ls`. The variable `filename` holds the
result of the current iteration.

This example is as much detail as I will provide on looping in bourne scripts
as it should be all that's needed for this class. I do, however, want to make a
note that looping over files in this manor does not work if a filename has a
space character in it. For more on this issue, please see [this
resource](https://www.cyberciti.biz/tips/handling-filenames-with-spaces-in-bash.html).
