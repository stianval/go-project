CC = g++
LFLAGS = -lglut -lGLU
#SOURCES = main.cpp game.cpp networking.cpp
SOURCES = *.cpp

game: $(SOURCES)
	$(CC) -Wall -g -o $@ $(LFLAGS) $^


.PHONY: clean
clean:
	rm game *.o
