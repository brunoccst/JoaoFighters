/*
 *  EndGameState.h
 *  Estado final.
 *
 */

#ifndef ENDGAMESTATE_H
#define ENDGAMESTATE_H

#include "GameState.h"
#include "Sprite.h"
#include "InputManager.h"

class EndGameState : public cgf::GameState
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
        static EndGameState* instance(int score)
        {
            m_EndGameState.score = score;
            return &m_EndGameState;
        }

    protected:

        EndGameState() {}

    private:

        static EndGameState m_EndGameState;

        int score;

        sf::RenderWindow* screen;
        cgf::InputManager* im;

        sf::Font font;
        sf::Text endLabel;
        sf::Text restartLabel;
        sf::Text scoreLabel;
};

#endif // ENDGAMESTATE_H
