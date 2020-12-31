#Compiler
CC = g++

#Options
CFLAGS = -c -Wall -g

#Include
CINCLUDES = -l ncurses

main: main.o computerplayer.o humanplayer.o terminal.o move.o
	$(CC) main.o computerplayer.o humanplayer.o terminal.o move.o -o t-t-t $(CINCLUDES)

main.o: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp

computerplayer.o: src/computerplayer.cpp
	$(CC) $(CFLAGS) src/computerplayer.cpp

humanplayer.o: src/humanplayer.cpp
	$(CC) $(CFLAGS) src/humanplayer.cpp

terminal.o: src/display/terminal.cpp
	$(CC) $(CFLAGS) src/display/terminal.cpp

move.o: src/move.cpp
	$(CC) $(CFLAGS) src/move.cpp

.PHONY: clean

clean:
	rm -rf *.o t-t-t
