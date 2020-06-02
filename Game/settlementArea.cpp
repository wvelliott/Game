//
//  settlementArea.cpp
//  Game
//
//  Created by William Elliott on 5/26/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#include "settlementArea.hpp"
settlementArea::settlementArea(){
    this -> tile = new sf::CircleShape();
}
sf::CircleShape* settlementArea::getTile(){
    return(tile);
}
void settlementArea::setOwner(player &Player){
    this -> owner = &Player;
}
player* settlementArea::getOwner(){
    return(this -> owner);
}
void settlementArea::setType(settlement Type){
    this -> stype = Type;
}
settlement settlementArea::getType(){
    return(this -> stype);
}
void settlementArea::setDock(resource dockType, int tradeAmount){
    this -> dock.first = dockType;
    this -> dock.second = tradeAmount;
}
void settlementArea::addRoad(roadway &road){
    this -> roads.push_back(&road);
}
std::vector<roadway*> settlementArea::getRoads(){
    return(this -> roads);
}
void settlementArea::addResourceTile(resourceTile &tile){
    this -> resourceTiles.push_back(&tile);
}
std::vector<resourceTile*> settlementArea::getResourceTiles(){
    return(this -> resourceTiles);
}
