/*
 *  MenuState.cpp
 *  Estado do menu inicial.
 *
 */

#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "GameState.h"
#include "Sprite.h"
#include "InputManager.h"

class MenuState : public cgf::GameState
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
        static MenuState* instance()
        {
            return &m_MenuState;
        }

    protected:

        MenuState() {}

    private:

        static MenuState m_MenuState;

        int dirx, diry;

        sf::RenderWindow* screen;
        cgf::InputManager* im;
};

#endif // MENUSTATE_H
