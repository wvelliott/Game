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
class connectServer
{
private:
    sf::RenderWindow* window;
    button enterButton;
    sf::RectangleShape inputField;
    sf::Text prompt;
    sf::Text inputText;
    sf::Text example;
public:
    void setWindow(sf::RenderWindow *Window);
    void scaleWidgets();
    void setupScreen();
    void drawScreen();
    void start();
};

#endif /* connectServer_hpp */
