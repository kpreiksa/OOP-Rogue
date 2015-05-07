//
//  DrawText.h
//  RogueOOP
//
//  Created by Kyle Preiksa on 5/6/15.
//  Copyright (c) 2015 Kyle Preiksa. All rights reserved.
//

#ifndef __RogueOOP__DrawText__
#define __RogueOOP__DrawText__

#include <stdio.h>
#include <SFML/Graphics.hpp>

class DrawText {
public:
    static sf::Text centeredText(sf::Font, float, std::string, int);
    
};

#endif /* defined(__RogueOOP__DrawText__) */
