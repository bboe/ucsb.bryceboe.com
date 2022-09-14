#ifndef _CUSTOM_CARDS_H
#define _CUSTOM_CARDS_H

#include "card.h"
using namespace std;


/* The AccumulatorCard is a Card that grows in strength every time it is
   discarded. The increase parameter indicates how much to add, or subtract to
   the previous hp value of the card.

   Card values can never be zero. If the result of the accumulation would make
   the card's hp value zero, then the value should be set to -1.
 */
class AccumulatorCard: public Card {
 public:
  AccumulatorCard(const string &name, int hp, int increase);
};


/* The KillMultipler card grows in strength whenver it is used to kill a
   player. That is if a player dies from the user of this card, the card's
   strengh should grow as a function of the original hp and the number of kills:

   effective_hp = (num_kills + 1) * original_hp
*/
class KillMultiplierCard: public Card {
 public:
  KillMultiplierCard(const string &name, int hp);
};


/* The ReflectorCard will heal the attacker with reflection_amount hp when used
   as an attack card. If the card is a healing card, the reflection property
   should not take place.
 */
class ReflectorCard: public Card {
 public:
  ReflectorCard(const string &name, int hp, int reflection_amount);
};


/* The SnowballCard is a Card with "rollover" capabilities. That is, each time
   the card is __discarded__, a snowball value should be computed. The snowball
   value should be whatever extra amount of the card's hp wasn't during the
   turn.

   For instance, if a 10hp SnowballCard is used to attack for 5hp, then its
   snowball value for that turn is 5hp and on its next use the card is
   effectively 15hp. If the card is then used for 10hp, it will again have a
   snowball value of 5hp.

   Keep in mind that hp values can be negative as well.
 */
class SnowballCard: public Card {
 public:
  SnowballCard(const string &name, int hp);
};


/* The TransformationCard simply switches state between attacking and healing
   on each __use__ (use is different than discarding).
 */
class TransformationCard: public Card {
 public:
  TransformationCard(const string &name, int hp);
};


#endif /* _CUSTOM_CARDS_H */
