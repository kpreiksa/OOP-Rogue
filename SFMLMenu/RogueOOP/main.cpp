
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "DrawText.hpp"
#include "RogueWindow.hpp"

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

#define SCRWIDTH 800
#define SCRHEIGHT 600

int main(int, char const**)
{
    RogueWindow window(SCRWIDTH, SCRHEIGHT, "icon.png");
    window.addFont("scary", "FaceYourFears.ttf");
    window.addFont("happy", "CookieMonster.ttf");
    
    window.addMusic("menu", "main.ogg");
    window.addMusic("die", "dying.ogg");
    window.addMusic("win", "winedit.ogg");
    window.addMusic("play", "nice_music.ogg");

    // Start the game loop
    window.setWindowDisplayed(windowType::MENU);
    while (window.getWindow()->isOpen())
    {
        switch (window.getWindowDisplayed()) {
            case windowType::MENU:
                window.showMenuScreen();
                // Process events
                sf::Event menuEvent;
                while (window.getWindow()->pollEvent(menuEvent))
                {
                    // Close window: exit
                    if (menuEvent.type == sf::Event::Closed) {
                        window.getWindow()->close();
                    }
                    
                    // Escape pressed: exit
                    if (menuEvent.type == sf::Event::KeyPressed && menuEvent.key.code == sf::Keyboard::Escape) {
                        window.getWindow()->close();
                    }
                    
                    if (menuEvent.type == sf::Event::KeyPressed && menuEvent.key.code == sf::Keyboard::Down){
                        window.incrementMenuIndex();
                    }
                    if (menuEvent.type == sf::Event::KeyPressed && menuEvent.key.code == sf::Keyboard::Up){
                        window.decrementMenuIndex();
                    }
                    if (menuEvent.type == sf::Event::KeyPressed && menuEvent.key.code == sf::Keyboard::Return) {
                        window.setWindowDisplayed();
                    }
                }
                break;
            case PLAY:
                window.showPlayScreen();
                // Process events
                sf::Event playEvent;
                while (window.getWindow()->pollEvent(playEvent))
                {
                    // Close window: exit
                    if (playEvent.type == sf::Event::Closed) {
                        window.getWindow()->close();
                    }
                    
                    // Escape pressed: exit
                    if (playEvent.type == sf::Event::KeyPressed && playEvent.key.code == sf::Keyboard::Escape) {
                        window.setWindowDisplayed(windowType::MENU);
                    }
                }
                break;
            case WIN:
                window.showWinScreen();
                // Process events
                sf::Event winEvent;
                while (window.getWindow()->pollEvent(winEvent))
                {
                    // Close window: exit
                    if (winEvent.type == sf::Event::Closed) {
                        window.getWindow()->close();
                    }
                    
                    // Escape pressed: exit
                    if (winEvent.type == sf::Event::KeyPressed && winEvent.key.code == sf::Keyboard::Escape) {
                        window.setWindowDisplayed(windowType::MENU);
                    }
                }
                break;
            case DIE:
                window.showDieScreen();
                // Process events
                sf::Event dieEvent;
                while (window.getWindow()->pollEvent(dieEvent))
                {
                    // Close window: exit
                    if (dieEvent.type == sf::Event::Closed) {
                        window.getWindow()->close();
                    }
                    
                    // Escape pressed: exit
                    if (dieEvent.type == sf::Event::KeyPressed && dieEvent.key.code == sf::Keyboard::Escape) {
                        window.setWindowDisplayed(windowType::MENU);
                    }
                }
                break;
        }
    }

    return EXIT_SUCCESS;
}



