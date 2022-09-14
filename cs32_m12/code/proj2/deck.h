#ifndef _DECK_H
#define _DECK_H

class Card;  // Forward declaration

#include <deque>
using namespace std;

/* A class for holding a set of cards */
class Deck {
 public:
  /* Constructors, destructors and assignment operator

     The copy constructor and assignment operator perform a deep copy of the
     contents of the Deck. While this "duplicates" cards, this is the expected
     behavior, otherwise, a single card could appear in multiple Decks
     simultaneously.
   */
  Deck();
  Deck(const Deck &other);
  ~Deck();
  const Deck& operator =(const Deck& other);

  /* Add a card to the bottom of the Deck */
  void add_card(Card *card);

  /* Remove a card from the top of the Deck */
  Card* get_card();

  /* Return true if the Deck contains no cards */
  bool is_empty();

  /* For each card in the Deck, call its reset function */
  void reset();

  /* Randomly shuffle the items in the Deck */
  void shuffle();
 private:
  deque<Card*> cards;
};

#endif /* _PLAYER_H */
