#include <cstdlib>
#include <iostream>
#include "game.h"


Game::Game(): current_player(0), dead(), players(), turn_number(0) {}


Game::~Game() {
  /* Free all the players */
  for (int i = 0; i < players.size(); ++i) {
    delete players[i];
  }
}


void Game::add_dead(Player *player) {
  dead.push_back(player);
}


void Game::add_player(Player *player) {
  players.push_back(player);
}


int Game::get_current_player_position() const {
  return current_player;
}


Player& Game::get_player(int pos) const {
  return *players[pos];
}


int Game::get_num_alive_players() const {
  return players.size() - dead.size();
}


int Game::get_num_players() const {
  return players.size();
}


const Player& Game::get_winner() const {
  if (get_num_alive_players() != 1) {
    cout << "The game has not yet been played. Goodbye!\n";
    exit(1);
  }
  Player *retval;
  for (int i = 0; i < players.size(); ++i) {
    if (players[i]->is_alive())
      retval = players[i];
  }
  return *retval;
}


void Game::play() {
  if (dead.size() != 0) { // Game state verification
    cout << "The game is not in the initial state. Goodbye!\n";
    exit(1);
  }
  bool game_over = false;
  while (!game_over) {
    turn_number += 1;
    cout << "Round number " << turn_number;
    cout << " (" << get_num_alive_players() << " alive players)\n";
    for (current_player = 0; current_player < players.size();
         ++current_player) {
      if (players[current_player]->is_alive()) {
        players[current_player]->turn_wrapper();
        if (get_num_alive_players() == 1) {
          game_over = true;
          break;
        }
      }
    }
    cout << "End of round status\n";
    cout << *this << "---\n";
  }
  cout << "*** The winner is: " << get_winner() << " ***\n\n";
}


void Game::prepare(Deck &deck) {
  for (int i = 0; i < players.size(); ++i)
    players[i]->join_game(deck, this);
}


void Game::reset() {
  if (get_num_alive_players() != 1) {
    cout << "Reset can only be used after a game is played. Goodbye!\n";
    exit(1);
  }
  turn_number = 0;
  // Move the winner to the front
  for (int i = 0; i < players.size(); ++i) {
    if (players[i]->is_alive()) {
      players[0] = players[i];
      players[0]->reset();
      break;
    }
  }
  // Use the dead vector to determine the new play order
  for (int i = 1; i < players.size(); ++i) {
    players[i] = dead.back();
    players[i]->reset();
    dead.pop_back();
  }
}


ostream& operator <<(ostream &outs, const Game &game) {
  for (int i = 0; i < game.players.size(); ++i) {
    cout << "  * " << *game.players[i] << endl;
  }
  return cout;
}
