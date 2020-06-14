//
//  boardManager.cpp
//  Game
//
//  Created by William Elliott on 5/26/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#include "boardManager.hpp"
#include <string>
void boardManager::addPlayer(player* P){
    this -> players.push_back(P);
}
std::vector<player*> boardManager::getPlayers(){
    return(this -> players);
}
void boardManager::addSetlementArea(settlementArea* area){
    this -> settlementAreas.push_back(area);
}
std::vector<settlementArea*> boardManager::getSettlementAreas(){
    return(this -> settlementAreas);
}
void boardManager::addRoadway(roadway* road){
    this -> roadways.push_back(road);
}
std::vector<roadway*> boardManager::getRoadways(){
    return(this -> roadways);
}
void boardManager::addResourceTile(resourceTile* rt){
    this -> resourceTiles.push_back(rt);
}
std::vector<resourceTile*> boardManager::getResourceTiles(){
    return(this -> resourceTiles);
}
void boardManager::setWindow(sf::RenderWindow *Window){
    this -> window = Window;
}
void boardManager::setScreenSize(int W, int H){
    this -> screenW = W;
    this -> screenH = H;
}
void boardManager::initResourceTiles(sf::Vector2u windowSize){
    sf::Texture* texture = new sf::Texture();
//    if (!texture -> loadFromFile("/Users/WilliamElliott/Documents/Graph/Game/External\ Libraries/res/img/sheep.jpg"))
    
//    char *memblock = new char [18742];
    
    if (!texture -> loadFromFile("res/img/sheep.jpg"))
    {
        printf("error loading texture\n");
        std::string str = "pwd";
        const char *command = str.c_str();
        system(command);
        str = "ls ../";
        command = str.c_str();
        system(command);
    }
    
    
    int index;
    float radius = tileRadius;
    std::pair<float,float> shifts[19] =
    {{-1.9,-3.24},{0,-3.24},{1.9,-3.24},
        {-2.85,-1.62},{-0.95,-1.62},{0.95,-1.62},{2.85,-1.62},
    {-3.8,0},{-1.9,0},{0,0},{1.9,0},{3.8,0},
        {-2.85,1.62},{-0.95,1.62},{0.95,1.62},{2.85,1.62},
        {-1.9,3.24},{0,3.24},{1.9,3.24}};
    for(index=0; index<19; index++){
        resourceTile* newRT = new resourceTile();
        printf("newRT %p\n", newRT);
        printf("newRT -> gettile() %p\n", (newRT -> getTile()));
        newRT -> getTile() -> setPointCount(6);
        newRT -> getTile() -> setRadius(radius);
        newRT -> getTile() -> setPosition(windowSize.y /2-radius, windowSize.y /2-radius);
        newRT -> getTile() -> setOutlineColor(sf::Color(0,0,0));
        newRT -> getTile() -> setTexture(texture);
        this -> resourceTiles.push_back(newRT);
        
    }
    for(index=0; index<19; index++){
        resourceTiles[index] -> getTile() -> move(shifts[index].first*radius,shifts[index].second*radius);
    }
    resourceTiles[9] -> getTile() -> setFillColor(sf::Color::Yellow);
    
}
void boardManager::initRoadways(sf::Vector2u windowSize){
    int index;
    float length = tileRadius;
    for(index=0; index<72; index++){
        roadway* newRoad = new roadway();
        this -> roadways.push_back(newRoad);
        newRoad -> getTile() -> setPosition(windowSize.y /2, windowSize.y /2);
        newRoad -> getTile() -> setFillColor(sf::Color(192,192,192));
        newRoad -> getTile() -> setSize(sf::Vector2f(length,length/6));
        newRoad -> getTile() -> setOutlineColor(sf::Color(0,0,0));
        newRoad -> getTile() -> setOutlineThickness(2);
    }
    
    std::pair<float,float> shifts330[24] =
    {{-2.85,-3.88},{-0.95,-3.88},{0.95,-3.88},
        {-3.8,-2.26},{-1.9,-2.26},{0,-2.26},{1.9,-2.26},
        {-4.75,-0.64},{-2.85,-0.64},{-0.95,-0.64},{0.95,-0.64},{2.85,-0.64},
        {-3.8,0.98},{-1.9,0.98},{0,0.98},{1.9,0.98},{3.8,0.98},
        {-2.85,2.6},{-0.95,2.6},{0.95,2.6},{2.85,2.6},
        {-1.9,4.22},{0,4.22},{1.9,4.22}
    };
    
    std::pair<float,float> shifts30[24] =
    {{-1.9,-4.33},{0,-4.33},{1.9,-4.33},
        {-2.85,-2.71},{-0.95,-2.71},{0.95,-2.71},{2.85,-2.71},
        {-3.8,-1.05},{-1.9,-1.05},{0,-1.05},{1.9,-1.05},{3.8,-1.05},
        {-4.75,0.60},{-2.85,0.60},{-0.95,0.60},{0.95,0.60},{2.85,0.60},
        {-3.8,2.22},{-1.9,2.22},{-0,2.22},{1.9,2.22},
        {-2.85,3.85},{-0.95,3.85},{0.95,3.85}
    };
    
    std::pair<float,float> shifts90[24] =
    {{-2.85,-3.88},{-0.95,-3.88},{0.95,-3.88},{2.85,-3.88},
        {-3.8,-2.26},{-1.9,-2.26},{0,-2.26},{1.9,-2.26},{3.8,-2.26},
        {-4.75,-0.64},{-2.85,-0.64},{-0.95,-0.64},{0.95,-0.64},{2.85,-0.64}, {4.75,-0.64},
        {-3.8,0.98},{-1.9,0.98},{0,0.98},{1.9,0.98},{3.8,0.98},
        {-2.85,2.6},{-0.95,2.6},{0.95,2.6},{2.85,2.6}
    };
    
    index = 0;
    while(index<24){
        roadways[index] -> getTile() -> rotate(330);
        roadways[index] -> getTile() -> move(shifts330[index].first*length,shifts330[index].second*length);
        index++;
    }
    while(index<48){
        roadways[index] -> getTile() -> rotate(30);
        roadways[index] -> getTile() -> move(shifts30[index%24].first*length+(length/12),shifts30[index%24].second*length-(length/12));
        index++;
    }
    while(index<72){
        roadways[index] -> getTile() -> rotate(90);
        roadways[index] -> getTile() -> move(shifts90[index%24].first*length+(length/12),shifts90[index%24].second*length+(length/12));
        index++;
    }
    
}
void boardManager::initSettlementAreas(sf::Vector2u windowSize){
    int index;
    float radius = tileRadius/5;
    float resTileRad = tileRadius;
    std::pair<float,float> shifts[54] =
    {{-4.75,0.55},{-2.85,0.55},{-0.95,0.55},{0.95,0.55},{2.85,0.55},{4.75,0.55},
    {-4.75,-0.55},{-2.85,-0.55},{-0.95,-0.55},{0.95,-0.55},{2.85,-0.55},{4.75,-0.55},
    {-3.8,1.1},{-1.9,1.1},{0,1.1},{1.9,1.1},{3.8,1.1},
    {-3.8,-1.1},{-1.9,-1.1},{0,-1.1},{1.9,-1.1},{3.8,-1.1},
    {-3.8,2.2},{-1.9,2.2},{0,2.2},{1.9,2.2},{3.8,2.2},
    {-3.8,-2.2},{-1.9,-2.2},{0,-2.2},{1.9,-2.2},{3.8,-2.2},
    {-2.85,2.75},{-0.95,2.75},{0.95,2.75},{2.85,2.75},
    {-2.85,-2.75},{-0.95,-2.75},{0.95,-2.75},{2.85,-2.75},
    {-2.85,3.85},{-0.95,3.85},{0.95,3.85},{2.85,3.85},
    {-2.85,-3.85},{-0.95,-3.85},{0.95,-3.85},{2.85,-3.85},
    {-1.9,4.4},{0,4.4},{1.9,4.4},
    {-1.9,-4.4},{0,-4.4},{1.9,-4.4}};
    for(index=0; index<54; index++){
        settlementArea* newSA = new settlementArea();
        this -> settlementAreas.push_back(newSA);
        newSA -> getTile() -> setRadius(radius);
        newSA -> getTile() -> setFillColor(sf::Color(192,192,192));
        newSA -> getTile() -> setPosition(windowSize.y /2-radius, windowSize.y /2-radius);
        newSA -> getTile() -> setOutlineColor(sf::Color(0,0,0));
        newSA -> getTile() -> setOutlineThickness(2);
    }
    for(index=0; index<54; index++){
        settlementAreas[index] -> getTile() -> move(shifts[index].first*resTileRad,shifts[index].second*resTileRad);
    }
}
void boardManager::initOcean(sf::Vector2u windowSize){
    this -> ocean.setPointCount(6);
    this -> ocean.setRadius(windowSize.y /2);
    this -> ocean.setFillColor(sf::Color::Blue);
    this -> ocean.setPosition(0,0);//(windowSize.x /2.0, windowSize.y /2.0);
}
void boardManager::initBackground(sf::Vector2u windowSize){
    sf::Texture* texture = new sf::Texture();
    if (!texture -> loadFromFile("res/img/background.jpg"))
    {
        printf("error loading texture\n");
        std::string str = "pwd";
        const char *command = str.c_str();
        system(command);
    }
    texture -> setRepeated(true);
    //this -> background.setSize(sf::Vector2f(windowSize.x, windowSize.y));
    this -> background.setTexture(*texture);
    this -> background.setTextureRect({0,0,(int)windowSize.x,(int)windowSize.y});
    
}
void boardManager::initBoard(){
    this -> gameFinished = false;
    sf::Vector2u windowSize = this -> window -> getSize();
    this -> tileRadius = windowSize.y/14;
    this -> initBackground(windowSize);
    this -> initOcean(windowSize);
    this -> initResourceTiles(windowSize);
    this -> initSettlementAreas(windowSize);
    this -> initRoadways(windowSize);
}
void boardManager::drawBoard(){
    
    int index;
    this -> window -> clear();
    this -> window -> draw(this -> background);
    this -> window -> draw(this -> ocean);
    for(index = 0; index < this -> resourceTiles.size(); index++){
        sf::CircleShape* t = this -> resourceTiles[index] -> getTile();
        this -> window -> draw(*t);
    }
    for(index = 0; index < this -> roadways.size(); index++){
        sf::RectangleShape* t = this -> roadways[index] -> getTile();
        this -> window -> draw(*t);
    }
    for(index = 0; index < this -> settlementAreas.size(); index++){
        sf::CircleShape* t = this -> settlementAreas[index] -> getTile();
        this -> window -> draw(*t);
    }
    this -> window -> display();
}
void boardManager::startGame(){
    bool finished = false;
    while(finished != true){
        sf::Event event;
        while(window -> pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    finished = true;
                    window -> close();
                    break;
            }
        }
        this -> drawBoard();
    }
}
void boardManager::start(){
    this -> initBoard();
    this -> startGame();
}
