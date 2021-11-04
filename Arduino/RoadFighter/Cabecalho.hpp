#ifndef CABECALHO
#define CABECALHO

// Para operações nas classes
#include "Arduino.h"

//PIN_A_... Analógica
//PIN_D_... Digital

// Joystick
#define PIN_A_EIXO_X A0 // 0 - 517 - 1023
#define PIN_A_EIXO_Y A1 // 0 - 495 - 1023
#define PIN_D_EIXO_Z 7 // true or false
#define EIXO_MAX 1023 //Valor maximo do analogico
#define ZONA_MORTA 100 //Valor onde não ocorrre acoes do joystick

// Display
#define QNT_LINHAS 2
#define QNT_COLUNAS 16
#define ENDERECO_DISPLAY 0x27 //Endereço do display para o módulo I2C
// PIN_A_SDA A4
// PIN_A_SCL A5

// Matriz
#define PIN_A_CLK 13
#define PIN_A_DATA 11
#define PIN_A_CS 10

#endif
