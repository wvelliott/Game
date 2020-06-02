//
//  main.cpp
//  Game
//
//  Created by William Elliott on 5/26/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "boardManager.hpp"
int main() {
    int screenW = sf::VideoMode::getDesktopMode().width;
    int screenH = sf::VideoMode::getDesktopMode().height;
    
    sf::RenderWindow window( sf::VideoMode(screenW , screenH), "Catan");
    
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        window.setFramerateLimit(30);
        boardManager BM;
        BM.setWindow(&window);
        BM.setScreenSize(screenW, screenH);
        BM.initBoard();
        BM.drawBoard();
    }
    return EXIT_SUCCESS;
}
