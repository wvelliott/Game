//
//  main.cpp
//  Game
//
//  Created by William Elliott on 5/26/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <pthread.h>
#include "connectServer.hpp"
#include "gameStarter.hpp"
#include "boardManager.hpp"
void ConnectServer(sf::RenderWindow* window){
    connectServer CS;
    CS.setWindow(window);
    CS.start();
}
void GameStarter(sf::RenderWindow* window){
    gameStarter GS;
    GS.setWindow(window);
    GS.start();
}
void BoardManager(sf::RenderWindow* window){
    boardManager BM;
    BM.setWindow(window);
    BM.start();
}

int main() {
    int screenW = sf::VideoMode::getDesktopMode().width;
    int screenH = sf::VideoMode::getDesktopMode().height;
    
    sf::RenderWindow* window = new sf::RenderWindow( sf::VideoMode(screenW , screenH), "Catan");
    
    window -> setFramerateLimit(30);
    window -> setActive(false);
    
    ConnectServer(window);
//    if(window -> isOpen()){
//        GameStarter(window);
//    };
    if(window -> isOpen()){
        BoardManager(window);
    };
//    pthread_t ptid;
//    pthread_create(&ptid, NULL, &program, (void *) window);
//    pthread_join(ptid, NULL);
    
    while(window -> isOpen()){
        sf::Event event;
        while(window -> pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window -> close();
                    break;
            }
        }
    }
    
    return EXIT_SUCCESS;
}
