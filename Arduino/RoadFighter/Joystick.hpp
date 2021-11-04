#ifndef H_JOYSTICK
#define H_JOYSTICK

#include "Cabecalho.hpp"

class Joystick
{
  private:
    bool zClicado;
    bool zLiberado;

  public:
    Joystick();
    ~Joystick();

    void setSetup();

    int eixoX();  // -1 -> Esquerda   0 -> Neutro   1 -> Direita
    int eixoY();  // -1 -> Baixo      0 -> Neutro   1 -> Cima
    bool cliqueZ();  //  true -> Ao soltar o botao

    //TEMPORARIA
    void teste()
    {
      Serial.print("\nX: ");
      if (eixoX() == -1)
        Serial.print("Esquerda");
      else if (eixoX() == 1)
        Serial.print("Direita");
      else if (eixoX() == 0)
        Serial.print("Neutro");

      Serial.print("\tY: ");
      if (eixoY() == -1)
        Serial.print("Baixo");
      else if (eixoY() == 1)
        Serial.print("Cima");
      else if (eixoY() == 0)
        Serial.print("Neutro");

      Serial.print("\tZ: ");
      if (cliqueZ())
        Serial.print("1");
      else
        Serial.print("0");
      delay(100);
    }
};

#endif
