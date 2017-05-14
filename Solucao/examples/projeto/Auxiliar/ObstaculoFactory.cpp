#include "ObstaculoFactory.h"
#include "Caixa.h"
#include <iostream>

using namespace std;

ObstaculoFactory::ObstaculoFactory()
{
    // Tipos:
    // Caixa
    quantidadeDeTipos = 1;
}

Obstaculo ObstaculoFactory::CriaObstaculo()
{
    int chanceDeCriar = (int)((rand() % 100) + 1);
    if (chanceDeCriar > 99) {
        switch((int)(rand() % quantidadeDeTipos) + 1) {
            case 1: //Caixa
                cout << "Gerou caixa" << endl;
                return Caixa();

                break;
            default:
                cout << "Gerou default (caixa)" << endl;
                return Caixa();
                break;
        }
    }
    else
    {
        //cout << "Nao gerou objeto" << endl;
        return Obstaculo();
    }

}

