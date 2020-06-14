//
//  inputField.hpp
//  Game
//
//  Created by William Elliott on 6/13/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#ifndef inputField_hpp
#define inputField_hpp


#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <string>
#include "button.hpp"
class inputField : public button{
public:
    void updateText(sf::Event event);
};

#endif /* inputField_hpp */
