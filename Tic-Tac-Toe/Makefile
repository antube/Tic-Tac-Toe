#Compiler
CC = g++

#Options
CFLAGS = -c -Wall

main: main.o computer_play.o winner.o
	$(CC) main.o computer_play.o winner.o -o Tic-Tac-Toe

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

computer_play.o: computer_play.cpp
	$(CC) $(CFLAGS) computer_play.cpp

winner.o: winner.cpp
	$(CC) $(CFLAGS) winner.cpp

clean:
	rm -rf *o Tic-Tac-Toe