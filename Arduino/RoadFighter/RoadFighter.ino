#include "DisplayLCD.hpp"
#include "Joystick.hpp"

DisplayLCD displayLCD;
Joystick joystick;

#define PONTO_POR_SEG 4
#define PROGRESSO_POR_SEG 0.02

float dt = 0.0;
float pontuacao = 0;
float progresso = 0;

void setup() {
  //Temporario para testes
  Serial.begin(9600);
  
  //Seta os elementos
  displayLCD.setSetup();
  joystick.setSetup();
}

void loop() {

  //Teste Display
  dt = millis();
  displayLCD.imprimeStatusFase(pontuacao, millis()/1000, progresso);
  dt = millis() - dt;

  pontuacao += PONTO_POR_SEG * (dt/1000);
  progresso += PROGRESSO_POR_SEG * (dt/1000);

  if(progresso > 1.0)
    progresso = 0;

  //Teste Joystick
  joystick.teste();
}
