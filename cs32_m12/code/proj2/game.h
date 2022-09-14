#ifndef _GAME_H
#define _GAME_H

#include <string>
#include <vector>
#include "player.h"
using namespace std;


/* This class represents a single instance of the game. */
class Game {
 public:
  /* Setup the initial game */
  Game();

  /* We _should_ have a destructor */
  ~Game();

  /* Signal that a player has died */
  void add_dead(Player *player);

  /* Add a Player to the game */
  void add_player(Player *player);

  /* Return the position of the current player */
  int get_current_player_position() const;

  /* Get the Player at position pos. 0 is the first position. Note that the
     player may be dead.
   */
  Player& get_player(int pos) const;

  /* Return the number of players who are still alive */
  int get_num_alive_players() const;

  /* Return the total number of players */
  int get_num_players() const;

  /* Return the winner */
  const Player& get_winner() const;

  /* Start playing the game */
  void play();

  /* Provide the deck to the players (called before the first play) */
  void prepare(Deck &deck);

  /* Reset the game so that it can be played again. Adjust the turn order such
     that the winner goes first, 2nd place goes 2nd, and so on
   */
  void reset();

  /* Output the state of the game */
  friend ostream& operator <<(ostream &outs, const Game &game);

 private:
  int current_player;
  vector<Player*> dead;
  vector<Player*> players;
  int turn_number;
};

#endif /* _GAME_H */
