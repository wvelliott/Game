//
//  connectServer.hpp
//  Game
//
//  Created by William Elliott on 6/2/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#ifndef connectServer_hpp
#define connectServer_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "button.hpp"
#include "inputField.hpp"
class connectServer
{
private:
    sf::RenderWindow* window;
    button enterButton;
    inputField field;
    sf::RectangleShape inputField;
    sf::Text prompt;
    sf::Text inputText;
    sf::Text example;
    sf::Sprite background;
public:
    void setWindow(sf::RenderWindow *Window);
    void initBackground();
    void scaleWidgets();
    void setupScreen();
    void drawScreen();
    void start();
};

#endif /* connectServer_hpp */
