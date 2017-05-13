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
    // Carrega background
    backgroundSprite1.load("BackGroundImages/CityClean3.png");
    backgroundSprite1.setScale(0.8, 0.50);

    backgroundSprite2.load("BackGroundImages/CityClean3.png");
    backgroundSprite2.setScale(0.8, 0.50);

    backgroundX = 0.0;
    backgroundXSize = backgroundSprite1.getSize().x - 300;
    updateBackgroundImage();

    // Carrega player
    originalX = 100;
    originalY = 500;
    maxY = originalY - 100;

    player.load(SpiderMan);
    player.setPosition(originalX,originalY);
    player.setScale(1.5, 1.5);
    pulando = false;
    caindo = false;

    im = cgf::InputManager::instance();

    im->addKeyInput("left", sf::Keyboard::Left);
    im->addKeyInput("right", sf::Keyboard::Right);
    im->addKeyInput("up", sf::Keyboard::Up);
    im->addKeyInput("down", sf::Keyboard::Down);
    im->addKeyInput("quit", sf::Keyboard::Escape);
    im->addKeyInput("stats", sf::Keyboard::S);
    im->addMouseInput("rightclick", sf::Mouse::Right);

    // Start default values
    runSpeed = 0.1;
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

    // Ativa o "pulo" pressionando a tecla de seta para cima
    if(im->testEvent("up"))
    {
        if (!pulando) {
            pulando = true;
        }
    }

    // TODO: implementar botao "enter" para pausar
//    if(im->testEvent("enter"))
//        game->changeState(PauseState::instance());

    if(im->testEvent("quit") || im->testEvent("rightclick"))
        game->quit();

    if(im->testEvent("stats"))
        game->toggleStats();
}

void RunState::update(cgf::Game* game)
{
    player.update(game->getUpdateInterval());

    // Incrementa score
    score += 1;

    // Aumenta a velocidade a cada marca de score
    switch (score) {
        case 250:
            runSpeed += 0.1;
            break;
        case 500:
            runSpeed += 0.05;
            break;
        case 1000:
            runSpeed += 0.05;
            break;
        case 2000:
            runSpeed += 0.05;
            break;
        case 4000:
            runSpeed += 0.05;
            break;
        case 8000:
            runSpeed += 0.05;
            break;
    }

    // Se estiver no estado "pulando"..
    if (pulando) {
        // Se estiver caindo, continua caindo ate chegar ao solo
        if (caindo) {
            cout << "Caindo" << endl;
            player.setPosition(player.getPosition().x, player.getPosition().y + 10);
        }
        // Se nao, continua subindo no pulo
        else {
            player.setPosition(player.getPosition().x, player.getPosition().y - 10);
            cout << "Pulando" << endl;
        }

        // Se chegou ao maximo Y, comeca a descer
        if (player.getPosition().y <= maxY){
            cout << "Chegou ao maximo Y, comecando a cair" << endl;
            caindo = true;
        }
        else if (player.getPosition().y >= originalY) {
            cout << "Chegou ao solo, pode pular novamente" << endl;
            pulando = false;
            caindo = false;
        }
    }
}

void RunState::updateScoreLabel() {
    ostringstream convert;   // stream used for the conversion
    convert << score;      // insert the textual representation of 'Number' in the characters in the stream
    scoreLabel.setString(convert.str());
}

void RunState::updateBackgroundImage(){
    backgroundSprite1.setPosition(backgroundX, 0);
    backgroundSprite2.setPosition(backgroundX + backgroundXSize, 0);
    backgroundX -= runSpeed;
    if (0 - backgroundX >=  backgroundXSize)
    {
        backgroundX = 0;
    }
}

void RunState::draw(cgf::Game* game)
{
    screen = game->getScreen();

    updateScoreLabel();
    updateBackgroundImage();

    screen->draw(backgroundSprite1);
    screen->draw(backgroundSprite2);
    screen->draw(player);
    screen->draw(scoreLabel);
}
