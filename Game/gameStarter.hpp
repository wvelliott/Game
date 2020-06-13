//
//  gameStarter.hpp
//  Game
//
//  Created by William Elliott on 6/3/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#ifndef gameStarter_hpp
#define gameStarter_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
class gameStarter{
private:
    sf::RenderWindow* window;
public:
    void setWindow(sf::RenderWindow *Window);
    void start();
};

#endif /* gameStarter_hpp */
