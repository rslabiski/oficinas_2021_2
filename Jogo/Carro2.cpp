#include "Carro2.h"

Carro2::Carro2(int xi, int yi, int vxi, int comprimento, int dano, int atraso):Inimigo(xi, yi, vxi, comprimento, dano, atraso){
}

Carro2::~Carro2(){
}

void Carro2::mover(){
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

    srand(time(NULL));

    int mov = rand()%3;

    if(mov == 1){
        if(this->x > 0) //Evita segmentation fault
            setCoordenadas(this->x - 1, this->y);
        else deletarInimigo();
    } 
    else if (mov == 2){
        if(this->x < 7) //Evita segmentation fault
            setCoordenadas(this->x + 1, this->y);
        else deletarInimigo();
    }
}