#include "Matriz.h"

Matriz::Matriz(int dificuldade)
{
    this->dificuldade = dificuldade;
    int i, j, gap = 0;

    for(i = 0; i < 16; i++){
        for(j = 0; j < 8; j++){
            this->m[i][j] = 0;
        }
    }

    /* Instala Bordas */
    if(dificuldade > 1) gap = 1;
    
    for(i = 0; i < 19; i++){
        this->m[i][0+gap] = 1;
        this->m[i][7-gap] = 1;
    }
    
}

Matriz::~Matriz(){}

void Matriz::imprimeMatriz()
{
    int i, j;

    cout << "\n";
    for(i = 3; i < 16; i++){
        for(j = 0; j < 8; j++){
            cout << m[i][j] <<" ";
        }
        cout << "\n";
    }
}
