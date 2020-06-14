//
//  button.cpp
//  Game
//
//  Created by William Elliott on 6/8/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#include "button.hpp"
void button::draw(sf::RenderWindow* window){
    window -> draw(this -> shape);
    window -> draw(this -> text);
}
void button::setText(std::string Text){
    this -> text.setString(Text);
}
void button::setPosition(sf::Vector2f position){
    sf::Vector2f shapeSize = this -> shape.getSize();
    sf::Vector2f textSize = sf::Vector2f(this -> text.getLocalBounds().width, this -> text.getLocalBounds().height);
    //this -> shape.setOrigin(shapeSize.x/2, shapeSize.x/2);
    this -> shape.setPosition(position.x, position.y);
    //this -> text.setOrigin(textSize.x/2, textSize.x/2);
    this -> text.setPosition(position.x, position.y);
}
void button::setSize(sf::Vector2f size){
    this -> shape.setSize(size);
}
bool button::checkClick(int X, int Y){
    return(this -> shape.getGlobalBounds().contains(X, Y));
}
bool button::checkClick(sf::Event event){
    return(this -> shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y));
}
