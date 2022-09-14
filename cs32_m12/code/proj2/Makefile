objects = card.o custom_cards.o custom_players.o deck.o game.o main.o player.o
CXX = clang++
CXXFLAGS = -Wall -g

play: $(objects)
	$(CXX) $(CXXFLAGS) $(objects) -o play

card.o: card.h player.h
custom_cards.o: custom_cards.h card.h
custom_players.o: custom_players.h player.h player.o
deck.o: card.h deck.h
game.o: deck.h game.h player.h
main.o: card.h custom_players.h custom_cards.o game.h player.h player.o
player.o: card.h deck.h player.h


.PHONY: clean
clean:
	-rm play $(objects)

.PHONY: update_src
update_src:
	rsync -auv --exclude custom_* ~cs32/public_html/code/proj2/ .
	chmod 700 .
