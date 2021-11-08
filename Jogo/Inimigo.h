#ifndef INIMIGO_H
#define INIMIGO_H

#include <stdio.h>
#include "Veiculo.h"

class Inimigo : public Veiculo {
    private:
        int dano;
        float atraso;

    public:
        Inimigo(int xi, int yi, int vxi, int comprimento, int dano, int atraso);
        ~Inimigo();

        int getDano() {return this->dano;}
        int getAtraso() {return this->atraso;}

        virtual void mover(char tecla = 0);
        void deletarInimigo();
};

#endif