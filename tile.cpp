#include "tile.h"

Tile::Tile(const Tile& t): window(t.window){
    active = t.active;
    area=t.area;
    IMG = t.IMG;
    texTile = t.texTile;
    texture = t.texture;
    OrderNumber = t.OrderNumber;
}

Tile::Tile(sf::RenderWindow& win, const sf::Rect<int> rect, const sf::Image Image, int n) 
: window(win), OrderNumber(n),  IMG(Image) 
{
    active=true;
    texture = std::make_shared<sf::Texture>();
    if(!texture->loadFromImage(IMG, rect)){
        std::cout << "ERROR LOADING IMAGE IN TILE" << std::endl;
    }
    texTile.setPosition(rect.left, rect.top);
    texTile.setSize(sf::Vector2f(rect.width, rect.height));
    texTile.setTexture(texture.get());
}

Tile& Tile::operator=(Tile& t){
    int x,y;
    active = t.active;
    area=t.area;
    IMG = t.IMG;
    OrderNumber = t.OrderNumber;
    return *this;
}


