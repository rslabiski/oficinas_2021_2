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
};

#endif