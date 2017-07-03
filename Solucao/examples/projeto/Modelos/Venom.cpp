#include "Venom.h"
#include <iostream>

using namespace std;

Venom::Venom()
{
    sprite.setPosition(950, 460);
    sprite.setScale(0.5, 0.5);
    sprite.loadXML("Sprites/SpideyVenomRunXML.xml");
    sprite.loadAnimation("Sprites/VenomAnim.xml");
    sprite.setAnimRate(10);
    sprite.setAnimation("run");
    sprite.play();
    //cout << "AEHOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
    this->isVenom = true;
    this->Carregado = true;
}
