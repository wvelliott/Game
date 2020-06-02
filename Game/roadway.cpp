//
//  roadway.cpp
//  Game
//
//  Created by William Elliott on 5/26/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#include "roadway.hpp"
roadway::roadway(){
    this -> tile = new sf::RectangleShape();
}
sf::RectangleShape* roadway::getTile(){
    return(tile);
}
void roadway::setOwner(player &Player){
    this -> owner = &Player;
}
player* roadway::getOwner(){
    return(this -> owner);
}
void roadway::addRoad(roadway &road){
    this -> roads.push_back(&road);
}
std::vector<roadway*> roadway::getRoads(){
    return(this -> roads);
}
