//
//  player.hpp
//  Game
//
//  Created by William Elliott on 5/26/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <string>
#include <SFML/Graphics.hpp>
#include <map>
#include "resource.hpp"

class roadway;
class settlementArea;
class resourceTile;

class player{
private:
    std::string name;
    int id;
    sf::Color color;
    int points;
    std::map<resource,int> resources;
public:
    player(int ID);
    void setName(std::string Name);
    std::string getName();
    void setColor(sf::Color Color);
    sf::Color getColor();
    int getPoints();
    void adjustPoints(int val);
    int resourceAmount(resource Resource);
    void adjustResource(resource Resource, int val);
    
};
#endif /* player_hpp */
