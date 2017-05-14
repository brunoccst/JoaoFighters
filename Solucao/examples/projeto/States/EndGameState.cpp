/*
 *  EndGameState.cpp
 *  Estado de fim de jogo.
 *
 */

#include "Game.h"
#include "EndGameState.h"
#include <iostream>
#include <cstring>
#include "RunState.h"


EndGameState EndGameState::m_EndGameState;

// General constants
const char* EndGameText = "Fim de jogo";

using namespace std;

void EndGameState::init()
{
    im = cgf::InputManager::instance();

    // Carrega as fontes
    if (!font.loadFromFile("data/fonts/arial.ttf")) {
        cout << "Cannot load arial.ttf font!" << endl;
        exit(1);
    }

    // Configura o titulo do jogo
    endLabel.setFont(font);
    endLabel.setString(EndGameText);
    endLabel.setCharacterSize(32); // in pixels
    endLabel.setFillColor(sf::Color::Red);
    endLabel.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void EndGameState::cleanup()
{
    cout << "MenuState: Clean" << endl;
}

void EndGameState::pause()
{
    cout << "MenuState: Paused" << endl;
}

void EndGameState::resume()
{
    cout << "MenuState: Resumed" << endl;
}

void EndGameState::handleEvents(cgf::Game* game)
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
//            else if(event.key.code == sf::Keyboard::Space)
//                game->changeState(RunState::instance());
            break;

        default:
            break;
        }
    }
}

void EndGameState::update(cgf::Game* game)
{

}

void EndGameState::draw(cgf::Game* game)
{
    // Pega as configuracoes de tela do jogo
    screen = game->getScreen();

    // Desenha os textos na tela
    float screenX = screen->getSize().x;

    endLabel.setPosition((screenX / 2) - strlen(EndGameText) * 7, 200);
    screen->draw(endLabel);
}
