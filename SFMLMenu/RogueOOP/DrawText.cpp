//
//  DrawText.cpp
//  RogueOOP
//
//  Created by Kyle Preiksa on 5/6/15.
//  Copyright (c) 2015 Kyle Preiksa. All rights reserved.
//

#include "DrawText.hpp"

sf::Text DrawText::centeredText(sf::Font font, float verticalPosition, std::string str, int SCRWIDTH = 800) {
        // Title text
        sf::Text text(str, font, 50);
        text.setColor(sf::Color::White);
        sf::FloatRect textRect = text.getLocalBounds(); // get bounds of the text... ie. how big it is
        text.setOrigin(textRect.left + (textRect.width/2.0f), textRect.top + (textRect.height/2.0f));
        text.setPosition(sf::Vector2f(SCRWIDTH/2.0f, verticalPosition));
    
        return text;
    }


