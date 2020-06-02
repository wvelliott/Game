//
//  resourceTile.hpp
//  Game
//
//  Created by William Elliott on 5/26/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#ifndef resourceTile_hpp
#define resourceTile_hpp

#include <stdio.h>
#include "resource.hpp"
#include "settlementArea.hpp"
class player;
class settlementArea;
class roadway;

class resourceTile
{
public:
    resource resourceType;
    std::vector<settlementArea*> settlements;
    int value;
    //sf::CircleShape* tile;
public:
    sf::CircleShape* tile;
    resourceTile();
    void setResourceType(resource type);
    resource getResourceType();
    void setValue(int value);
    int getValue();
    sf::CircleShape* getTile();
    void addSettlement(settlementArea* area);
    std::vector<settlementArea*> getSettlements();
};
#endif /* resourceTile_hpp */
