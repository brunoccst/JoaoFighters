#ifndef VENOM_H
#define VENOM_H

#include "Obstaculo.h"

class Venom : public Obstaculo
{
    public:
        Venom();
        bool isEnemy;
        void playSprite();
    protected:
    private:
};

#endif // Venom_H
