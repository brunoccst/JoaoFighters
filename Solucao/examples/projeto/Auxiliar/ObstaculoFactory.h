#ifndef OBSTACULOFACTORY_H
#define OBSTACULOFACTORY_H

#include "Obstaculo.h"
#include "Caixa.h"

class ObstaculoFactory
{
    public:
        ObstaculoFactory();
        Obstaculo CriaObstaculo();
    protected:
    private:
        int quantidadeDeTipos;
};

#endif // OBSTACULOFACTORY_H
