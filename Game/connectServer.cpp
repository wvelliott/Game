//
//  connectServer.cpp
//  Game
//
//  Created by William Elliott on 6/2/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#include "connectServer.hpp"
void connectServer::setWindow(sf::RenderWindow *Window){
    this -> window = Window;
}
void connectServer::scaleWidgets(){
    float windowX = this -> window -> getSize().x;
    float windowY = this -> window -> getSize().y;
    this -> enterButton.setSize(sf::Vector2f(windowX, windowY));
    
}
void connectServer::setupScreen(){
//    sf::Font font;
//    font.loadFromFile("/Users/WilliamElliott/Documents/Graph/Game/External\ Libraries/res/font/Mermaid1001.ttf");
    this -> scaleWidgets();
    this -> enterButton.shape.setFillColor(sf::Color::Red);
//    this -> enterButton.text.setFont(font);
//    this -> enterButton.text.setString("Press");
//    this -> enterButton.text.setFillColor(sf::Color::Black);
}
void connectServer::drawScreen(){
//    sf::CircleShape testButton;
//    testButton.setRadius(20);
//    testButton.setFillColor(sf::Color::Red);
    this -> window -> clear();
    enterButton.draw(window);
    this -> window -> display();
}
void connectServer::start(){
    this -> setupScreen();
    bool finished = false;
    while(!finished){
        sf::Event event;
        while(window -> pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window -> close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if(enterButton.shape.getFillColor() == sf::Color::Red){
                        enterButton.shape.setFillColor(sf::Color::Blue);
                    }
                    else{
                        finished = true;
                    }
                    break;
            }
        this -> drawScreen();
        }
    }
}
