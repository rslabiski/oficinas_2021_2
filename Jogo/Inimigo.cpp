#include "Inimigo.h"

Inimigo::Inimigo(int xi, int yi, int vxi, int comprimento, int dano, int atraso):Veiculo (xi, yi, vxi, comprimento){
    this->dano = dano;
    this->atraso = atraso;
}

Inimigo::~Inimigo(){
}

void Inimigo::mover(){
    if(this->v > 0){
        if(this->x + this->comprimento < 16) //Evita segmentation fault
            setCoordenadas(this->x + 1, this->y);
        else deletarInimigo();
    }
    else{
        if(this->x > 0)
            setCoordenadas(this->x - 1, this->y);
        else deletarInimigo();
    }
}