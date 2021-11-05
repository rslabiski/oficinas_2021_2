#ifndef CARRO2_H
#define CARRO2_H

#include <stdio.h>
#include "Inimigo.h"

class Carro2 : public Inimigo
{
    private:
        int velocidadex;
    public:
        Carro2();
        ~Carro2();

        void mover();
};

#endif
