//
//  RogueWindow.cpp
//  RogueOOP
//
//  Created by Kyle Preiksa on 5/7/15.
//  Copyright (c) 2015 Kyle Preiksa. All rights reserved.
//

#include "RogueWindow.hpp"

RogueWindow::RogueWindow(int width, int height, std::string iconFile):SCRHEIGHT(height), SCRWIDTH(width), displayedWindow(0), selectedMenuIndex(0){
    
    //sf::RenderWindow window(sf::VideoMode(width, height), "SFML window");
    this->window = new sf::RenderWindow(sf::VideoMode(width, height), "SFML window");
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + iconFile)) {
        return EXIT_FAILURE;
    }
    this->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}


void RogueWindow::showMenuScreen() {
    
    sf::Text titleText("Rogue 3.6", this->fontList["scary"], 100);
    titleText.setColor(sf::Color::White);
    sf::FloatRect titleTextRect = titleText.getLocalBounds(); // get bounds of the text... ie. how big it is
    titleText.setOrigin(titleTextRect.left + (titleTextRect.width/2.0f), titleTextRect.top + (titleTextRect.height/2.0f));
    titleText.setPosition(sf::Vector2f(SCRWIDTH/2.0f, 75));
    
    sf::Text playText("Play", this->fontList["scary"], 75);
    playText.setColor(sf::Color::White);
    sf::FloatRect playTextRect = playText.getLocalBounds(); // get bounds of the text... ie. how big it is
    playText.setOrigin(playTextRect.left + (playTextRect.width/2.0f), playTextRect.top + (playTextRect.height/2.0f));
    playText.setPosition(sf::Vector2f(SCRWIDTH/2.0f, 200));
    
    sf::Text dieText("Die", this->fontList["scary"], 75);
    dieText.setColor(sf::Color::White);
    sf::FloatRect dieTextRect = dieText.getLocalBounds(); // get bounds of the text... ie. how big it is
    dieText.setOrigin(dieTextRect.left + (dieTextRect.width/2.0f), dieTextRect.top + (dieTextRect.height/2.0f));
    dieText.setPosition(sf::Vector2f(SCRWIDTH/2.0f, 300));
    
    sf::Text winText("Win", this->fontList["scary"], 75);
    winText.setColor(sf::Color::White);
    sf::FloatRect winTextRect = winText.getLocalBounds(); // get bounds of the text... ie. how big it is
    winText.setOrigin(winTextRect.left + (winTextRect.width/2.0f), winTextRect.top + (winTextRect.height/2.0f));
    winText.setPosition(sf::Vector2f(SCRWIDTH/2.0f, 400));
    
    // Clear screen
    this->window->clear();
    
    if (this->selectedMenuIndex == 0)
        playText.setColor(sf::Color::Red);
    
    if (this->selectedMenuIndex == 1)
        dieText.setColor(sf::Color::Red);
    
    if (this->selectedMenuIndex == 2)
        winText.setColor(sf::Color::Red);
    
    // Draw the title string
    this->window->draw(titleText);
    this->window->draw(playText);
    this->window->draw(dieText);
    this->window->draw(winText);
    
    // Update the window
    window->display();
    
    return;
    
}
    
void RogueWindow::showPlayScreen() {
    
    sf::Text titleText(" You are\n playing\nda game!!!", this->fontList["scary"], 75);
    titleText.setColor(sf::Color::White);
    sf::FloatRect titleTextRect = titleText.getLocalBounds(); // get bounds of the text... ie. how big it is
    titleText.setOrigin(titleTextRect.left + (titleTextRect.width/2.0f), titleTextRect.top + (titleTextRect.height/2.0f));
    titleText.setPosition(sf::Vector2f(SCRWIDTH/2.0f, 200));
    
    
    // Clear screen
    this->window->clear();
    
    // Draw the title string
    this->window->draw(titleText);
    
    // Update the window
    this->window->display();
    
    return;
    
}

