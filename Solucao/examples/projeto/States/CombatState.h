/*
 *  CombatState.cpp
 *  Estado de combate (jogador contra jogador);
 *
 */

#ifndef COMBATSTATE_H
#define COMBATSTATE_H

#include "GameState.h"
#include "Sprite.h"
#include "InputManager.h"

class CombatState : public cgf::GameState
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
        static CombatState* instance()
        {
            return &m_CombatState;
        }

    protected:

        CombatState() {}

    private:

        static CombatState m_CombatState;

        int dirx, diry;

        // Jogadores
        cgf::Sprite player1;
        cgf::Sprite player2;

        sf::RenderWindow* screen;
        cgf::InputManager* im;
};

#endif // COMBATSTATE_H
