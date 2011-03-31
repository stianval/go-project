CC = g++
LFLAGS = -lglut
#SOURCES = main.cpp game.cpp networking.cpp
SOURCES = *.cpp

game: $(SOURCES)
	$(CC) -o $@ $(LFLAGS) $^


.PHONY: clean
clean:
	rm game *.o
