/*
 *  PauseState.cpp
 *  Example "pause" state
 *
 */

#include <iostream>
#include "Game.h"
#include "InputManager.h"
#include "PauseState.h"

PauseState PauseState::m_PauseState;

using namespace std;

void PauseState::init()
{
    pauseSprite.load("data/img/paused.png"); // load menu state bitmap
    cout << "PauseState Init Successful" << endl;
}

void PauseState::cleanup()
{
    cout << "PauseState Cleanup Successful" << endl;
}

void PauseState::pause()
{
    cout << "PauseState Paused" << endl;
}

void PauseState::resume()
{
    cout << "PauseState Resumed" << endl;
}

void PauseState::handleEvents(cgf::Game* game)
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
            if(event.key.code == sf::Keyboard::P)
                game->popState();
            break;

            // we don't process other types of events
        default:
            break;
        }
    }
}

void PauseState::update(cgf::Game* game)
{
}

void PauseState::draw(cgf::Game *game)
{
    pauseSprite.setPosition(50,50);
//    menuSprite->draw(game->getScreen());
    game->getScreen()->draw(pauseSprite);
}

