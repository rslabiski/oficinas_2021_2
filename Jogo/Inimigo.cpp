#include "Inimigo.h"

Inimigo::Inimigo(int xi, int yi, int vxi, int comprimento, int dano, int atraso):Veiculo (xi, yi, vxi, comprimento){
    this->dano = dano;
    this->atraso = atraso;
}

Inimigo::~Inimigo(){
}

void Inimigo::mover(){
    if(this->v > 0){
        if(this->y + this->comprimento < 16) //Evita segmentation fault
            setCoordenadas(this->x, this->y + 1);
        else deletarInimigo();
    }
    else{
        if(this->y > 0)
            setCoordenadas(this->x, this->y - 1);
        else deletarInimigo();
    }
}