#

CC = g++

CFLAGS = -g -Wall 

sol: solitaire.o card.o 
	$(CC) solitaire.o card.o  -o sol

solitaire.o: solitaire.cpp
	$(CC) $(CFLAGS) -c solitaire.cpp

card.o: card.cpp
	$(CC) $(CFLAGS) -c card.cpp

clean:
	-rm -f *.o sol

