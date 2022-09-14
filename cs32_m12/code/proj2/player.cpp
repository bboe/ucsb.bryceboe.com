#include <cstdlib>
#include <iostream>
#include "card.h"
#include "player.h"
#include "game.h"
using namespace std;


Player::Player(const string &name, int gender):
  game(NULL), deck(), discard(), gender(gender), hp(STARTING_HP), name(name) {
  if (gender < 0 || gender > 3) {
    cout << "Invalid gender. Goodbye\n";
    exit(1);
  }
}


void Player::decrease_hp(int amount) {
  if (amount <= 0) {
    cout << "Decrease amount must be positive. Goodbye!\n";
    exit(1);
  }
  hp -= amount;
  if (hp <= 0)
    game->add_dead(this);
}


const string Player::get_gender_string() const {
  if (gender == 0)
    return "itself";
  else if (gender == 1)
    return "herself";
  else
    return "himself";
}


int Player::get_hp() const {
  return hp;
}


const string& Player::get_name() const {
  return name;
}


void Player::increase_hp(int amount) {
  if (amount <= 0) {
    cout << "Increase amount must be positive. Goodbye!\n";
    exit(1);
  }
  hp += amount;
  // hp cannot exceed the starting value
  if (hp > STARTING_HP)
    hp = STARTING_HP;
}


bool Player::is_alive() const {
  return hp > 0;
}


void Player::join_game(Deck &deck, Game *game) {
  this->discard = deck;
  this->game = game;
}


void Player::reset() {
  hp = STARTING_HP;
  /* Move all remaining cards to the discard */
  while (!deck.is_empty()) {
    discard.add_card(deck.get_card());
  }
  discard.reset();
}


void Player::turn_wrapper() {
  /* Shuffle the deck when empty */
  if (deck.is_empty()) {
    while (!discard.is_empty())
      deck.add_card(discard.get_card());
    deck.shuffle();
  }
  /* Fetch the card and play the turn */
  Card *card = deck.get_card();
  take_turn(*card);
  /* Discard the card */
  card->discard();
  discard.add_card(card);
}


ostream& operator <<(ostream &outs, const Player &rhs) {
  cout << rhs.name << " (";
  if (rhs.hp > 0)
    cout << rhs.hp << " hp";
  else
    cout << "dead";
  return cout << ")";
}


/*
 * AttackNextPlayer Implementation
 *
 * This player will always attack the next player in turn-order and heal
 * themself.
 */
AttackNextPlayer::AttackNextPlayer(const string &name, int gender):
  Player(name, gender) {
}


void AttackNextPlayer::take_turn(Card &card) {
  if (card.get_hp() > 0) {
    // Heal ourself with only as much hp as required
    int hp = min(STARTING_HP - get_hp(), card.get_hp());
    if (hp > 0)
      card.play(*this, *this, hp);
  }
  else {  // Attack the next player
    int pos = game->get_current_player_position();
    int size = game->get_num_players();
    Player *other;
    do {
      other = &game->get_player(++pos % size);
    }
    while (!other->is_alive());
    // Attack with only as much as hp as required
    int hp = min(other->get_hp(), -card.get_hp());
    card.play(*this, *other, hp);
  }
}


int prompt(const string &msg, int min, int max) {
  bool valid = false;
  bool is_tty = isatty(STDIN_FILENO); // UGLY non-C++ HACK
  int retval;
  while (!valid) {
    if (is_tty)
      cout << msg;
    cin >> retval;
    if (cin.eof()) {
      cout << "Input stream closed during prompt. Goodbye!\n";
      exit(1);
    }
    else if (cin.fail() || cin.get() != '\n') {
      cin.clear();
      while (cin.get() != '\n');
    }
    else if (retval >= min && retval <= max)
      valid = true;

    if (!valid && is_tty)
      cout << "Invalid number. Try again.\n";

  }
  return retval;
}
