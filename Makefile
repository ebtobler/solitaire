#

CC = g++

CFLAGS = -g -Wall 

sol: solitaire.o Card.o Deck.o
	$(CC) solitaire.o Card.o Deck.o  -o sol

solitaire.o: solitaire.cpp
	$(CC) $(CFLAGS) -c solitaire.cpp

Deck.o: Deck.cpp
	$(CC) $(CFLAGS) -c Deck.cpp

Card.o: Card.cpp
	$(CC) $(CFLAGS) -c Card.cpp

clean:
	-rm -f *.o sol

