#include "Jogo.hpp"

Jogo::Jogo()
{
  dificuldade = 1;
  fimDoJogo = false;
  vitoria = false;
  tempoDeJogo = 0.0;
  dt = 0.0;
  pontuacao = 0.0;
  progresso = 0.0;
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
  float tAnterior, tAtual; // Variaveis para controle de clock

  // Intro do jogo
  rodarIntroJogo();

  // Selecao de dificuldade
  selecionaDificuldade();

  // Inicialização da fase de acordo com a dificuldade
  // FALTA DECLARAR FUNCAO E IMPLEMENTAR
  tempoDeJogo = 10.; // De acordo com a dificuldade

  // Inicializacao das variaveis de controle
  vitoria = false;
  fimDoJogo = false;
  pontuacao = 0.0;
  progresso = 0.0;
  dt = 0.0;
  tAnterior = millis() / 1000; // Pega o tempo em segundos
  
  // Loop do jogo
  while (!fimDoJogo)
  {
    // Atualiza a variacao do tempo
    tAtual = millis() / 1000;
    dt = tAtual - tAnterior ;

    // Sequencia de jogo
    capturarEntrada();
    atualizar();
    renderizar();

    // Verifica fim de jogo
    if(tempoDeJogo < 0.0)
    {
      vitoria = false;
      fimDoJogo = true;
    }
    else if(progresso >= 1.0) 
    {
      vitoria = true;
      fimDoJogo = true;
    }
    else
      tAnterior = tAtual; // Reseta o tempo do tick
  }

  // Teste de vitoria
  if(vitoria)
    acoesVitoria();
  else
    acoesDerrota();

  //Espera dois segundos para Reiniciar o jogo
  delay(2000);
}

void Jogo::selecionaDificuldade()
{
  displayLCD.imprimeCentralizado("Selecione a", 0);
  displayLCD.imprimeCentralizado("dificuldade", 1);
  delay(2000);
  
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

  // Mostra informacao ao jogador
  displayLCD.imprimeCentralizado("Selecionado:", 0);
  if (dificuldade == 1)
    displayLCD.imprimeCentralizado("Facil", 1);
  else if (dificuldade == 2)
    displayLCD.imprimeCentralizado("Medio", 1);
  else
    displayLCD.imprimeCentralizado("Dificil", 1);
  delay(2000);
}

void Jogo::rodarIntroJogo()
{
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
}

void Jogo::capturarEntrada()
{
  // Captura entrada do jostick para mudar posicao do jogador
}

void Jogo::atualizar()
{
  // Atualiza tempos de acordo com o dt
  tempoDeJogo -= dt;
  pontuacao += dt * PONTO_POR_SEG;
  progresso += dt * PROGRESSO_POR_SEG;
  // FALTA O PROGRESSO!
  
  // Atuaiza Inimigo
  // Se VY > 0 e Não houver colisão, apaga o led superior e acende o inferior.
  // Se VX > 0 ou < 0 e houver NÃO houver colisão, move (apaga o corpo da coluna e desenha na nova coluna).

  // Atualiza Jogador
  // Se VX > 0 ou < 0 E não bater na parede, move (apaga o corpo da coluna e desenha na nova coluna).

  // Verifica colisão entre jogador e inimigos
}

void Jogo::renderizar()
{
  displayLCD.imprimeStatusFase(pontuacao, tempoDeJogo, progresso);
}

void Jogo::acoesVitoria()
{
  // Sequencia de ações que vão ocorrer com a vitória do jogador
  displayLCD.imprimeCentralizado("Vitoria!", 0);
  displayLCD.imprimeCentralizado("", 1);
}

void Jogo::acoesDerrota()
{
  // Sequencia de ações que vão ocorrer com a derrota do jogador
  displayLCD.imprimeCentralizado("Derrota!", 0);
  displayLCD.imprimeCentralizado("", 1);
}
