#ifndef _CUSTOM_PLAYERS_H
#define _CUSTOM_PLAYERS_H

#include "player.h"
using namespace std;


/* Players of this classs use the strategy of always attacking the weakest
   player, excluding themselves of course. In the event of a tie, players of
   this class should attack the one that most immediately follows them in
   turn-order.
 */
class AttackWeakestPlayer: public Player {
 public:
  AttackWeakestPlayer(const string &name, int gender);
  void take_turn(Card &card);
};


/* Players of this class represent human players. For each turn, a prompt
   should be made informing the player what card is being played, what its hp
   value is and finally asking the human which player to attack and with how
   much hp.

   When prompting for which player to perform the action upon, expect the
   response to be in the range -1 to num_players - 1. These values should
   directly correlate with the player positions. A value of -1 means that the
   card is not being played.

   When prompting for the amount of hp to use in the action, expect the
   response to be in the range 1 to abs(card.get_hp()). You will need to
   convert the returned absolute hp value into the appropriate value expected
   by the Card's play function.

   You should use the prompt function declared in player.h for this purpose.
 */
class HumanPlayer: public Player {
 public:
  HumanPlayer(const string &name, int gender);
  void take_turn(Card &card);
};


/* Players of this class use the strategy of always attacking the strongest
   player three times before moving on to the next strongest player.

   You will need some way of keeping track of state so that when no attack has
   been made yet, or a 3-attack cycle had just been completed on another player
   we can select the next strongest target upon an attack card. When an attack
   card is played this player needs to determine the strongest player
   (excluding themselves). In the event of a tie, the player that most
   immediately follows the current player in turn order should be selected.

   Before the next strongest player is selected, the targeted "strong" player
   must be attacked three times or have died.
 */
class AttackStrongest3xPlayer: public Player {
 public:
  AttackStrongest3xPlayer(const string &name, int gender);
  void take_turn(Card &card);
};


#endif /* _CUSTOM_PLAYERS_H */
