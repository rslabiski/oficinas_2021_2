#include "DisplayLCD.hpp"

//TEMPORARIO
#include <stdio.h>
///////////////////////////////

DisplayLCD::DisplayLCD() {

}

DisplayLCD::~DisplayLCD() {

}

void DisplayLCD::reset() {
    printf("Resetou Display LCD\n"); //TEMPORARIO
}

void DisplayLCD::renderizar() {
    
    this->reset(); //Limpa para nao ocorrer sobrescricao de dados

    printf("Pontos: 100\n"); //TEMPORARIO
    printf("Tempo: 20s.\n"); //TEMPORARIO
}