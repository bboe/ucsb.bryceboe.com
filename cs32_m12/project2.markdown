---
title: Project 2 &raquo; CS32 Summer 2012
---
{%- assign base = site.baseurl | append: "/cs32_m12" -%}
## Project 2, A Semi-Simple Turn-based Card Game

### Motivation

To learn and demonstrate proper class inheritance. And to have fun with a
simple card game.

### Project Setup

Change into the cs32 directory, and create a proj2 directory:

```sh
cd cs32
mkdir proj2
```

Change into the proj2 directory and copy files you will need for this project:

```sh
cd proj2
cp  -r ~cs32/public_html/code/proj2/* .
```

At this point all the files you fetched are read only except for the files you
will need to modify.


### Implementation Part 1: Player class inheritance

For the first part of this assignment, you will need to write three descendants
to the Player class. The code for each of these classes should only be added to
`custom_players.h` and `custom_players.cpp`.

The classes you have to implement are:

 * AttackWeakestPlayer (9 pts)
 * HumanPlayer (9 pts)
 * AttackStrongest3xPlayer (9 pts)

The descriptions for what each does are contained in `custom_players.h`. The
comments should be more than enough information to get you started.


### Implementation Part 2: Card class inheritance

For the second part of the assignment, you will need to write five descendants
to the Card class. These changes need to be made to `custom_cards.h` and
`custom_cards.cpp`. The five classes you need to implement are described fully
in `custom_cards.h`.

The classes you have to implement are:

 * AccumlatorCard (9 pts)
 * KillMultiplierCard (9 pts)
 * ReflectorCard (9 pts)
 * SnowballCard (9 pts)
 * TransformationCard (9 pts)


### Building and running play

To build the program you need only run:

    make

This will produce the executable play that can be run via:

    ./play INPUT_FILE NUM_GAMES [SEED]


The INPUT_FILE should be a file constructed similar to such as `tests/initial`
or `tests/all` that describe the players and cards for the game. In order to
create player instances other than `AttackNextPlayer` you will need to
uncomment the appropriate `else if` conditions in `main.cpp` in the function
`read_in_game_data`. The same is true if you wish to create card instances
other than the base Card class.

The NUM_GAMES argument should be a number that is greater than 0. This
indicates how many rounds should be played.

The SEED argument, when present, should be any number. The seed value is used
to seed the random number generator. In a nutshell, when the SEED argument is
given, random will behave the same for each iteration with the same SEED
value. That means everytime you run `./play 10 0` it will produce the exact
same output. However, that output will differ from `./play 10 1`.

When no SEED argument is provided, the random number generator is seeded with
the current time. Effectively, the output will be different for every
invocation.


### Submission Instructions

For this project you will be allowed 20 submissions. You will receive up to 16
lines of diff output for each test case.

    ~cs32/submit proj2@cs32 custom_*.h custom_*.cpp

__Note on the feedback for this project__: In order to prevent a major
dependency between your implementation of the `Card` classes and the `Player`
classes when testing this project, the feedback system builds the projects
slightly differently than you build them. When the feedback system is testing
your `Player` classes, it builds the project using the _solution_ version of
the `Card` classes. Likewise, the feedback system uses the _solution_ version
of the `Player` classes when testing your `Card` classes.


Please check the feedback email to ensure you submitted correctly, and are
satisfied with your final score. If you are not, feel free to revise and submit
again. Please also review the
[automated feedback]({{ base }}/automated_feedback) instructions as needed.
