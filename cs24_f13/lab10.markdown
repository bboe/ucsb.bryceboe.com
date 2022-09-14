---
title: Lab 10 &raquo; CS24 Fall 2013
---
{%- assign base = site.baseurl | append: "/cs24_f13" -%}
## Lab 10: Word Frequency Counter

### Goals for this lab

By the time you have completed this lab, you should:

* know what a hash table is
* understand that the C++ standard template library (STL) provides
  implementations of the data structures we discussed in this class (use them!)
* have experience working with a few STL classes

### Lab pairing

For this lab you may work with a partner. To facilitate your submissions as a
pair you __MUST__ pair up using the submission system. When you visit the
project page from where you can view all your submission you should see a link
to a page where you can join a group. Of the two people in the group, one of
you must invite the other, and the other must confirm the invitation. Once you
group up, any submissions that either you, or your partner have already made
will be visible to each other in addition to all future submissions.

### Lab preparation

After logging in, create the directory for this lab:

```sh
mkdir -p cs24/lab10
```

Change into the lab directory and copy the files you will need for this lab:

```sh
cd cs24/lab10
cp ~bboe/public_html/cs24_f13/code/lab10/* .
```


### Hash table

#### Definition

A hash table is an incredibly useful container data structure. A hash table is
an unordered mapping between a unique key and a value. The operations `insert`,
`contains`, and `remove` each run in constant time on average. The speed is
acheived by utilizing a clever storage mechanism in combination with an
intentional abundance of storage space.

#### Internal structure

In a nutshell, values (and their associated keys) stored within a hash table
are stored at some position in an array. That position is calculated by passing
the key through a hash function which returns values ranging from zero to one
less than the size of the array.

For example, assume we have a small hash table to identify if a given number is
odd or even.  It will have two records in its array:

    0 "Even"
    1 "Odd"

Say we have the hash function `return key % 2 == 0` that returns `0` if the key
is divisible by 2, and `1` otherwise. Thus given any number we can look up its
value in the hash table, which in this contrived example tells us whether the
number is odd or even.

In the previous example we use our simple example to fetch or access a
value. Hash tables can also be utilized to store or update a value. For
instance we can also use hash tables to count the number of odds and evens in
some given sequence.

Now our table array has the following records:

    0 # evens
    1 # odds

If we are encountering an even or an odd at some point in the code, we can
simply increase corresponding number in the table via `array[hash_result]++;`

In this case, our key maps to a value that corresponds to the number of similar
(odd or even) numbers.

In class we will discuss in more depth the implementation details of hash
tables. However, for the lab you will just need to use an existing hash
table. Hash tables, in general, can store many more than 2 items, in fact they
can store an unbounded number of items with the right implementation.


### Standard Template Library (STL)

Throughout this class we have implemented a number of data structures. When we
started working with C++ we made those data structures generic by templating
them. As it turns out, in the real world you seldom need to write the
implementation for a data structure as they are often provided either directly
by the language, or through a library for the language. In C++, the standard
template library, or STL, provides some form of all the data structures we
discuss in this class (among others).

The following are some you will want to use in this lab.

#### vector

One such ADT is the `vector` class that allows you to create a dynamic array of
an arbitrary type and provides methods for insertion and removal (similar to
our array-based List implementation). The following is an example utilizing a
vector of integers:

```c++
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums(3, 5);  // create array of 3 ints, each initialized to 5
                             // nums = [5, 5, 5]
    nums.push_back(6);       // add 6 in the end
                             // nums = [5, 5, 5, 6]
    nums.pop_back();         // remove the last element
                             // nums = [5, 5, 5]
    for(vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
        cout << *i << endl;  // outputs the content of each item in nums
    return 0;
}
```

Aside from the `vector` there is one new concept in the above example code: the
`iterator`. In general, an iterator is a pointer-like object that is used to
traverse through elements in ADTs that support them. They are pointer-like
because the value stored at the element is obtainable by dereferencing the
iterator, and incrementing, or decrementing (for iterators that are
bidirectional) the iterator by one will advance to the next or previous item in
the ADT.

In the example above, to iterate through a vector of integers we declare (in
the for loop) `vector<int>::iterator i`. We say that we start from the first
element `i = vector.begin()` and we print numbers until `i` is pointing to the
"end" element, which is one after the last in the vector `i != nums.end()`.


#### string

We've already seen strings in this class. However, for completeness reference
the following example if needed.

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Assume the standard input stream contains "abc qwe\n345\n"
    string s1, s2, s3;
    cin >> s1;  // s1 = "abc"
    cin >> s2;  // s2 = "qwe"
    cin >> s3;  // s3 = "345"
    s1 = s1 + s2 + s3;
    cout << s1 << endl;  // abcqwe345\n
    return 0;
}
```


#### unordered_map (hash table)

One more example is `unordered_map`, which is an implementation of a hash table
that maps a key to value.


```c++
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int value;
    string key("abc");
    unordered_map<string, int> hash_table;  // initialize the hash table

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

The first thing to note in this example is that the `unordered_map` class
requires two template arguments. The first represents the type of the _key_, in
this case a string, and the second represents the type of the _value_, in this
case an int.

If we want to iterate through the table (you will have to do some form of this
for the lab), then we have to create appropriate iterator
`unordered_map<string, int>::iterator it = hash_table.begin();`

Each element returned by the hash table iterator is of type `pair` that
contains two attributes: `first`, the key; and `second`, the value.  To refer
separately to the key try `it->first`, for the value try `it->second`.

__NOTE__: The `unordered_map` class does not exist in older versions of
C++. Thus in order to compile this program (and your lab10 program) you will
need to add `-std=c++11` to the clang compile line.


#### sort

Finally, the STL provides a numper of often used/needed algorithms. For
example, in this lab we will be using the `sort` function. The sort function
will sort elements in ascending order, unless provided a _sorting_ function
that specifies how individual elements should be compared.

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
  // into a something sortable -- here we use a vector
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

In this lab you will write a program that calculates number of occurrences of
unique words given via standard input. The program should print out statistics
of the encountered words. The order of the output should be such that the most
frequently used words are listed first, and words of the same frequency are
sorted according to however strings are sorted by default (lexicographically).

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

It is also worth noting that the result of `cin >> term` can be used as a
boolean expression indicating whether or not the the input of type term
succeeded. The expression will evaluate to false when EOF is reached.

### Submitting the assignment

Only one person in a group need submit the assignment but make sure that both
you and your partner can view the submission on the submission site. If you
cannot, you need to complete the making a group process. Please review the
[submission instructions]({{ base }}/submission) as needed. Note that you may resubmit
this assignment as many times as necessary up until the deadline.
