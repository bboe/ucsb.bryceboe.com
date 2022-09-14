#ifndef _CARD_H
#define _CARD_H

class Player;  // Forward declaration

#include <string>
using namespace std;

/* A class to represent a card in the game. All Cards must have a name and
   hp. When the hp value is negative the card is an attack card. When the hp
   value is positive, the card is a healing card. The card hp will never be 0.
 */
class Card {
 public:
  Card(const string &name, int hp);

  /* A virtual "copy constructor". You must implement this function in
     inherited classes.

     Note that it should always return type Card* but the data the Card* points
     to should be an instance of the appropriate child Card class..
   */
  virtual Card* clone() const;

  /* The card has been discarded, thus it is ready to be used again. */
  virtual void discard();

  /* Return the amount of hp the card is worth. Negative values indicate the
     card is an attack card, and postive values indicate a healing card.

     Child classes may want to override this function to add accumulators or
     multipliers.
   */
  virtual int get_hp() const;

  /* Return the name of the card. */
  const string& get_name() const;

  /* This function is called when the from Player has decided to attack or heal
     the to Player with hp amount of hp. If needed this function can be
     overridden in a child Card class.

     The hp value passed to this function will always be positive. Use the
     card's get_hp function to determine if the hp should be added or
     subtracted.
   */
  virtual void perform_action(Player &from, Player &to, int hp);

  /* This function should be called by the Player class in the take_turn
     function. It is responsible for verification, calling the perform_action
     function and finally reporting of the event.

     The hp value passed to this function should always be positive.
   */
  void play(Player &from, Player &to, int hp);

  /* Reset the card for a new game. If needed this function can be overridden
     in a child Card class.
   */
  virtual void reset();

  /* Output the name of the card and its current hp value. */
  friend ostream& operator <<(ostream &outs, const Card &card);
 protected:
  /* Cards can be used only once a turn. This must be set false on discard */
  bool used;
 private:
  int hp;
  string name;
};

#endif /* _CARD_H */
