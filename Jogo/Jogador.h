#ifndef JOGADOR_H
#define JOGADOR_H

#include "Veiculo.hpp"

/*
    acelerar = inimigos pra baixo
    freiar = inimigos para cima

*/
class Jogador: public Veiculo {
    private:
        int i;
        int posi;
        int posj;

    public:
        Jogador();
        ~Jogador();
};

#endif