void RogueWindow::showWinScreen() {
    
    sf::Text titleText("You won!!!", this->fontList["happy"], 100);
    titleText.setColor(sf::Color::White);
    sf::FloatRect titleTextRect = titleText.getLocalBounds(); // get bounds of the text... ie. how big it is
    titleText.setOrigin(titleTextRect.left + (titleTextRect.width/2.0f), titleTextRect.top + (titleTextRect.height/2.0f));
    titleText.setPosition(sf::Vector2f(SCRWIDTH/2.0f, 75));
    
    
    // Clear screen
    this->window->clear();
    
    // Draw the title string
    this->window->draw(titleText);
    
    // Update the window
    this->window->display();
    
    return;
    
}

void RogueWindow::showDieScreen() {
    
    sf::Text titleText("You died :(", this->fontList["scary"], 100);
    titleText.setColor(sf::Color::White);
    sf::FloatRect titleTextRect = titleText.getLocalBounds(); // get bounds of the text... ie. how big it is
    titleText.setOrigin(titleTextRect.left + (titleTextRect.width/2.0f), titleTextRect.top + (titleTextRect.height/2.0f));
    titleText.setPosition(sf::Vector2f(SCRWIDTH/2.0f, 75));
    
    
    // Clear screen
    this->window->clear();
    
    // Draw the title string
    this->window->draw(titleText);
    
    // Update the window
    this->window->display();
    
    return;
    
}

void RogueWindow::addFont(std::string id, std::string fontFile){
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + fontFile)) {
        return EXIT_FAILURE;
    }
    this->fontList.emplace(id, font);
}
void RogueWindow::addMusic(std::string id, std::string musicFile){
    this->musicList.emplace(id, musicFile);
}

void RogueWindow::incrementMenuIndex(){
    if (this->selectedMenuIndex < 2) {
        this->selectedMenuIndex++;
    }
    else {
        this->selectedMenuIndex = 0;
    }
    
}

void RogueWindow::decrementMenuIndex(){
    if (this->selectedMenuIndex > 0) {
        this->selectedMenuIndex--;
    }
    else {
        this->selectedMenuIndex = 2;
    }
}

sf::RenderWindow* RogueWindow::getWindow(){
    return this->window;
}

void RogueWindow::setWindowDisplayed(windowType type) {
    this->displayedWindow = type;
    currentMusic.stop();
    if (this->displayedWindow == 0) {
        if (!currentMusic.openFromFile(resourcePath() + musicList["menu"])) {
            return EXIT_FAILURE;
        }
        currentMusic.play();
    }
    else if (this->displayedWindow == 1) {
        if (!currentMusic.openFromFile(resourcePath() + musicList["play"])) {
            return EXIT_FAILURE;
        }
        currentMusic.play();
    }
    else if (this->displayedWindow == 2) {
        if (!currentMusic.openFromFile(resourcePath() + musicList["die"])) {
            return EXIT_FAILURE;
        }
        currentMusic.play();
    }
    else if (this->displayedWindow == 3) {
        if (!currentMusic.openFromFile(resourcePath() + musicList["win"])) {
            return EXIT_FAILURE;
        }
        currentMusic.play();
    }
}

void RogueWindow::setWindowDisplayed() {
    if (this->selectedMenuIndex == 0) {
        setWindowDisplayed(windowType::PLAY);
    }
    else if (this->selectedMenuIndex == 1) {
        setWindowDisplayed(windowType::DIE);
    }
    else if (this->selectedMenuIndex == 2) {
        setWindowDisplayed(windowType::WIN);
    }
}

windowType RogueWindow::getWindowDisplayed() {
    if (this->displayedWindow == 0) {
        return windowType::MENU;
    }
    else if (this->displayedWindow == 1) {
        return windowType::PLAY;
    }
    else if (this->displayedWindow == 2) {
        return windowType::DIE;
    }
    else if (this->displayedWindow == 3) {
        return windowType::WIN;
    }
    
}
