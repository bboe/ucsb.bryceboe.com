#include <cstdlib>
#include <iostream>
#include "card.h"
#include "player.h"


Card::Card(const string &name, int hp): used(false), hp(hp), name(name) {
  if (hp == 0) {
    cout << "hp cannot be 0. Goodbye!\n";
    exit(1);
  }
}


Card* Card::clone() const {
  return new Card(name, hp);
}


void Card::discard() {
  used = false;
}


int Card::get_hp() const {
  return hp;
}


const string& Card::get_name() const {
  return name;
}


void Card::perform_action(Player &from, Player &to, int hp) {
  if (get_hp() < 0)
    to.decrease_hp(hp);
  else
    to.increase_hp(hp);
}


void Card::play(Player &from, Player &to, int hp) {
  // Verification
  if (used) {
    cout << "Cannot play an already used card. Goodbye!\n";
    exit(1);
  }
  else if (hp < 1 || hp > abs(get_hp())) {
    cout << "Invalid hp value: " << hp << ". Goodbye!\n";
    exit(1);
  }
  else if (!to.is_alive()) {
    cout << "Cannot play a card on a dead player. Goodbye!\n";
    exit(1);
  }
  // Actually perform the card's task
  used = true;
  int card_hp = get_hp();  // The hp can change as a result of playing the card
  perform_action(from, to, hp);
  // Reporting
  cout << "  + " << from.get_name() << (card_hp < 0 ? " attacks " : " heals ");
  if (&from != &to)
    cout << to.get_name();
  else
    cout << from.get_gender_string();
  cout << " with " << name << " for " << hp << " hp.";
  if (!to.is_alive())
    cout << " " << to.get_name() << " has died.";
  cout << endl;
}


void Card::reset() {
  used = false;
}


ostream& operator <<(ostream &outs, const Card &card) {
  return outs << "Card(" << card.name << ", " << card.get_hp() << "hp)";
}
