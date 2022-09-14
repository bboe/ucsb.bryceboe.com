---
title: Submission Instructions &raquo; CS24 Summer 2013
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
show you the command you are to use to submit your project. It will look
something like:

    ~bboe/bin/submit -p PROJECT_ID FILENAME FILENAME

Once you have verified that your code works as it should on a CSIL machine
(`csil.cs.ucsb.edu` is a good machine to ssh into if you're working remotely)
and have executed a few test cases on it (it's really important you don't cheat
yourself out of valuable testing experience) then from a CSIL machine (not an
ECI machine) then execute the command exactly as listed on the project page.

### Common Issues

When submitting, if you see an error similar to the one below it means you are
not actually on a CSIL machine (or one sufficiently similar to it). The easiest
thing to do is to just quickly ssh into `csil.cs.ucsb.edu` to submit your work.

    /cs/student/bboe/bin/submit: line 6: /cs/student/bboe/bin/.py27/bin/python: cannot execute binary file
