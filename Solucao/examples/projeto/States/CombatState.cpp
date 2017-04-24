/*
 *  CombatState.cpp
 *  Estado de combate (jogador contra jogador);
 *
 */

#include <iostream>
#include <cmath>
#include "Game.h"
#include "CombatState.h"
#include "InputManager.h"

CombatState CombatState::m_CombatState;

using namespace std;

void CombatState::init()
{
    player1.load("data/img/Char14.png");
    player1.setPosition(10,100);

    dirx = 0; // direção do sprite: para a direita (1), esquerda (-1)
    diry = 0; // baixo (1), cima (-1)

    im = cgf::InputManager::instance();

    im->addKeyInput("left", sf::Keyboard::Left);
    im->addKeyInput("right", sf::Keyboard::Right);
    im->addKeyInput("up", sf::Keyboard::Up);
    im->addKeyInput("down", sf::Keyboard::Down);
    im->addKeyInput("quit", sf::Keyboard::Escape);
    im->addKeyInput("stats", sf::Keyboard::S);
    im->addMouseInput("rightclick", sf::Mouse::Right);

    cout << "EstadoCombate: Init" << endl;
}

void CombatState::cleanup()
{
    cout << "EstadoCombate: Clean" << endl;
}

void CombatState::pause()
{
    cout << "EstadoCombate: Paused" << endl;
}

void CombatState::resume()
{
    cout << "EstadoCombate: Resumed" << endl;
}

void CombatState::handleEvents(cgf::Game* game)
{
    screen = game->getScreen();
    sf::Event event;

    while (screen->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            game->quit();
    }

    dirx = diry = 0;

    if(im->testEvent("left"))
        dirx = -1;

    if(im->testEvent("right"))
        dirx = 1;

    if(im->testEvent("up"))
        diry = -1;

    if(im->testEvent("down"))
        diry = 1;

    if(im->testEvent("quit") || im->testEvent("rightclick"))
        game->quit();

    if(im->testEvent("stats"))
        game->toggleStats();

    player1.setXspeed(50*dirx);
    player1.setYspeed(50*diry);
}

void CombatState::update(cgf::Game* game)
{
    player1.update(game->getUpdateInterval());
}

void CombatState::draw(cgf::Game* game)
{
    screen = game->getScreen();
    screen->draw(player1);
}