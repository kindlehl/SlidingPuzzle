#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include <vector>
#include <set>


class Board{
    public:
        //9 tiles in a 2d array
        //constructor(size of tiles)
        //move
        Board(sf::RenderWindow& win, sf::Image img, int w = 3, int h = 3);
        void draw(){
            for(auto t : tiles){
                if(t.on())
                    t.draw();
            }
        }
        void move(int x, int y);
        void swap(Tile& t1, Tile& t2);

    private:
        int height, width;  //number of tiles
        int imageWidth, imageHeight; //size of image in pixels
        std::vector<Tile> tiles;
        int blank, clicked; //holds index of blank tile, and user clicked tile
        std::set<int> possibleMoves;
        std::set<int> getMoves();
        bool checkMoves();
};


#endif
