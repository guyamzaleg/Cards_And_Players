Decks_game: main.o Card.o Character.o Deck.o Dragon.o Enemy.o Fighter.o Ghost.o Ranger.o Set.o Sorcerer.o Troll.o
	g++ main.o Card.o Character.o Deck.o Dragon.o Enemy.o Fighter.o Ghost.o Ranger.o Set.o Sorcerer.o Troll.o -o Decks_game
	
Card.o: Card.cpp Card.h
	g++ -c Card.cpp
	
Character.o: Character.cpp Character.h Deck.h Card.h Set.h Memory_Error.h
	g++ -c Character.cpp
	
Deck.o: Deck.cpp Deck.h Card.h Memory_Error.h
	g++ -c Deck.cpp
	
Dragon.o: Dragon.cpp Dragon.h Enemy.h Fighter.h Character.h Deck.h Card.h Set.h Sorcerer.h Ranger.h
	g++ -c Dragon.cpp

Enemy.o: Enemy.cpp Enemy.h Fighter.h Character.h Deck.h Card.h Set.h Sorcerer.h Ranger.h
	g++ -c Enemy.cpp
	
Fighter.o: Fighter.cpp Fighter.h Character.h Deck.h Card.h Set.h Enemy.h Sorcerer.h Ranger.h
	g++ -c Fighter.cpp 
		
Ghost.o: Ghost.cpp Ghost.h Enemy.h Fighter.h Character.h Deck.h Card.h Set.h Sorcerer.h Ranger.h
	g++ -c Ghost.cpp
	
main.o: main.cpp Memory_Error.h Card.h Deck.h Set.h Character.h Fighter.h Enemy.h Sorcerer.h Ranger.h Troll.h Ghost.h Dragon.h 
	g++ -c main.cpp
	
Ranger.o: Ranger.cpp Ranger.h Character.h Deck.h Card.h Set.h Enemy.h Fighter.h Sorcerer.h
	g++ -c Ranger.cpp
	
Set.o: Set.cpp Set.h Card.h
	g++ -c Set.cpp
	
Sorcerer.o: Sorcerer.cpp Sorcerer.h Character.h Deck.h Card.h Set.h Enemy.h Fighter.h Ranger.h
	g++ -c Sorcerer.cpp
	
Troll.o: Troll.cpp Troll.h Enemy.h Fighter.h Character.h Deck.h Card.h Set.h Sorcerer.h Ranger.h
	g++ -c Troll.cpp
	
clean: 
	rm -f *.o Decks_game
