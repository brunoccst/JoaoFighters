#include "Obstaculo.h"

Obstaculo::Obstaculo()
{
    this->Carregado = false;
}

Obstaculo::Obstaculo(cgf::Sprite sprite)
{
    this->sprite = sprite;
    this->Carregado = true;
}

cgf::Sprite Obstaculo::GetSprite()
{
    return this->sprite;
}
