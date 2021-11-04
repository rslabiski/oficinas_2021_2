#include "Joystick.hpp"

Joystick::Joystick()
{
  zClicado = false;
  zLiberado = false;
}

Joystick::~Joystick()
{
  
}

void Joystick::setSetup()
{
  //Constantes estão no arquivo Cabecalho.hpp
  pinMode(PIN_A_EIXO_X, INPUT);
  pinMode(PIN_A_EIXO_Y, INPUT);
  pinMode(PIN_D_EIXO_Z, INPUT);
  digitalWrite(PIN_D_EIXO_Z, HIGH); //Se não setar, ele fica enviando pulsos aleatórios!
}

int Joystick::eixoX()
{
  float valor = analogRead(PIN_A_EIXO_X);
  
  if(valor <= (EIXO_MAX - ZONA_MORTA) / 2)
    return -1;
  else if(valor >= (EIXO_MAX + ZONA_MORTA) / 2) 
    return 1;
  else
    return 0;
}

int Joystick::eixoY()
{
  float valor = analogRead(PIN_A_EIXO_Y);
  
  if(valor <= (EIXO_MAX - ZONA_MORTA) / 2)
    return 1;
  else if(valor >= (EIXO_MAX + ZONA_MORTA) / 2) 
    return -1;
  else
    return 0;
}

bool Joystick::cliqueZ()
{
  bool clique = digitalRead(PIN_D_EIXO_Z);

  //Por causa do setSetup = HIGH, se não ele manda pulsos aleatorios
  if( clique == LOW) { 
    zClicado = true;
    zLiberado = false;
  }
  else {
    zLiberado = true;
  }
  if(zClicado && zLiberado) {
    zClicado = false;
    zLiberado = false;
    return true;
  }
  else {
    return false;
  }
}
