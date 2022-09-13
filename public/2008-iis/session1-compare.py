#!/usr/bin/env python

"""This script takes as arguments two filenames. It adds each
line in each file to a set, which is unique to each file. Finally
it calculates the difference between the two sets and prints
out the each element in the difference set"""

import sys

a = open(sys.argv[1])
b = open(sys.argv[2])

setA = set()
setB = set()

for line in a.readlines():
    setA.add(line.strip('\n'))

for line in b.readlines():
    setB.add(line.strip('\n'))

setC = setA.difference(setB)

for val in setC:
    print val
