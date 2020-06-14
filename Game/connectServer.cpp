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
    this -> field.setSize(sf::Vector2f(windowX/20, windowY/20));
    this -> field.setPosition(sf::Vector2f(3* windowX/20, 3* windowY/20));
}
void connectServer::initBackground(){
    sf::Texture* texture = new sf::Texture();
    if (!texture -> loadFromFile("res/img/background.jpg"))
    {
        printf("error loading texture\n");
        std::string str = "pwd";
        const char *command = str.c_str();
        system(command);
    }
    texture -> setRepeated(true);
    this -> background.setTexture(*texture);
    sf::Vector2u windowSize = this -> window -> getSize();
    this -> background.setTextureRect({0,0,(int)windowSize.x,(int)windowSize.y});
    
}
void connectServer::setupScreen(){
    initBackground();
    sf::Font* font = new sf::Font();
    font -> loadFromFile("res/font/Mermaid1001.ttf");
    this -> scaleWidgets();
    this -> field.shape.setFillColor(sf::Color::Red);
    this -> field.text.setFont(*font);
    this -> field.text.setString("");
    this -> field.text.setFillColor(sf::Color::Black);
}
void connectServer::drawScreen(){
    this -> window -> clear();
    this -> window -> draw(background);
    this -> enterButton.draw(window);
    this -> field.draw(window);
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
                    finished = true;
                    window -> close();
                    break;
                case sf::Event::MouseButtonPressed:
//                    if(enterButton.shape.getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y)){
                    if(enterButton.checkClick(event)){
                        if(enterButton.shape.getFillColor() == sf::Color::Red){
                            enterButton.shape.setFillColor(sf::Color::Blue);
                        }
                        else{
                            finished = true;
                        }
                    }
                    break;
                case sf::Event::KeyPressed:
                    this -> field.updateText(event);
            }
        this -> drawScreen();
        }
    }
}
