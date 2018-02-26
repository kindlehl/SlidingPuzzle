#include "board.h"

Board::Board(sf::RenderWindow& win, sf::Image img, int w, int h) 
: width(w), height(h)
{
    imageWidth = win.getSize().x;
    imageHeight = win.getSize().y;
    for(int i = 0; i < w*h; i++){
        int x = (i%w)*(imageWidth/w);//generate x coordinate for tile at i
        int y = (i/w)*(imageHeight/h);//hopefully generates y coordinate
        tiles.push_back(Tile(win, sf::Rect<int>(x,y,imageWidth/w, imageHeight/h), img, i));

    }
    
    (--tiles.end())->disable(); //remove bottom right corner from puzzle
    blank = (--tiles.end())->OrderNumber; //mark bottom right as blank

//ITS SCRAMBLING TIME
    std::random_shuffle(tiles.begin(), tiles.end());
}

//gets indexes that the clicked tile could move to, given an empty space
std::set<int> Board::getMoves(){
    std::set<int> s;
    s.insert(clicked-1); //tile to left
    s.insert(clicked+1); //tile to right
    s.insert(clicked-width);//tile up
    s.insert(clicked+width);//tile down
    return s;
}

bool Board::checkMoves(){
    //if the clicked tile could move to blank tile return true
    return (possibleMoves.find(blank) != possibleMoves.end());
}

void Board::swap(Tile& t1, Tile& t2){
    int tempnum;
    sf::RectangleShape temptex;
    
    tempnum = t1.OrderNumber;
    t1.OrderNumber = t2.OrderNumber;
    t2.OrderNumber = tempnum;

    std::swap(t1.texture, t2.texture);
    t1.texTile.setTexture(&t1.texture);
    t2.texTile.setTexture(&t2.texture);
    t2.active = !t2.active;
    t1.active = !t1.active;
 //   temptex = t1.texTile;
 //   t1.texTile = t2.texTile;
 //   t2.texTile = temptex;
}

void Board::move(int x, int y){
   //calculate index at (x,y)
    clicked = (width*x/imageWidth)+width*(height*y/imageHeight);
   //generate possibleMoves
    possibleMoves = getMoves();
   //check if move is valid
    if(checkMoves()){
//        valid move, swap tiles
        std::cout << "CLICKED: " <<  clicked << std::endl;
        std::cout << "BLANK: " << blank << std::endl;
        Board::swap(tiles[blank], tiles[clicked]);
        blank=clicked;
    }
    else
        std::cout << "ERROR: Invalid Move!" << std::endl;

}

