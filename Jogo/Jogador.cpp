#include "Jogador.h"

Jogador::Jogador(int xi, int yi, int vxi, int comprimento):Veiculo (xi, yi, vxi, comprimento){
    this->pontuacao = 0;
    this->tecla = NULL;
}

void Jogador::mover(char tecla) {

    switch (tecla)
    {
    case 'a':
        this->x = x - 1;
        break;

    case 'd':
        this->x = x + 1;
        break;

    case 's':
        if (this->v > 1)
            this->v = v - 1;
        break;

    case 'w':
        if (this->v < VMAX)
            this->v = v + 1;
        break;
    
    default:
        break;
    }
    this->tecla = NULL;
}

int Jogador::colide(Matriz* M, float tempo){
    int pos = M->getPosiMatriz(this->x, this->y), i = 0;
    if (pos != 0){
        while (M->getPosiMatriz(this->x, this->y + i) != 0){
            M->setPosiMatriz(this->x, this->y + i, 0);
            i++;
        }

        i = 1;

        while (M->getPosiMatriz(this->x, this->y - i) != 0){
            M->setPosiMatriz(this->x, this->y - i, 0);
            i++;
        }
        return 10*pos;
    } else return 0;
}
