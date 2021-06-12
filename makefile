#Compiler
CC = g++

#Options
CFLAGS = -c -Wall -g

#Include
CINCLUDES = -l ncurses

main: main.o computerplayer.o terminal.o display.o point.o move.o
	$(CC) main.o computerplayer.o terminal.o display.o point.o move.o -o t-t-t $(CINCLUDES)

main.o: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp

computerplayer.o: src/computerplayer.cpp
	$(CC) $(CFLAGS) src/computerplayer.cpp

terminal.o: src/display/terminal/terminal.cpp
	$(CC) $(CFLAGS) src/display/terminal/terminal.cpp

display.o: src/display/display.cpp
	$(CC) $(CFLAGS) src/display/display.cpp

point.o: src/display/terminal/point.cpp
	$(CC) $(CFLAGS) src/display/terminal/point.cpp

move.o: src/move.cpp
	$(CC) $(CFLAGS) src/move.cpp

.PHONY: clean

clean:
	rm -rf *.o t-t-t
