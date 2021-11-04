#ifndef H_MATRIZ_LED
#define H_MATRIZ_LED

#include "Cabecalho.hpp"
#include <MD_MAX72xx.h>

class MatrizLED : 
  public MD_MAX72XX
{
public:
  MatrizLED();
  ~MatrizLED();

  void setSetup();

  void led(int linha, int coluna, int ligado); //0 -> Desligado, != 0 -> Ligado
  void todosLeds(int ligado); //0-> apagar todos, != -> Ligar todos

  /*
  void acenderLed(int l, int c);
  void apagarLed(int l, int c);
  void acenderTodosLeds();
  void apagarTodosLeds();
  */
};

#endif
