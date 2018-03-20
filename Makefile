ALL_DEP= source/main.cpp source/tile.cpp include/tile.h tile.o 
OBJECTS= main.o tile.o board.o
CPP=source/main.cpp source/tile.cpp
EXE= SlidingTiles 
SFML= -lsfml-window -lsfml-graphics -lsfml-system 
CC= g++ -std=c++11


final: $(OBJECTS)
	$(CC) $(OBJECTS) $(SFML) -o $(EXE)
debug: $(ALL_DEP)
	$(CC) -g $(OBJECTS) $(SFML) -o $(EXE)
main.o: source/tile.cpp include/tile.h source/main.cpp
	$(CC) -c source/main.cpp $(SFML) -o main.o
tile.o: source/tile.cpp include/tile.h
	$(CC) -c source/tile.cpp $(SFML) -o tile.o 
board.o: source/board.cpp tile.o source/tile.cpp include/tile.h
	$(CC) -c source/board.cpp $(SFML) -o board.o
clean:
	rm -rf *.o

