//
//  roadway.hpp
//  Game
//
//  Created by William Elliott on 5/26/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#ifndef roadway_hpp
#define roadway_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
class player;
class settlementArea;
class resourceTile;

class roadway
{
private:
    player* owner;
    std::vector<roadway*> roads;
    sf::RectangleShape* tile;
public:
    roadway();
    sf::RectangleShape* getTile();
    void setOwner(player &Player);
    player* getOwner();
    void addRoad(roadway &road);
    std::vector<roadway*> getRoads();
};
#endif /* roadway_hpp */
