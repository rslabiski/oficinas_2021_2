#ifndef JOGADOR_H
#define JOGADOR_H

#include "Veiculo.hpp"
class Matriz;

/*
    acelerar = inimigos pra baixo
    freiar = inimigos para cima

*/
class Jogador: public Veiculo {
    private:
        char tecla;
        int pontuacao;

    public:
        Jogador(int xi, int yi, int vxi); /**/
        ~Jogador();

        void mover(char tecla); /* a w s d, 'w' e 's' mudam velocidade */
        void setVelocidade(int v);

        int colide(Matriz* M, float tempo); /* Retorna o dano se colidir, se não, retorna 0, se colidir faz o veículo explodir */
        int atualizaPontuacao(int dano); /* Recebe o retorno do colide */
    
};

#endif
