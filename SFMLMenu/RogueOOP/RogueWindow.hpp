//
//  RogueWindow.h
//  RogueOOP
//
//  Created by Kyle Preiksa on 5/7/15.
//  Copyright (c) 2015 Kyle Preiksa. All rights reserved.
//

#ifndef __RogueOOP__RogueWindow__
#define __RogueOOP__RogueWindow__

#include <stdio.h>
#include <map>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"


typedef enum {MENU,PLAY,DIE,WIN} windowType;


class RogueWindow {
private:
    std::map<std::string, std::string> musicList;
    std::map<std::string, sf::Font> fontList;
    sf::RenderWindow *window;
    int SCRWIDTH;
    int SCRHEIGHT;
    int selectedMenuIndex;
    int displayedWindow;
    sf::Music currentMusic;
    
public:
    RogueWindow(int, int, std::string);
    void showMenuScreen();
    void showPlayScreen();
    void showWinScreen();
    void showDieScreen();
    
    void addFont(std::string, std::string);
    void addMusic(std::string, std::string);
    
    void incrementMenuIndex();
    void decrementMenuIndex();
    
    windowType getWindowDisplayed();
    void setWindowDisplayed(windowType);
    void setWindowDisplayed();
    
    sf::RenderWindow* getWindow();
};

#endif /* defined(__RogueOOP__RogueWindow__) */
