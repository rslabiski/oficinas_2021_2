#ifndef CARRO2_H
#define CARRO2_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Inimigo.h"

class Carro2 : public Inimigo
{
    private:
        int velocidadex;
    public:
        Carro2(int xi, int yi, int vxi, int comprimento, int dano, int atraso);
        ~Carro2();

        void mover();
};

#endif
