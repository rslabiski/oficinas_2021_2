#include "Jogo.hpp"

Jogo::Jogo()
{
  dificuldade = 1;
  fimDoJogo = false;
  vitoria = false;

  // Temporario ============================================================
  dt = 0.0;
  pontuacao = 0;
  progresso = 0;
}

Jogo::~Jogo()
{

}

void Jogo::Setup()
{
  displayLCD.Setup();
  joystick.Setup();
  matrizLED.Setup();
  pinMode(P_LED_G, OUTPUT);
  pinMode(P_LED_Y, OUTPUT);
  pinMode(P_LED_R, OUTPUT);
}

void Jogo::executar()
{
  delay(5000);
  
  // Intro do jogo
  matrizLED.todosLeds(1);
  displayLCD.imprimeCentralizado("Road", 0);
  displayLCD.imprimeCentralizado("Fighter", 1);
  
  delay(2000);
  matrizLED.todosLeds(0);
  // Temporario
  delay(1000);
  matrizLED.todosLeds(1);
  delay(1000);
  matrizLED.todosLeds(0);

  // ======
  displayLCD.imprimeCentralizado("Selecione a", 0);
  displayLCD.imprimeCentralizado("dificuldade", 1);
  delay(2000);

  // Selecao de dificuldade
  selecionaDificuldade();

  displayLCD.imprimeCentralizado("Selecionado:", 0);
  if(dificuldade == 1)
    displayLCD.imprimeCentralizado("Facil",1);
  else if(dificuldade == 2)
    displayLCD.imprimeCentralizado("Medio",1);
  else
    displayLCD.imprimeCentralizado("Dificil",1);

  delay(2000);

  displayLCD.imprimeCentralizado("Loop do jogo",0);
  displayLCD.imprimeCentralizado("Iniciado",1);

  // Inicializacao das variaveis de controle
  dt = 0;
  vitoria = false;
  fimDoJogo = false;

  // Inicialização da fase de acordo com a dificuldade

  // Loop do jogo
  while (!fimDoJogo)
  {
    // Temporário =================================
    matrizLED.todosLeds(1);
    delay(500);
    matrizLED.todosLeds(0);
    delay(500);
  }
}

void Jogo::selecionaDificuldade()
{
  //Inicia com dificuldade facil
  dificuldade = 1;
  digitalWrite(P_LED_G, HIGH);
  digitalWrite(P_LED_Y, LOW);
  digitalWrite(P_LED_R, LOW);

  displayLCD.imprimeCentralizado("Facil", 0); //linha 0 ou 1
  displayLCD.imprimeCentralizado("", 1); //linha 0 ou 1

  //Enquanto o jogador não clica com o Z
  while ( !joystick.cliqueZ() )
  {
    if ( joystick.eixoX() == -1 && dificuldade == 2)
    {
      digitalWrite(P_LED_G, HIGH);
      digitalWrite(P_LED_Y, LOW);
      digitalWrite(P_LED_R, LOW);

      displayLCD.imprimeCentralizado("Facil", 0);
      displayLCD.imprimeCentralizado("", 1);

      this->dificuldade = 1;
    }
    else if ( joystick.eixoX() == 1 && dificuldade == 1 || joystick.eixoX() == -1 && dificuldade == 3)
    {
      digitalWrite(P_LED_G, LOW);
      digitalWrite(P_LED_Y, HIGH);
      digitalWrite(P_LED_R, LOW);

      displayLCD.imprimeCentralizado("Medio", 0);
      displayLCD.imprimeCentralizado("", 1);

      this->dificuldade = 2;
    }
    else if ( joystick.eixoX() == 1 && dificuldade == 2)
    {
      digitalWrite(P_LED_G, LOW);
      digitalWrite(P_LED_Y, LOW);
      digitalWrite(P_LED_R, HIGH);

      displayLCD.imprimeCentralizado("Dificil", 0);
      displayLCD.imprimeCentralizado("", 1);

      this->dificuldade = 3;
    }
    delay(200);
  }
}

void Jogo::capturaEntrada()
{

}

void Jogo::atualizar()
{

}

void Jogo::renderizar()
{

}

void Jogo::acoesVitoria()
{

}

void Jogo::acoesDerrota()
{

}
