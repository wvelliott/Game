//
//  settlementArea.hpp
//  Game
//
//  Created by William Elliott on 5/26/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#ifndef settlementArea_hpp
#define settlementArea_hpp

#include <stdio.h>
#include <vector>
#include <utility>
#include <SFML/Graphics.hpp>
#include "settlement.hpp"
#include "resource.hpp"
class player;
class roadway;
class resourceTile;

class settlementArea
{
private:
    player *owner;
    settlement stype;
    std::vector<roadway*> roads;
    std::vector<resourceTile*> resourceTiles;
    std::pair<resource,int> dock;
    sf::CircleShape* tile;
public:
    settlementArea();
    sf::CircleShape* getTile();
    void setOwner(player &Player);
    player* getOwner();
    void setType(settlement Type);
    settlement getType();
    void setDock(resource dockType, int tradeAmount);
    void addRoad(roadway &road);
    std::vector<roadway*> getRoads();
    void addResourceTile(resourceTile &tile);
    std::vector<resourceTile*> getResourceTiles();
};
#endif /* settlementArea_hpp */
