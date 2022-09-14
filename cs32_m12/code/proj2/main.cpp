#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include "card.h"
#include "game.h"
#include "custom_cards.h"
#include "custom_players.h"

/* Completely convert a string to an integer. The return value is true
   if input was completely converted.
*/
bool string_to_int(const string input, int &output) {
  stringstream tmp(input);
  tmp >> output;
  return !tmp.fail() && tmp.peek() == -1;
}

/* Return a string of all content up until a colon */
string read_until_colon(istream &ins) {
  string retval;
  char c;
  while (isspace(ins.peek())) ins.get();  // Ignore leading whitespace
  while ((c = ins.get()) != ':')
    retval += c;
  return retval;
}


/* Read in the game data */
void read_in_game_data(istream &ins, Game &game, Deck &deck) {
  string class_name, name;
  int num1;
  while (ins.good() && ins >> class_name) {
    name = read_until_colon(ins);
    ins >> num1;

    // Create the proper Card or Player instances
    if (class_name == "AttackNextPlayer")
      game.add_player(new AttackNextPlayer(name, num1));
    else if (class_name == "Card")
      deck.add_card(new Card(name, num1));

    // Uncomment the else conditions when the related Player classes are defined
    /*
    else if (class_name == "AttackWeakestPlayer")
      game.add_player(new AttackWeakestPlayer(name, num1));
    else if (class_name == "HumanPlayer")
      game.add_player(new HumanPlayer(name, num1));
    else if (class_name == "AttackStrongest3xPlayer")
      game.add_player(new AttackStrongest3xPlayer(name, num1));
    */

    // Uncomment the else conditions when the related Card classes are defined
    /*
    else if (class_name == "AccumulatorCard") {
      int num2;
      ins >> num2;
      deck.add_card(new AccumulatorCard(name, num1, num2));
    }
    else if (class_name == "KillMultiplierCard")
      deck.add_card(new KillMultiplierCard(name, num1));
    else if (class_name == "ReflectorCard") {
      int num2;
      ins >> num2;
      deck.add_card(new ReflectorCard(name, num1, num2));
    }
    else if (class_name == "SnowballCard")
      deck.add_card(new SnowballCard(name, num1));
    else if (class_name == "TransformationCard")
      deck.add_card(new TransformationCard(name, num1));
    */

    else {
      cout << "Invalid Card or Player class `" << class_name << "`. Goodbye!\n";
      exit(1);
    }
  }
  cout << game;
}


/* Setup and run multiple instances of the game */
int main(int argc, char *argv[]) {
  // Verify arguments
  int num_games;
  int random_seed;
  if (argc < 3 || argc > 5) {
    cout << "Usage: play INPUT_FILE NUM_GAMES [SEED]\n";
    return 1;
  }
  ifstream game_input(argv[1]);
  if (game_input.fail()) {
    cout << "`" << argv[1] << "` could not be opened\n";
  }
  if (!string_to_int(argv[2], num_games)) {
    cout << "Num games value `" << argv[2] << "` is not a number\n";
    return 1;
  }
  if (num_games < 1) {
    cout << "Cannot play fewer than 1 games.\n";
    return 1;
  }
  if (argc == 4) {
    // Use the second argument as an srand seed
    if (!string_to_int(argv[3], random_seed)) {
      cout << "Seed value `" << argv[3] << "` is not a number\n";
      return 1;
    }
    srand(random_seed);
  }
  else {
    // Seed with the time for varied results
    srand(time(NULL));
  }

  // Initialize the game from standard input
  Deck deck;
  Game game;
  read_in_game_data(game_input, game, deck);
  game_input.close();
  game.prepare(deck);

  // Play the first game
  game.play();

  // Play the remaining games
  while (--num_games > 0) {
    game.reset();
    game.play();
  }

  return 0;
}
