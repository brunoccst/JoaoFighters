#ifndef OBJETO_H
#define OBJETO_H

#include "Sprite.h"

class Objeto
{
    public:
        Objeto();
        Objeto(char* spriteURL);
        cgf::Sprite GetSprite() { return sprite; }
        void SetSprite(cgf::Sprite val) { sprite = val; }
        int* GetLimites();
    protected:
    private:
        cgf::Sprite sprite;
};

#endif // OBJETO_H
