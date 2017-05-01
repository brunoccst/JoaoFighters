/*
 *  MenuState.cpp
 *  Estado do menu inicial.
 *
 */

#include <iostream>
#include <cmath>
#include "Game.h"
#include "MenuState.h"
#include "InputManager.h"

MenuState MenuState::m_MenuState;

using namespace std;

void MenuState::init()
{
    //Loading background image
    im = cgf::InputManager::instance();
    backgroundSprite.load("BackGroundImages/CityNight2.png");

    //Loading fonts and texts
    if (!font.loadFromFile("data/fonts/arial.ttf")) {
        cout << "Cannot load arial.ttf font!" << endl;
        exit(1);
    }
    text.setFont(font);
    text.setString(L"John Runners");
    text.setCharacterSize(32); // in pixels
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void MenuState::cleanup()
{
    cout << "MenuState: Clean" << endl;
}

void MenuState::pause()
{
    cout << "MenuState: Paused" << endl;
}

void MenuState::resume()
{
    cout << "MenuState: Resumed" << endl;
}

void MenuState::handleEvents(cgf::Game* game)
{
    sf::Event event;
    sf::RenderWindow* screen = game->getScreen();

    while (screen->pollEvent(event))
    {
        // check the type of the event...
        switch (event.type)
        {
            // window closed
        case sf::Event::Closed:
            game->quit();
            break;

            // key pressed
        case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::Escape)
                game->quit();
            break;

        default:
            break;
        }
    }
}

void MenuState::update(cgf::Game* game)
{

}

void MenuState::draw(cgf::Game* game)
{
    screen = game->getScreen();
    backgroundSprite.setPosition(0,0);
    backgroundSprite.setScale(0.75, 0.64);
    text.setPosition(400, 200);
    screen->draw(backgroundSprite);
    screen->draw(text);
}
