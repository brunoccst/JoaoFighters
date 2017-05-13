/*
 *  MenuState.cpp
 *  Estado do menu inicial.
 *
 */

#include <iostream>
#include <cmath>
#include <cstring>
#include "Game.h"
#include "MenuState.h"
#include "RunState.h"
#include "InputManager.h"
#include "../Constants.h"

MenuState MenuState::m_MenuState;

// General constants
const char* StartGameText = "Pressione o botao [Espaco] para iniciar";
const char* RunStateBackground = "BackGroundImages/CityNight2.png";

using namespace std;

void MenuState::init()
{
    im = cgf::InputManager::instance();

    // Carrega o sprite de background
    backgroundSprite.load(RunStateBackground);

    // Carrega as fontes
    if (!font.loadFromFile("data/fonts/arial.ttf")) {
        cout << "Cannot load arial.ttf font!" << endl;
        exit(1);
    }

    // Configura o titulo do jogo
    titleLabel.setFont(font);
    titleLabel.setString(GameTitle);
    titleLabel.setCharacterSize(32); // in pixels
    titleLabel.setFillColor(sf::Color::Red);
    titleLabel.setStyle(sf::Text::Bold | sf::Text::Underlined);


    // Configura o texto de inicializacao
    startGameLabel.setFont(font);
    startGameLabel.setString(StartGameText);
    startGameLabel.setCharacterSize(32); // in pixels
    startGameLabel.setFillColor(sf::Color::Red);
    startGameLabel.setStyle(sf::Text::Bold | sf::Text::Underlined);

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
            else if(event.key.code == sf::Keyboard::Space)
                game->changeState(RunState::instance());
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
    // Pega as configuracoes de tela do jogo
    screen = game->getScreen();

    // Desenha o background na tela
    backgroundSprite.setPosition(0,0);
    backgroundSprite.setScale(0.75, 0.64);
    screen->draw(backgroundSprite);

    // Desenha os textos na tela
    float screenX = screen->getSize().x;

    titleLabel.setPosition((screenX / 2) - strlen(GameTitle) * 7, 200);
    screen->draw(titleLabel);

    startGameLabel.setPosition((screenX / 2) - strlen(StartGameText) * 7, 250);
    screen->draw(startGameLabel);
}
