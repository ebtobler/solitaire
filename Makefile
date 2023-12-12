#

CC = g++

CFLAGS = -g -Wall 

sol: solitaire.o Card.o 
	$(CC) solitaire.o Card.o  -o sol

solitaire.o: solitaire.cpp
	$(CC) $(CFLAGS) -c solitaire.cpp

Card.o: Card.cpp
	$(CC) $(CFLAGS) -c Card.cpp

clean:
	-rm -f *.o sol

