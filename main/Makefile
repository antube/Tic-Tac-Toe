#Compiler
CC = g++

#Options
CFLAGS = -c -Wall

#Include
CINCLUDE = -lncurses

main: main.o computerplayer.o humanplayer.o move.o
	$(CC) main.o computerplayer.o humanplayer.o move.o -o Tic-Tac-Toe 

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

computerplayer.o: computerplayer.cpp
	$(CC) $(CFLAGS) computerplayer.cpp

humanplayer.o: humanplayer.cpp
	$(CC) $(CFLAGS) humanplayer.cpp 

move.o: move.cpp
	$(CC) $(CFLAGS) move.cpp

clean:
	rm -rf *o Tic-Tac-Toe
