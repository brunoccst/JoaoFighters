#include "Objeto.h"

Objeto::Objeto()
{

}

Objeto::Objeto(char* spriteURL)
{
    this->GetSprite().load(spriteURL);
}

/*
*   Retorna as coordenadas (x,y) maxima e minima do objeto na tela.
*   O formato e: [ min_x, min_y, max_x, maxy ].
*/
int* Objeto::GetLimites()
{
    sf::Vector2u tamanhoDaImagem = this->GetSprite().getSize();
    sf::Vector2f posicaoAtual = this->GetSprite().getPosition();

    return new int[4]
    {
        posicaoAtual.x,
        posicaoAtual.y,
        posicaoAtual.x + tamanhoDaImagem.x,
        posicaoAtual.y + tamanhoDaImagem.y
    };
}
