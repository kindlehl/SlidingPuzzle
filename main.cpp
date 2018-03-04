#include <SFML/Graphics.hpp>
#include <iostream>
#include "tile.h"
#include "board.h"
#include <math.h>

using namespace std;

void processEvents(sf::RenderWindow& window, Board& board);


int main(int argc, char** argv){
    int height, width;
    height = width = 600;
    sf::Image Img; 
   if(argc != 2){
        cout << "Invalid Arguments. Please enter the name of a file or image on the internet" << endl;
        return -1;
    }
    if(!Img.loadFromFile(argv[1])){
        cout << "ERROR OPENING FILE: " << argv[1] << " ABORTING!" << endl;
        return -1;
    }
    width = Img.getSize().x;
    height = Img.getSize().y;

    sf::RenderWindow window(sf::VideoMode(width, height), "Puzzle Project");
    sf::RectangleShape background(sf::Vector2f(width, height));
    background.setFillColor(sf::Color(100, 15, 60));
    window.setFramerateLimit(60);
    Board board(window, Img, 3, 3);
    while(window.isOpen()){
        window.clear();
        processEvents(window, board);
        window.draw(background);
        board.draw();
        window.display();
    }

    return 0;

}


void processEvents(sf::RenderWindow& window, Board& board){
     sf::Event event;
     while(window.pollEvent(event)){

         if(event.type==sf::Event::Closed)
                window.close();
         if(event.type==sf::Event::MouseButtonPressed){
            board.move(event.mouseButton.x, event.mouseButton.y);
         }
     }

}

