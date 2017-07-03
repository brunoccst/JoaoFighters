#include "Caixa.h"

Caixa::Caixa()
{
    sprite.load("Sprites/caixa_1.png");
    sprite.setScale(0.05, 0.05);
    sprite.setPosition(950, 500);
    this->Carregado = true;
}
