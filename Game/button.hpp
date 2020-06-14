//
//  button.hpp
//  Game
//
//  Created by William Elliott on 6/8/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#ifndef button_hpp
#define button_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <string>
class button{
public:
    sf::RectangleShape shape;
    sf::Text text;
    bool selected;
    void draw(sf::RenderWindow* window);
    void setText(std::string Text);
    void setPosition(sf::Vector2f position);
    void setSize(sf::Vector2f size);
    bool checkClick(int X, int Y);
    bool checkClick(sf::Event event);
};
#endif /* button_hpp */
