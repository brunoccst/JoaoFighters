/*
 *  Obstaculo.h
 *  Representacao de um obstaculo.
 */

#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "Sprite.h"

class Obstaculo
{
    public:
        Obstaculo();
        Obstaculo(cgf::Sprite sprite);
        cgf::Sprite GetSprite();
        cgf::Sprite sprite;
        bool Carregado;
        bool isVenom;
    protected:
    private:
};

#endif // OBSTACULO_H
