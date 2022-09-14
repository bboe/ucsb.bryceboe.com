---
title: Project 1, Part 1 &raquo; CS32 Summer 2012
---
{%- assign base = site.baseurl | append: "/cs32_m12" -%}
## Project 1, Part 1: Automating Input / Output Testing

### Motivation

Software testing is incredibly crucial in the real-world software development
cycle. Customers of a product want to be assured that, as the product is
improved (adding features, fixing bugs, optimizing), existing functionality
continues to work. When software gains complexity, such testing becomes
incredibly tedious to perform manually. Thus, many companies implement some
sort of automated testing as part of their development and product release
cycles. With automated testing, developers need only write the tests for a
specific feature once, and then the tests can be used throughout the lifecycle
of the product.

Testing software, whether by manually executing the software or by writing
tests for an automated testing framework, is a skill that needs to be exercised
just as much as programming. Thus, in this project, you are going to write a
basic input/output based automated testing tool. The end-goals are that you
will adapt this tool for your needs in future assignments, exercise your test
writing ability, and discover bugs in the code you write.

### Input/output testing

Input/output testing is a type of end-to-end testing that can be used to test
programs that produce consistent output over multiple runs of the program with
the same set of inputs. Recall that input to a program can be command line
arguments, the standard input file stream, and a few others such as environment
variables. For this project, we will only concern ourselves with the standard
input file stream.

In input/output testing, we want to enumerate as many inputs as we can, and
associate them with the output that we expect. For instance, if we are testing
the program `wc` using only the standard input stream (no command line
arguments), we will want to test a variety of file sizes.

#### Writing test case inputs

We'll start by considering ways to test `wc` with a zero byte file:

0. Redirecting standard input from `/dev/null`

        $ wc < /dev/null
              0       0       0

0. Piping the output of `echo -n` (`-n` means no ending new-line)

        $ echo -n | wc
              0       0       0

0. With a zero byte file

        $ touch input_zero_byte_file
        $ wc < input_zero_byte_file
        0 0 0

Using the last method, creating a file called input_zero_byte_file, allows us
to save our input state with some descriptive name so that we can re-test the
program without having to manually re-type the input stream. Let's take this a
step further.

First, create a directory `wc` to save our tests in and move the existing test
to the directory:

```sh
mkdir wc
mv input_zero_byte_file wc/
```

Now, create a number of test files for various word count lenghts:

```sh
echo "one" > wc/input_one_word
echo "one two" > wc/input_two_words
echo "one two three" > wc/input_three_words
```

#### Writing test case outputs

Great! We now have the input files for four tests of the program wc. Now we
need to define the expected output for each test. For each input file you
should manually create a corresponding file prefixed with `output_` that
contains the expected output of `wc` on the input file. Below is how we can
create `output_one_word`:

```sh
echo "1 1 4" > wc/output_one_word
```

You might wonder why we don't just use `wc` to generate the output. Normally
you won't be testing a program that has already been written. Instead, you will
be testing a program that you are in the process of writing. Thus, you should
always manually create your output files.


#### Running the test cases

Now that we have input files and corresponding output files, we want to
actually run tests against `wc`. We will do that by feeding wc an input file,
and comparing the output to the expected output. We will use the exit status of
the program `diff` to tell us whether or not the programs are identical. For
the program diff, an exit status of `0` means the files are identical, and
we'll consider any other exit status a failure.

For the test case `three_words` we can run the following:

```sh
wc < wc/input_three_words | diff wc/output_three_words - > /dev/null
echo $?
```

In the above command, we feed the test file `input_three_words` to wc. The
output of that command is then piped into the program diff. The `-` argument to
diff means to use the standard input stream as the second file in the
comparision. We redirect diff's output to `/dev/null` because, for this
project, we actually don't care what the diff output is. We're only concerned
if it matches the expected output or not. This information is contained in
`$?`, the exit status of the previous command.

#### Summing up the input/output testing

Up to this point, we have described input/output testing by detailing how to
write test cases (input and output files), and how to use these test cases to
verify the program behaves as expected. Combined with the knowledge of shell
scripting you gained from [lab 1]({{ base }}/lab1), you should now be
able to write a shell script to automatically run all the test cases in a given
directory for some program.


### The automated testing tool

The bourne shell script you write should be called `test_it.sh`. You can
prepare the script like so:

```sh
echo '#!/bin/sh' > test_it.sh
chmod +x test_it.sh
```

The script should accept a single argument `DIRECTORY` that points to a
directory containing zero or more subdirectories. Your script should iterate
over all the subdirectories of `DIRECTORY`, ignoring any other files. The name
of each subdirectory indicates the name of an external program that your script
will perform automated testing on. We will refer to each of these directories
as a `test directory`. For each `test directory` your script should ouput
`Testing {PROGRAM}`, replacing `{PROGAM}` with the appropriate external program
name.

Within each `test directory`, there should be zero or more test cases written
as described in the previous section. For each test, your script needs to
output whether the test `Passed` or `Failed`.

For instance, if `test_it.sh` is in the same directory as the `wc` folder we
created previously, then running `./test_it.sh .` should produce exactly the
following:

    Testing wc
    Passed: one_word
    Passed: three_words
    Passed: two_words

If we modified either `wc/input_two_words`, or `wc/output_two_words` so that
the `two_words` test no longer passed, then the output should be:

    Testing wc
    Passed: one_word
    Passed: three_words
    Failed: two_words


#### Missing output files

While your shell script should ignore any files not beginning with `input_` in
each `test directory`, the script should produce a warning message when there
is no corresponding `output_` file for a given `input_` file.

For example, if we add the files `input_something`, `input_unknown`, and
`something_to_ignore` to the `wc` folder, the output should be exactly the
following:

    Testing wc
    Passed: one_word
    No output file for wc test 'something', skipping
    Passed: three_words
    Failed: two_words
    No output file for wc test 'unknown', skipping


#### Complete example

If we have the directory `the_tests` with the following structure:

    the_tests/
        sha1sum/
            input_test_1
            input_test_2
            output_test_1
            output_test_2
        some_regular_file
        wc/
            input_one_word
            input_something
            input_three_words
            input_two_words
            input_unknown
            output_one_word
            output_three_words
            output_two_words
            something_to_ignore

then running `test_it.sh the_tests` will produce the following output if the
`wc` test `two_words` is the only failing test:

    Testing sha1sum
    Passed: test_1
    Passed: test_2
    Testing wc
    Passed: one_word
    No output file for wc test 'something', skipping
    Passed: three_words
    Failed: two_words
    No output file for wc test 'unknown', skipping

#### Error conditions

There are two error conditions for the shell script. If either condition isn't
met, your script should output the corresponding error message, and exit with
status code `1`. On success, your script should exit with status code `0`. The
following are the error conditions and associated error messages:

* The number of command line arguments is not exactly 1:

        Usage: test_it.sh DIRECTORY

* The provided DIRECTORY is not a directory (replace {DIRECTORY} with whatever
  value was input as a command line argument):

        {DIRECTORY} is not a directory


### Submission instructions

    ~cs32/submit pj1part1@cs32 test_it.sh

Please also review the [automated feedback]({{ base }}/automated_feedback)
instructions as needed.
