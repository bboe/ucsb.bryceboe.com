---
title: Automated Feedback Instructions &raquo; CS32 Summer 2012
---
## Automated Feedback Instructions

The submissions for all assignments in this course are done through an
automatic submission verification and testing system. It works in tandem with
the `turnin` program you should all be used to. However, in order to trigger
the feedback, you will need to use a wrapper program when you submit your
assignments.


### Submitting Assignments

Each assignment will contain the specific submission line to use for
submission. Below is the generic format each will follow:

    ~cs32/submit ASSIGNMENT_NAME@cs32 FILENAME1 FILENAME2 ...

Upon a successful submission, you should see a report similar to the following:

    These are the regular files being turned in:

                  Last Modified   Size   Filename
                  -------------- ------  -------------------------
               1: 08/01/12 11:52    357  FILENAME1

    ****************************************************************************

    You are about to turnin 1 files [1KB] for ASSIGNMENT_NAME to cs32

    *** Do you want to continue? y
    FILENAME1

    *** TURNIN OF ASSIGNMENT_NAME TO cs32 COMPLETE! ***
    Sending submission notification... connected to localhost... turnin complete!


### Receiving and Parsing the Feedback

After a reasonable amount of time, usually within a minute, you will receive an
email sent to your `@cs.ucsb.edu` email address. This email contains a report
on the verification of your submission, and, given a valid submission, reports
on your tentative score for the project.

The first section of the report provides feedback on the files you've
submitted. This feedback is provided to ensure that you've submitted the
correct files for the assignment. Furthermore, the feedback details any issues
with files themselves, such as _forbidden_ keyword detection or file size
restrictions. Finally, the last part of the report provides verbose output on
the compilation of the submitted assignment. Any compile errors will result in
a verification failure. Below is what the feedback might look like for a valid
submission:

    Status: Success
    User: bboe
    Project: hw1
    ...Finding most recent submission
            Found submission: bboe-10.tar.Z
    ...Extracting submission
            fizzbuzz.cpp
    ...Verifying files
            passed fizzbuzz.cpp
            passed README (missing optional)
    ...Making submission
            make: Entering directory `/cs/class/cs32/TURNIN/hw1/bboe'
            clang++ fizzbuzz.cpp
            make: Leaving directory `/cs/class/cs32/TURNIN/hw1/bboe'

    Verification: 2 out of 2

Note that in this assignment the submission of a `README` file is optional and
that the compile line used by the automated assessment system is `clang++
fizzbuzz.cpp`. Should the submission not pass verification, you will need to
correct any errors and then resubmit.

The next section of the feedback reports on the score for a submission. A score
is made up of the sum of the point values for various test cases. A test case
represents a unique input to your program that could be from any combination of
command-line arguments, standard input, or files your program expects to read
from. Test cases that do not produce the __exact__ same output as the reference
implementation are included in the report with the following information:

* The test name
* The point value of the test case
* The [unified diff](https://en.wikipedia.org/wiki/Diff#Unified_format) output
  that compares the reference implementation output to yours

Below is a sample of what the feedback you receive may contain:

    ...Scoring
            error_negative_value_arg - Failed (1 pt)
    -NUM is too small

            error_zero_value_arg - Failed (1 pt)
    -NUM is too small

            error_too_many_args - Failed (1 pt)
    -Usage: fizzbuzz NUM
    +1
    +2
    +fizz
    +4
    +buzz
    +fizz
    +7
    +8
    +fizz
    +buzz
    +11
    +fizz

            error_no_args - Failed (1 pt)
    -Usage: fizzbuzz NUM


    Tentative Score: 10 out of 14

In the above example, notice that the tentative score, `10 out of 14`, is at
the end of the report. We can also see that the submission failed four test
cases. You will need to familiarize yourself with the unified diff output in
order to determine how your program's output differs from the expected
output. The following are explanations of the diff output
for each failed test case reported in the above example:

* __error_negative_value_arg__: The expected output should contain "NUM is too
  small". However, your program didn't produce that output. All other output
  matched.
* __error_zero_value_arg__: The explanation is the same as the one above.
* __error_too_many_args__: The expected output is `Usage: fizzbuzz
  NUM`. However, your program didn't produce that output. Instead, it produced
  all the lines prefixed with `+`. These lines were not in the expected output.
* __error_no_args__: The explanation is similar to the explanation for
  __error_negative_value_arg__.

Note that the diff output has a limit on both the number of
lines displayed as well as the number of columns in each line.

Naturally, it is your responsibility to correct any discrepancies so that
your output matches that of the reference implementation
_character-for-character_. This matching includes newlines and other whitespace
that may be difficult or impossible to view in the feedback email.
