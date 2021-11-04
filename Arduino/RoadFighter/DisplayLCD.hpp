#ifndef H_DISPLAY_LCD
#define H_DISPLAY_LCD

#include "Cabecalho.hpp"

//#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class DisplayLCD:
  public LiquidCrystal_I2C
{
public:
  DisplayLCD();
  ~DisplayLCD();

  void setSetup();
  void imprimeCentralizado(String texto, int linha); //linha 0 ou 1
  void imprimeStatusFase(int pontos, int segundos, float progressoCorrida); //Pontos 0 - 999, tempo 0 à 999 s., progressoCorrida 0.0 - 1.0

};

#endif
