CC = g++
LFLAGS = -lglut -lGLU
CFLAGS = -Wall -g
#SOURCES = main.cpp game.cpp networking.cpp
SOURCES = *.cpp

game: $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $(LFLAGS) $^


.PHONY: clean
clean:
	rm game *.o
