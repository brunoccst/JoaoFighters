#include "ObstaculoFactory.h"
#include "Caixa.h"
#include "Venom.h"
#include <iostream>
#include <ctime>

using namespace std;

ObstaculoFactory::ObstaculoFactory()
{
    // Tipos:
    // Caixa
    quantidadeDeTipos = 2;
    cronometro = clock();
}

Obstaculo ObstaculoFactory::CriaObstaculo()
{
    // So gera se ja passou 2 segundos desde a ultima criacao
    //cout << "clock " <<  cronometro << " novo clock " << clock() << endl;
    //if (clock() - cronometro > 500000) {
        //cronometro = clock();
        int chanceDeCriar = (int)((rand() % 100) + 1);
        if (chanceDeCriar > 99) {
            switch((int)(rand() % quantidadeDeTipos) + 1) {
                case 1: //Caixa
                    cout << "Gerou venom" << endl;
                    return Venom();

                    break;
                default:
                    cout << "Gerou caixa" << endl;
                    return Caixa();
                    break;
            }
        }
        else {
            //cout << "Nao gerou objeto" << endl;
            return Obstaculo();
        }
    //}

    //else
    //{
        //cout << "Nao gerou objeto" << endl;
    //    return Obstaculo();
    //}

}

