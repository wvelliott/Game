//
//  gameStarter.cpp
//  Game
//
//  Created by William Elliott on 6/3/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#include "gameStarter.hpp"
void gameStarter::setWindow(sf::RenderWindow *Window){
    this -> window = Window;
}
void gameStarter::start(){
    sf::CircleShape testButton;
    testButton.setRadius(20);
    testButton.setFillColor(sf::Color::Red);
    while(window -> isOpen()){
        sf::Event event;
        while(window -> pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window -> close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if(testButton.getFillColor() == sf::Color::Red){
                        testButton.setFillColor(sf::Color::Blue);
                    }
                    else{
                        testButton.setFillColor(sf::Color::Red);
                    }
                    break;
            }
        }
        window -> clear();
        window -> draw(testButton);
        window -> display();
    }
}
