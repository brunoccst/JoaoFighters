/*
 *  GameState.cpp
 *  Estado de combate (jogador contra jogador);
 *
 */

#include <iostream>
#include <cmath>
#include "Game.h"
#include "RunState.h"
#include "InputManager.h"
#include <sstream>

RunState RunState::m_RunState;

using namespace std;

// Sprites path
const char* SpiderMan = "Sprites/Spidey1.png";

void RunState::init()
{
    backgroundSprite.load("BackGroundImages/CityClean3.png");
    player.load(SpiderMan);
    player.setPosition(10,500);

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

    // Start default values
    runSpeed = 1.0;
    score = 0;

        //Loading fonts and texts
    if (!font.loadFromFile("data/fonts/arial.ttf")) {
        cout << "Cannot load arial.ttf font!" << endl;
        exit(1);
    }

    scoreLabel.setFont(font);
    scoreLabel.setCharacterSize(42); // in pixels
    scoreLabel.setFillColor(sf::Color::Red);
    scoreLabel.setStyle(sf::Text::Bold);
    scoreLabel.setPosition(0, 0);

    cout << "EstadoCombate: Init" << endl;
}

void RunState::cleanup()
{
    cout << "EstadoCombate: Clean" << endl;
}

void RunState::pause()
{
    cout << "EstadoCombate: Paused" << endl;
}

void RunState::resume()
{
    cout << "EstadoCombate: Resumed" << endl;
}

void RunState::handleEvents(cgf::Game* game)
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

    player.setXspeed(350*dirx);
    player.setYspeed(350*diry);
}

void RunState::update(cgf::Game* game)
{
    player.update(game->getUpdateInterval());
}

void RunState::updateScoreLabel() {
    ostringstream convert;   // stream used for the conversion
    convert << score;      // insert the textual representation of 'Number' in the characters in the stream
    scoreLabel.setString(convert.str());
}

void RunState::draw(cgf::Game* game)
{
    screen = game->getScreen();
    backgroundSprite.setPosition(0,0);
    backgroundSprite.setScale(0.8, 0.50);

    score += 1;
    if (score % 10 == 0) {
        runSpeed += 1;
    }

    updateScoreLabel();
    player.setScale(1.5, 1.5);
    screen->draw(backgroundSprite);
    screen->draw(player);
    screen->draw(scoreLabel);
}
