#ifndef _PLAYER_H
#define _PLAYER_H

class Card;  // Forward declaration
class Game;  // Forward declaration

#include <string>
#include "card.h"
#include "deck.h"
using namespace std;


/* An abstract class that represents a player in the game. */
class Player {
 public:
  /* This constant represents how much hp each player has at the start of the
     game. This value cannot be exceeded (enforced in increase_hp).
   */
  static const int STARTING_HP = 100;

  /* The only constructor for Player classes
     Params:
       -name: the name of the player
       -gender: 0:it, 1:female, 2:male
   */
  Player(const string &name, int gender);

  /* Decrease the Player's hp */
  void decrease_hp(int amount);

  /* Internally used to output "itself", "herself", or "himself" */
  const string get_gender_string() const;

  /* The amount of hp the Player has */
  int get_hp() const;

  /* Return the name of the Player */
  const string& get_name() const;

  /* Increase the Player's hp */
  void increase_hp(int amount);

  /* True if the player's hp > 0 */
  bool is_alive() const;

  /* Called before the first game is started to setup the Player's deck and
     to provide the Player with a pointer to the game object.
   */
  void join_game(Deck &deck, Game *game);

  /* Reset the Player's state to that of the beginning of the game. This is
     virtual so that you can override its functionality if needed.
   */
  virtual void reset();

  /* When it's the Player's turn, this function is invoked with the card to
     play as an argument. This function _should be_ overridden by child
     classes.
   */
  virtual void take_turn(Card& card) = 0;

  /* turn_wrapper is called by the game object when it's the Player's turn. This
     funciton is reponsible for fetching the next card, shuffling the deck if
     necessary, calling take_turn, and finally discarding the card.
   */
  void turn_wrapper();

  /* Conveniently output the Player name and their hp status */
  friend ostream& operator <<(ostream &outs, const Player &rhs);
 protected:
  /* All Player instances have access to the functions of the game state
     through this variable.
   */
  Game *game;
 private:
  Deck deck;
  Deck discard;
  int gender;
  int hp;
  string name;
};


/*
 * Players of this class will always attack the next Player according to
 * turn-order and heal themselves. Use this class as a reference for
 * implementing other Player subclasses.
 */
class AttackNextPlayer: public Player {
 public:
  AttackNextPlayer(const string &name, int gender);
  void take_turn(Card &card);
};


/* Use this function to prompt the user with a number input.
 *
 * message can be whatever you want the prompt message to be. It will only be
 * output when the user is actually typing into the terminal. More precisely,
 * when the input stream is being redirected from a file, the message will not
 * be output.
 *
 * min is the minimum integer value that is acceptable as a reponse
 * max is the maximum integer value that is acceptable as a reponse
 *
 * The function will loop until valid input is provided or the EOF is
 * reached. If EOF occurs, this function will exit the program.
 *
 * The return value will be the valid selection of the user.
 */
int prompt(const string &message, int min, int max);


#endif /* _PLAYER_H */
