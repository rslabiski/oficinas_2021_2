#include "MatrizLED.hpp"

//TEMPORARIO
#include <stdio.h>
///////////////////////////////

MatrizLED::MatrizLED() {

}

MatrizLED::~MatrizLED() {

}

void MatrizLED::reset() {
    printf("Resetou Matriz LED\n"); //TEMPORARIO
}

void MatrizLED::renderizar() {

    this->reset(); //Limpa para nao ocorrer sobrescricao de dados

    printf("Renderizou Matriz LED\n"); //TEMPORARIO
}