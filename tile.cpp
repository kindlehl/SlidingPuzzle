#include "tile.h"
#include "include/utilities.h"

Tile::Tile(sf::RenderWindow& win, const sf::Rect<int> rect, const sf::Image Image, int n) 
: window(win), OrderNumber(n),  IMG(Image) 
{
    active=true;
    if(!texture.loadFromImage(IMG, rect)){
        std::cout << "ERROR LOADING IMAGE IN TILE" << std::endl;
    }
    texTile.setPosition(rect.left, rect.top);
    texTile.setSize(sf::Vector2f(rect.width, rect.height));
    texTile.setTexture(&texture);
}

Tile& Tile::operator=(const Tile& t){
    active = t.active;
    texTile = t.texTile;
    texture = t.texture;
    OrderNumber = t.OrderNumber;

    return *this;
}


