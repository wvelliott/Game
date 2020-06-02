//
//  boardManager.hpp
//  Game
//
//  Created by William Elliott on 5/26/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#ifndef boardManager_hpp
#define boardManager_hpp

#include <stdio.h>
#include "resourceTile.hpp"
#include "roadway.hpp"
#include "settlementArea.hpp"
#include "player.hpp"
class boardManager{
private:
    std::vector<player*> players;
    std::vector<settlementArea*> settlementAreas;
    std::vector<roadway*> roadways;
    std::vector<resourceTile*> resourceTiles;
    sf::CircleShape ocean;
    sf::Sprite background;
    sf::RenderWindow *window;
    int screenW;
    int screenH;
    int tileRadius;
    void initSettlementAreas(sf::Vector2u windowSize);
    void initRoadways(sf::Vector2u windowSize);
    void initResourceTiles(sf::Vector2u windowSize);
    void initOcean(sf::Vector2u windowSize);
    void initBackground(sf::Vector2u windowSize);
public:
    void addPlayer(player* P);
    std::vector<player*> getPlayers();
    void addSetlementArea(settlementArea* area);
    std::vector<settlementArea*> getSettlementAreas();
    void addRoadway(roadway* road);
    std::vector<roadway*> getRoadways();
    void addResourceTile(resourceTile* rt);
    std::vector<resourceTile*> getResourceTiles();
    void setWindow(sf::RenderWindow *Window);
    void setScreenSize(int W, int H);
    void initBoard();
    void drawBoard();
};
#endif /* boardManager_hpp */
