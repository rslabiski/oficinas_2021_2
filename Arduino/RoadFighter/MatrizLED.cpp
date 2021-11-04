#include "MatrizLED.hpp"

MatrizLED::MatrizLED():
  MD_MAX72XX(MD_MAX72XX::GENERIC_HW, PIN_A_DATA, PIN_A_CLK, PIN_A_CS, 2)
{
  //Constantes estão no arquivo Cabecalho.hpp
}
 
MatrizLED::~MatrizLED()
{
  
}

void MatrizLED::setSetup()
{
  begin(); //Inicializa
  clear(); //Limpa matriz
  control(MD_MAX72XX::INTENSITY, 0); //Define intensidade como 0 (Pode ser 1 e 2 mas fica muito forte)
}

void MatrizLED::led(int linha, int coluna, int ligado) //0 -> Desligado, != 0 -> Ligado
{
  if(ligado == 0)
    setPoint(coluna, linha, LOW);
  else
    setPoint(coluna, linha, HIGH);
}

void MatrizLED::todosLeds(int ligado)
{
  for(int i = 0; i < 16; i++)
    for(int j = 0; j < 8; j++)
      led(i,j, ligado);
}
