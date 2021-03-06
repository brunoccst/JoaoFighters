/*
 *  RunState.cpp
 *  Estado de combate (jogador contra jogador);
 *
 */

#ifndef RUNSTATE_H
#define RUNSTATE_H

#include "GameState.h"
#include "Sprite.h"
#include "InputManager.h"
#include "Obstaculo.h"
#include "ObstaculoFactory.h"

class RunState : public cgf::GameState
{
    public:

        void init();
        void cleanup();

        void pause();
        void resume();

        void handleEvents(cgf::Game* game);
        void update(cgf::Game* game);
        void draw(cgf::Game* game);

        // Implement Singleton Pattern
        static RunState* instance()
        {
            return &m_RunState;
        }

    protected:

        RunState() {}

    private:

        static RunState m_RunState;

        int dirx, diry;
        int score;
        int originalX, originalY, maxY;
        float runSpeed;
        float backgroundX;
        float backgroundXSize;
        bool pulando;
        bool segundoPulo;
        bool caindo;
        bool batendo;
        bool correndo;

        void updateScoreLabel();
        void updateBackgroundImage();
        void aumentaVelocidade();
        void atualizaPersonagem();
        void tentaAdicionarObstaculo();
        bool atualizaObstaculos();

        std::vector<Obstaculo> obstaculos;
        ObstaculoFactory geradorDeObstaculos;

        // Jogadores
        cgf::Sprite player;
        cgf::Sprite shot;
        sf::SoundBuffer backgroundMusic;
        sf::Sound music;

        sf::RenderWindow* screen;
        cgf::Sprite backgroundSprite1;
        cgf::Sprite backgroundSprite2;
        cgf::InputManager* im;

        sf::Font font;
        sf::Text scoreLabel;
};

#endif // COMBATSTATE_H
