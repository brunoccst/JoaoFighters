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
    im = cgf::InputManager::instance();
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

}

void MenuState::update(cgf::Game* game)
{

}

void MenuState::draw(cgf::Game* game)
{

}
