#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
//tile class
//  has a number to hold the order that it goes in
//  texture
//  constructed given width/height and the texture
//  no default construction

class Tile{
    public:
        friend class Board;
        int getNum(){ return OrderNumber; }
        Tile(sf::RenderWindow& win, sf::Rect<int> rect, sf::Image Image, int n);
        Tile(const Tile& t) ;
        Tile& operator=(Tile& t);
        sf::RectangleShape get(){
            return texTile;
        }
        void enable(){ active = true; }
        void disable(){ active = false; }
        bool on(){ return active; }
        void draw(){
            window.draw(texTile);
        }
    private:
        bool active = true;
        sf::RenderWindow& window;
        sf::Vector2f area;
        sf::Image IMG;
        sf::RectangleShape texTile;
        std::shared_ptr<sf::Texture> texture;
        int OrderNumber;
};

#endif
