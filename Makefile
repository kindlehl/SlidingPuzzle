ALL_DEP= main.cpp tile.cpp tile.h tile.o 
OBJECTS= main.o tile.o board.o
CPP=main.cpp tile.cpp
EXE= SlidingTiles 
SFML= -lsfml-window -lsfml-graphics -lsfml-system 
CC= g++ -std=c++11


final: $(OBJECTS)
	$(CC) $(OBJECTS) $(SFML) -o $(EXE)
debug: $(ALL_DEP)
	$(CC) -g $(OBJECTS) $(SFML) -o $(EXE)
main.o: tile.cpp tile.h main.cpp
	$(CC) -c main.cpp $(SFML) -o main.o
tile.o: tile.cpp tile.h
	$(CC) -c tile.cpp $(SFML) -o tile.o 
board.o: board.cpp board.cpp tile.o tile.cpp tile.h
	$(CC) -c board.cpp $(SFML) -o board.o
clean:
	rm -rf *.o

