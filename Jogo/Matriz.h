#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>
#include <iostream>
using namespace std;


class Matriz 
{
protected:
    int m[19][8]; /* Para evitar carros aparecerem brotados */
    int dificuldade;

public:
    Matriz(int dificuldade);
    ~Matriz();
    
    void imprimeMatriz(); /* Imprimir a partir da linha 3 para baixo */
    void atualizar(); /* Pega a posição do Jogador e reimprime a matriz */
    
    void setPosiMatriz(int x, int y, int valor) {this->m[x][y] = valor;} /* Modifica o valor em uma dada posição na matriz*/ 
    int getPosiMatriz(int x, int y) {return this->m[x][y];} /* Retorna o valor em uma dada posição na matriz*/ 

};

#endif