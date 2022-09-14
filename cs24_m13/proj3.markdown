---
title: Project 3 &raquo; CS24 Summer 2013
---
{%- assign base = site.baseurl | append: "/cs24_m13" -%}
## Project 3: Emergency Room Patient Scheduling

__Note__: You must work independently on this assignment. With respect to the
use of data structures within the C++ STL please feel free to share and discuss
examples of code that utilizes these data structures. Do not, however, share
nor discuss code pertaining to solving the assignment.

In this project, you will utilize some of the data structures we have discussed
in this class to create a log of patients in an emergency room. There will be
no training wheels for this project, you will have 100% of control over the
program and thus must properly read in the input, and produce the expected
output.

### Goals for this project

By the time you have completed this project, you should:

* be comfortable parsing data from an input stream

* know which data structure to use for a particular task

* be able to use data structures contained within the C++ standard template
  library

### Project Description

For this project your program will be provided structured input to the standard
input stream (see input) that describes a number of symptoms, the doctors
available, and the times that patients arrive on a single day at hospital's
emergency room. You will output to the standard output stream a log file (see
output) containing the events as they occured that day.

### Input

Below is an example of what the input format will look like. Notice that there
are three sections to the file: priorities, doctors, and patient arrivals.

    # Priorities
    01 Cough
    05 Head Ache
    08 Bleeding
    10 Decompression Sickness
    # Doctors
    Dr. Something Orother
    # Patient Arrivals
    09:11 "Vincent van Gogh" "Bleeding" 150
    09:30 "Phineas Gage" "Head Ache" 65
    09:45 "Neil Armstrong" "Decompression Sickness" 360


#### Priorities Section

Each line within the first section can be broken into `TWO_DIGIT_NUM space
SYMPTOM` where `TWO_DIGIT_NUM` represents the priority from 0 to 99, and
`SYMPTOM` is the description of the symptom. Higher values indicate higher
priority, and the symptom can contain multiple words (it should be everything
after the separating space). You will want to __map__ each symptom to its
priority so that you can easily look up a symptom's priority by its name.

#### Doctors Section

Each line within the second section only contains a doctor's name. All
characters on the line (up to the newline) should be considered part of the
name. Doctors should be added to a __queue__ in the order that they are listed.


#### Patient Arrivals Section

Each line within the third section can be broken into `ARRIVAL_HOUR colon
ARRIVAL_MINUTE space quote PATIENT_NAME quote space quote SYMPTOM quote
VISIT_DURATION`.

`ARRIVAL_HOUR` is a number between 00 and 23. `ARRIVAL_MINUTE` is a number
between 00 and 59. These two values combined make up the time of the event. All
the events (lines) will be given in sequential order and will all occur between
00:00 and 23:59.

`PATIENT_NAME` is the name of the patient and should be everything contained
between the two double-quote characters (`"`). Likewise, `SYMPTOM` is
everything between the second set of double-quote characters.

Finally, `VISIT_DURATION` specifies the amount of time this patient spends with
the doctor when visted by the doctor.


### Output

Below is an example of what the output needs look like when given the input
above. Notice that there is one line per event.

    09:11 Vincent van Gogh arrives
    09:11 Dr. Something Orother visits Vincent van Gogh about Bleeding
    09:30 Phineas Gage arrives
    09:45 Neil Armstrong arrives
    11:41 Vincent van Gogh departs
    11:41 Dr. Something Orother visits Neil Armstrong about Decompression Sickness
    17:41 Neil Armstrong departs
    17:41 Dr. Something Orother visist Phineas Gage about Head Ache
    18:46 Phineas Gage departs

The output should be given in the order that events occur. When multiple events
occur at the same time arrivals should be listed first, followed by departures,
and finally visits. When multiple arrivals occur at the same time they should
be output in the same order as they appear on the input stream. When multiple
departures occur at the same time, they should be output in the same order that
their arrivals occured. Finally, multiple visits can only occur at the same
time if there are more than one available doctor. The patient with the highest
priority symptom should be scheduled the doctor who least-recently finished
visiting a patient. Doctors who have yet to visit a patient should be assigned
patients in their input order. When multiple patients have symptoms of equal
priority, whoever arrived first should be scheduled first.


### Project Preparation

For this assignment, you actually do not need any files. However, to make
things somewhat simpler, I have provided a `MaxHeap` class in the file
`heap.h`. While you will not submit `heap.h` this file will be available on the
submission system should you wish to use it.

To begin create a proj3 directory (assuming you haven't already done so):

```sh
mkdir -p cs24/proj3
```

Change the permissions of the cs24 directory such that only your account can
access the files inside this directory. This step is __incredibly__
important. If omitted, other students can peek at your work and you may be held
partially responsible. It should also go without saying that you may __not__
give other students access to your account. If you've done that in the past
please [change your password](https://accounts.engr.ucsb.edu/maintain/login) at
this time.

```sh
chmod 700 cs24
```

Change into the proj3 directory and copy the files you will need for this
project:

```sh
cd cs24/proj3
cp ~bboe/public_html/cs24_m13/code/proj3/* .
```


### Working with project 3

You will only submit `main.cpp` thus put all of your code in this program. You
will very likely want to utilize the `queue` and `unordered_map` libraries from
the STL, and the `MaxHeap` class from `heap.h`.

When you're ready to build and test your program run:

    make

And run your program via:

   ./er

To make testing simpler you may want to make test files and then use input
redirection to provide the test file as the standard input to your program. For
instance if you want to run your program against `sample_input.txt` you can run
one of the following:

```sh
./er < sample_input.txt
cat sample_input.txt | ./er
```

### Submitting the project

Please review the [submission instructions]({{ base }}/submission) as needed.
On the submission site you will find the command you need to use to submit the
project. Note that you may resubmit this project as many times as necessary up
until the deadline. There will be a 30 minute delay between
subsequent submission result viewings, so verify your changes by testing
locally before making submissions.
