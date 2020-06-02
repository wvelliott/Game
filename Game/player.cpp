//
//  player.cpp
//  Game
//
//  Created by William Elliott on 5/26/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#include "player.hpp"
player::player(int ID){
    this -> id = ID;
    this -> points = 0;
}
void player::setName(std::string Name){
    this -> name = Name;
}
std::string player::getName(){
    return(this -> name);
}
void player::setColor(sf::Color Color){
    this -> color = Color;
}
sf::Color player::getColor(){
    return(this -> color);
}
int player::getPoints(){
    return(this -> points);
}
void player::adjustPoints(int val){
    this -> points += val;
}
int player::resourceAmount(resource Resource){
    return(this -> resources[Resource]);
}
void player::adjustResource(resource Resource, int val){
    this -> resources[Resource] += val;
}
