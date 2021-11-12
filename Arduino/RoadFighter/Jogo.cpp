#include "Jogo.hpp"

Jogo::Jogo()
{
  dificuldade = 1;
  fimDaFase = false;
  vitoria = false;
  tempoDaFase = 0.0;
  dt = 0.0;
  progresso = 0.0;
  tamanhoPista = 0;
  pJogador = NULL;
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
  // Variaveis para controle de clock
  float tAnterior, tAtual;

  rodarIntroJogo();
  selecionaDificuldade();
  inicializarFase();

  // Inicialização do controle do tempo
  dt = 0.0;
  tAnterior = millis() / 1000;

  // Loop do jogo
  while (!fimDaFase)
  {
    // Atualiza a variacao do tempo
    tAtual = millis() / 1000;
    dt = tAtual - tAnterior ;

    // Sequencia de jogo
    capturarEntrada();
    atualizar();
    renderizar();

    // Verifica fim de jogo
    if (tempoDaFase < 0.0)
    {
      vitoria = false;
      fimDaFase = true;
    }
    else if (progresso >= 1.0)
    {
      vitoria = true;
      fimDaFase = true;
    }
    else
      tAnterior = tAtual; // Reseta o tempo do tick
  }

  // Teste de vitoria
  if (vitoria)
    acoesVitoria();
  else
    acoesDerrota();

  // Desalocação de memoria
  if (pJogador != NULL)
  {
    delete(pJogador);
    pJogador = NULL;
  }

  //Espera dois segundos para Reiniciar o jogo
  delay(2000);
}

void Jogo::rodarIntroJogo()
{
  matrizLED.todosLeds(1);
  displayLCD.imprimeCentralizado("Road", 0);
  displayLCD.imprimeCentralizado("Fighter", 1);
  delay(1000);
  matrizLED.todosLeds(0);
  // Temporario
  delay(1000);
  matrizLED.todosLeds(1);
  delay(1000);
  matrizLED.todosLeds(0);
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

void Jogo::inicializarFase()
{
  // Inicializacao das variaveis de controle
  vitoria = false;
  fimDaFase = false;
  pJogador->setPontuacao(0.0);
  progresso = 0.0;

  // Alocacao do jogador
  pJogador = new Jogador(0.0 , 0.0, 0.0, 0.0);
  if (pJogador == NULL)
  {
    displayLCD.imprimeCentralizado("Err jogador=NULL", 0);
    displayLCD.imprimeCentralizado("inicializaFase()", 1);
    delay(5000);
  }

  // Definicao dos atributos da fase
  switch (dificuldade)
  {
    case 1:
      tempoDaFase = 5.0;
      tamanhoPista = 6;
      // Definir tamanho do Vetor / Lista de inimigos (qnt de inimigos) (inicia com todos null!)
      // Definir o tempo de spawn
      // Definir a porcentagem da velocidade base dos inimigos
      break;
    case 2:
      tempoDaFase = 4.0;
      tamanhoPista = 5;
      break;
    case 3:
    default:
      tempoDaFase = 3.0;
      tamanhoPista = 4;
      break;
  }

  // Acende a Pista
  int resto = (8 - tamanhoPista) / 2;
  matrizLED.ledIntervalo(0, 15, 0, resto - 1, HIGH);
  matrizLED.ledIntervalo(0, 15, tamanhoPista + resto, 7, HIGH);

  // Inicia Jogador
  // FALTA IMPLEMENTAR
}

void Jogo::capturarEntrada()
{
  // Captura entrada do jostick para mudar posicao do jogador
}

void Jogo::atualizar()
{
  // Atualiza tempos de acordo com o dt
  tempoDaFase -= dt;
  pJogador->somaPontuacao(dt * 200);//PONTO_POR_SEG);
  progresso += dt * PROGRESSO_POR_SEG;

  // Atuaiza Inimigo
  // Se VY > 0 e Não houver colisão, apaga o led superior e acende o inferior.
  // Se VX > 0 ou < 0 e houver NÃO houver colisão, move (apaga o corpo da coluna e desenha na nova coluna).

  // Atualiza Jogador
  // Se VX > 0 ou < 0 E não bater na parede, move (apaga o corpo da coluna e desenha na nova coluna).

  // Verifica colisão entre jogador e inimigos
}

void Jogo::renderizar()
{
  displayLCD.imprimeStatusFase(pJogador->getPontuacao(), tempoDaFase, progresso);
}

void Jogo::acoesVitoria()
{
  // Sequencia de ações que vão ocorrer com a vitória do jogador
  String pontos;
  pontos.concat((int)pJogador->getPontuacao());
  displayLCD.imprimeCentralizado("Vitoria!", 0);
  displayLCD.imprimeCentralizado("Pontos: " + pontos, 1);
}

void Jogo::acoesDerrota()
{
  // Sequencia de ações que vão ocorrer com a derrota do jogador
  String pontos;
  pontos.concat((int)pJogador->getPontuacao());
  displayLCD.imprimeCentralizado("Derrota!", 0);
  displayLCD.imprimeCentralizado("Pontos: " + pontos, 1);
}
