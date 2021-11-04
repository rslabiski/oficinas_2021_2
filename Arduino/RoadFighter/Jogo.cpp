#include "Jogo.hpp"

Jogo::Jogo()
{
  
}

Jogo::~Jogo()
{
  
}

void Jogo::inicializar()
{
  Serial.print("Inicializou\n");
}

void Jogo::executar()
{
  Serial.print("Rodando!\n");
  delay(2000);
}
