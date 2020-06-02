//
//  resourceTile.cpp
//  Game
//
//  Created by William Elliott on 5/26/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#include "resourceTile.hpp"
resourceTile::resourceTile(){
    this -> tile = new sf::CircleShape();
    printf("tile %p\n", tile);
}
void resourceTile::setResourceType(resource type){
    this -> resourceType = type;
}
resource resourceTile::getResourceType(){
    return(this -> resourceType);
}
void resourceTile::setValue(int val){
    this -> value = val;
}
int resourceTile::getValue(){
    return(this -> value);
}
sf::CircleShape* resourceTile::getTile(){
    return(this -> tile);
}
void resourceTile::addSettlement(settlementArea* area){
    this -> settlements.push_back(area);
}
std::vector<settlementArea*> resourceTile::getSettlements(){
    return(this -> settlements);
}
