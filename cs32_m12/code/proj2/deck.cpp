#include <cstdlib>
#include <iostream>
#include "deck.h"
#include "card.h"


Deck::Deck(): cards() {}


Deck::Deck(const Deck &other): cards(other.cards) {
  /* Deep copy all of the cards */
  for (int i = 0; i < cards.size(); ++i) {
    Card *tmp = cards[i]->clone();
    cards[i] = tmp;
  }
}


Deck::~Deck() {
  for (int i = 0; i < cards.size(); ++i)
    delete cards[i];
}


const Deck& Deck::operator =(const Deck &other) {
  if (this == &other) return *this;
  cards = other.cards;
  /* Deep copy all of the cards */
  for (int i = 0; i < cards.size(); ++i) {
    Card *tmp = cards[i]->clone();
    cards[i] = tmp;
  }
  return *this;
}


void Deck::add_card(Card *card) {
  cards.push_back(card);
}


Card* Deck::get_card() {
  Card *retval = cards.front();
  cards.pop_front();
  return retval;
}


bool Deck::is_empty() {
  return cards.empty();
}


void Deck::reset() {
  for (int i = 0; i < cards.size(); ++i)
    cards[i]->reset();
}


void Deck::shuffle() {
  Card *tmp;
  for (int i = 0; i < cards.size() -1 ; ++i) {
    // Select a random position between i and size - 1 to swap into position
    int idx = i + rand() % (cards.size() - i);
    tmp = cards[i];
    cards[i] = cards[idx];
    cards[idx] = tmp;
  }
}
