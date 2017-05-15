#ifndef OBSTACULOFACTORY_H
#define OBSTACULOFACTORY_H

#include "Obstaculo.h"
#include "Caixa.h"
#include <ctime>

class ObstaculoFactory
{
    public:
        ObstaculoFactory();
        Obstaculo CriaObstaculo();
    protected:
    private:
        int quantidadeDeTipos;
        unsigned int cronometro;
};

#endif // OBSTACULOFACTORY_H
