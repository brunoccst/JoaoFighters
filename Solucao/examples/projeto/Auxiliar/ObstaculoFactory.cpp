#include "ObstaculoFactory.h"
#include "Caixa.h"
#include <iostream>
#include <ctime>

using namespace std;

ObstaculoFactory::ObstaculoFactory()
{
    // Tipos:
    // Caixa
    quantidadeDeTipos = 1;
    cronometro = clock();
}

Obstaculo ObstaculoFactory::CriaObstaculo()
{
    // So gera se ja passou 2 segundos desde a ultima criacao
    //cout << "clock " <<  cronometro << " novo clock " << clock() << endl;
    if (clock() - cronometro > 1000000) {
        cronometro = clock();
        int chanceDeCriar = (int)((rand() % 100) + 1);
        if (chanceDeCriar > 50) {
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
        else {
            //cout << "Nao gerou objeto" << endl;
            return Obstaculo();
        }
    }

    else
    {
        //cout << "Nao gerou objeto" << endl;
        return Obstaculo();
    }

}

