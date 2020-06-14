//
//  inputField.cpp
//  Game
//
//  Created by William Elliott on 6/13/20.
//  Copyright © 2020 wvelliott. All rights reserved.
//

#include "inputField.hpp"
void inputField::updateText(sf::Event event){
    char keycode = event.key.code;
    this -> text.setString(this -> text.getString() + keycode);
}
