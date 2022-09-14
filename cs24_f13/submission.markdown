---
title: Submission Instructions &raquo; CS24 Fall 2013
---
## Submitting using submit.cs

All non-written assignments this quarter will utilize the
__submit.cs__ system. This system not only handles
the submission of the files, but can also provide you with nearly immediate
feedback on your submission. This submission system is intended to help you
iteratively make improvements to the programs you submit, thus you are allowed
to resubmit as many times as you want. Note, however, that on some of the
assignments you may have to wait some period of time to receive subsequent
feedback if you make multiple submissions in a small window of time.


### Getting Started

Before you can make submissions, you will need an account on
__submit.cs__. Use whatever
email you prefer to signup (your email is your username, and can be used if you
forget your password). However, in the _name_ field you __must__ enter your
name as listed in GOLD if you want to get credit for your submissions.

Once you've created your account, you need to join the class. Note that you
will need to login if you have not already.


### Making Submissions

After you've joined the appropriate course, you should find a list of available
projects on the course specific page. Clicking on the link for the project will
both provide you with a link to submit via the on-line submission form, and
show you the command line you are to use to submit your project.

#### Testing before submitting

Before making any submission you should verify that your code compiles on a
CSIL machine (`csil.cs.ucsb.edu` is a good machine to ssh into if you're
working remotely), and is an improvement upon any previous submissions. To do
the latter you should come up with your own set of test cases that you run
against your program before making a submission. A huge part of being a good
programmer is being a good tester, so don't skip on this step. As the quarter
progresses, you will have to wait a longer period of time to receive feedback
so it's important that have confidence in the code you submit.

#### Making an on-line submission

If you are using the online submission system, you can either select one or
more files to upload via the browse button, or drag and drop the files to
submit. If the online uploader does not work for you, try using a different
browser (it works with the latest versions of Chrome, Firefox and Safari).


#### Submitting via command line

From a CSIL machine (not an ECI machine) execute the command exactly as listed
on the project page. Your current working directory should be such that it
contains the files you wish to submit. The command will look something like:

    ~bboe/bin/submit -p PROJECT_ID FILENAME...


### Common Issues

When submitting via command line, if you see an error similar to the one below
it means you are not actually on a CSIL machine (or one sufficiently similar to
it). The easiest thing to do is to just quickly ssh into `csil.cs.ucsb.edu` to
submit your work.

    /cs/student/bboe/bin/submit: line 6: /cs/student/bboe/bin/.py27/bin/python: cannot execute binary file
