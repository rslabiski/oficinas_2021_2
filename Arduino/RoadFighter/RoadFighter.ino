#include "DisplayLCD.hpp"

DisplayLCD displayLCD;

#define PONTO_POR_SEG 4
#define PROGRESSO_POR_SEG 0.02

float dt = 0.0;
float pontuacao = 0;
float progresso = 0;

void setup() {
  //Temporario para testes
  Serial.begin(9600);
  displayLCD.setSetup();

  displayLCD.imprimeCentralizado("Bem",0);
  delay(2000);
  displayLCD.imprimeCentralizado("Vindo!", 1);
  delay(2000);
}

void loop() {

  dt = millis();
  displayLCD.imprimeStatusFase(pontuacao, millis()/1000, progresso);
  dt = millis() - dt;

  pontuacao += PONTO_POR_SEG * (dt/1000);
  progresso += PROGRESSO_POR_SEG * (dt/1000);
}
