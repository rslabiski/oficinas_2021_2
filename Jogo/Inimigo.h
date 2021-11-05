#ifndef INIMIGO_H
#define INIMIGO_H

#include <stdio.h>
#include "Veiculo.hpp"

class Inimigo : public Veiculo {
    private:
        int comprimento;
        int dano;
        float atraso;

    public:
        Inimigo(int xi, int yi, int vxi, int comprimento);
        ~Inimigo();

        int getDano() {return this->dano;}
        int getAtraso() {return this->atraso;}
};

#endif