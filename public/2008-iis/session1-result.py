#!/usr/bin/env python
import sys

"""The following was what we dynamically created durring the session.
There are some large commented out sections because we no longer had use
for that section, but were left for future reference"""


def doSomething(list):
    #a = 1
    a = """if 'a' in list:
        print 'This is in the list'
        return
    else:
        print 'Not in the list'
        print list
    for i,var in enumerate(list):
        print i,var
        print str(i) + " " + str(var)
        print "%s %s" % (i,var)

    print "Hello",
    print "my name is bryce"
        
    for i in range(len(list)):
        print i,list[i]

    """

#doSomething('b c d e'.split(' '))
#i,j = 1,2

# Get user input
"""
name = raw_input("Enter Your name: ")
try:
    age = int(raw_input("Enter Age: "))
    #a = ()
    #a[1] = 0
except ValueError, e:
    print e
    print "age invalid type"
    age = 0
except:
    raise
print name
print age
"""
    
#sys.stderr.write("I'm printing to stderr\n")

if __name__ == '__main__':
    #print 'Executed'
    if len(sys.argv) != 3:
        sys.stderr.write("Usage: %s file1 file2\n" % sys.argv[0])
        sys.exit(1) #Exit with return value of 1
    #print sys.argv

    try:
        f1 = open(sys.argv[1])
        f2 = open(sys.argv[2])
    except IOError,e:
        sys.stderr.write("IOError -- invalid files\n")
        sys.exit(1)
    except:
        raise

    for line in f1.readlines():
        print line

    #dataf1 = f1.read()
    dataf2 = f2.read()

    print dataf1
    print dataf2
    
