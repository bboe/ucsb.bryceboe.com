---
title: Lab 8 &raquo; CS24 Summer 2013
---
{%- assign base = site.baseurl | append: "/cs24_m13" -%}
## Lab 8: Word Frequency Counter

### Goals for this lab

By the time you have completed this lab, you should:

* know what a hash table is
* learn about the C++ standard template library (STL)
* have more experience working with strings in C++

### Lab preparation

After logging in, create the directory for this lab:

```sh
mkdir -p cs24/lab8
```

Change into the lab2 directory and copy the files you will need for this lab:

```sh
cd cs24/lab8
cp ~bboe/public_html/cs24_m13/code/lab8/* .
```

Open up README.txt with your favorite text editor and be sure to add your and
your partner's name so that you both receive credit.

### Hash Table

#### Definition

Hash table are one of the basic data structures. It is a mapping between a
unique key and its value, that is usually stored in the form of a table (or
array).  To get the value by knowing the key we will use a hash function. A
hash function tells us where in the array a value for the given key is stored.
It calculates the (in theory unique) index in the array from the key.

For example, we have a small hash table to identify if the number is odd or
even.  It will have two records in its array:


    0 Even
    1 Odd

Now we provide hash function as `mod 2` and a number (key) `num`, that we want
to check.  We calculate index `i = num % 2` and look for an answer (value) at
`array[i]`.  If `num = 10` then `i = 10 % 2 = 0` and `array[0] = "Even"`. If
`num = 11` then `i = 11 % 2 = 1` and `array[1] = "Odd"`.

We can also use hash tables to count the number of odds and evens in some given
sequence.

Now our table array has two recores:

    0 Number of evens
    1 Number of odds

If we are encountering an even or an odd at some point in the code, we can
simply increase corresponding number in the table via `array[num % 2]++;`

In this case our key, that is some number, maps to a value that is a number of
the occurences of the same type numbers.

Tomorrow in class we will discuss implementation details of hash
tables. However, for today's lab you will just need to use an existing hash
table. Hash tables in general can store many more than 2 items, in fact they
can store an unbounded number of items with the right implementation.

### Standard Template Library

In the previous labs we have talked about C++ templates. Turns out there is a
library with a bunch of very useful templates that are ready to use.

#### vector

One template is the `vector` template that allows you to create a dynamic array
of an arbitrary type and provides methods for dynamic memory allocation.  Here
is an example of code that creates a string array and adds

```c++
#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> nums(3, 5);  // create array of 3 ints, initialize to 5s
                             // nums = [5, 5, 5]
    nums.push_back(6);       // add 6 in the end
                             // nums = [5, 5, 5, 6]
    nums.pop_back();         // remove the last element
                             // nums = [5, 5, 5]
    for(vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
        cout << *i << endl;  // prints out the content of the nums
    return 0;
}
```

As a template is a container built to use with an arbitrary type, it makes
sence to implement a special type of pointers, that would work with
containers. These are called iterators. In the example above, to iterate
through a vector of integers we declare (right in the middle of the code)
`vector<int>::iterator i`. We say that we start from the first element `i =
vector.begin()` and we print numbers until `i` is pointing to the "end"
element, which is one after the last in the vector `i != nums.end()`.
Iterators have very similar arithmetics to pointers. `i++` will move iterator
to one position forward, `nums.begin() + 4` will be pointing to the element at
position nums[4] and `*i` will return a value that is stored at a current
position.

#### string

Another example are strings. Strings are containers specificaly to store
strings and provide a number of popular methods.

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Assume the standard input stream contains "abc qwe\n345\n"
    string s1, s2, s3;
    cin >> s1;  // "abc"
    cin >> s2;  // "qwe"
    cin >> s3;  // "345"
    s1 = s1 + s2 + s3;
    cout << s1 << endl;  // abcqwe345
    return 0;
}
```

#### unordered_map (hash table)

One more example is `unordered_map`, that is an implementation of a hash table
mapping key to value.


```c++
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int value;
    string key("abc");
    unsorted_map<string, int> hash_table;  // initialize the hash table

    // test if a key is contained in the hash table
    cout << (hash_table.find(key) != hash_table.end()) << endl;  // 0

    // Accessing an item that was not previously contained will add it
    // using the default constructor (initialize to 0 for type int)
    cout << hash_table[key] << endl;  // 0

    // test if a key is contained in the hash table
    cout << (hash_table.find(key) != hash_table.end()) << endl;  // 1

    hash_table[key]++;  // Increment the key
    cout << hash_table[key] << endl;  // 1

    return 0;
}
```

If we want to iterate trough the table, then we have to create appropriate
iterator `unordered_map<string, int>::iterator it = hash_table.begin();`

Each element returned by the hash table iterator is of type `pair` that
contains two attributes: `first`, the key; and `second`, the value.  To refer
separately to the key try `it->first`, for the value try `it->second`.

__NOTE__: The `unordered_map` class does not exist in older versions of
C++. Thus in order to compile this program (and your lab8 program) you will
need to add `-std=c++11` to the clang compile line.

#### sort

Finally, there is a numper of popular algorithms, implemented in STL. For
example, in this lab we will be using `sort`. Sort will sort elements in
ascending order, unless provided a sorting function that specifies how we
compare two elements.

For example, if we wanted to output the elements of our hash table in reverse
(descending) order based on the key we would do the following:

{% raw %}
```c++
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

bool sort_reverse(const pair<string, int> &a, const pair<string, int> &b) {
  return a.first > b.first;
}

int main(){
  // Initialize the hash table with some fun values
  unordered_map<string, int> ht = {{"Bananas", 10}, {"Apples", 16},
                                   {"Pears", 8}, {"Zebras", 1}};

  // unorderd_map iterators cannot be sorted so we must copy its contents
  // into a vector
  vector<pair<string, int> > values(ht.begin(), ht.end());
  // sort all of the values in the vector using the function `reverse` for
  // comparisons
  sort(values.begin(), values.end(), sort_reverse);

  // Output the items
  // The `auto` keyword in C++11 will automatically determine its type.
  // In this case its type is: vector<pair<string, int> >::iterator
  for(auto it = values.begin(); it != values.end(); ++it)
    cout << it->first << " " << it->second << endl;

  return 0;
}
```
{% endraw %}

### Writing frequency.cpp

In this lab you will be writing a program that calculates number of ocurrences
of words in a standard input. It should print out statistics on the encountered
words. The order of the output should be such that the most frequently used
words are listed first, and words of the same frequency are sorted
alphanumerically.

Words can include punctuation and are separated by any form of
whitespace. Using `cin >> term` where term is a string will handle the
whitespace issue for you. All comparisons should be case insensitive, meaning
that `IS`, `Is`, `iS`, and `is` should all be counted as one word, `is`. You
will need to write a function that converts a string to its lowercase form. You
probably want to use the `tolower` function to help you with that.

For example `echo "ASD aSd asd sdf dfg." | ./a.out` should produce the output:

    3 asd
    1 dfg.
    1 sdf

### Submitting the project

Only one person in a group need submit the project. If both members of a group
submit we will only score the last submission made between the two group
members. Please review the
[submission instructions]({{ base }}/submission) as needed. On the submission site
you will find the command you need to use to submit the project. Note that you
may resubmit this project as many times as necessary up until the deadline.
