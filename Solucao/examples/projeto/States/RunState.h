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

        // Jogadores
        cgf::Sprite player1;
        cgf::Sprite player2;

        sf::RenderWindow* screen;
        cgf::Sprite backgroundSprite;
        cgf::InputManager* im;
};

#endif // COMBATSTATE_H
