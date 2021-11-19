#ifndef H_JOGO
#define H_JOGO

#include "Cabecalho.hpp"
#include "DisplayLCD.hpp"
#include "Joystick.hpp"
#include "MatrizLED.hpp"
#include "Jogador.hpp"
#include "Pista.hpp"
#include "Inimigo.hpp"

// LEDS
#define P_LED_G 5
#define P_LED_Y 4
#define P_LED_R 3

class Jogo
{
  private:
    int dificuldade; // Variavel de contole da dificuldade do jogo
    bool fimDaFase; // Variável de controle do loop da fase
    bool vitoria; // Variável de controle da vitória do jogador
    float tempoDaFase; // Tempo que será mostrado no display
    float dt; // Tempo de tick do loop do jogo
    float progresso; // Progresso da pista

    DisplayLCD displayLCD;
    Joystick joystick;
    MatrizLED matrizLED;

    Jogador *pJogador;
    Pista *pPista;

    // Vetor de inimigos

  public:
    Jogo();
    ~Jogo();

    void Setup(); // Setup do Hardware
    void executar(); // Execução do jogo (Não é o loop da fase!)
    void rodarIntroJogo();
    void selecionaDificuldade(); // Jogador seleciona a dificultade do jogo
    void inicializarFase();
    void capturarEntrada(); // Captura entrada do joystick e altera velocidade do jogador
    void atualizar(); // Atualiza os elementos do jogo
    void renderizar(); // Renderiza no Display e Matriz
    void acoesVitoria(); // Acoes quando o jogador Vencer
    void acoesDerrota(); // Acoes quadno o jogador Perder

    void inicializarPista();
    void inicializarJogador();
    void desalocarElementos(); // desaloca os ponteiros do Jogo
    void desalocarInimigo(Inimigo *pInimigo); // Funcao para desalocar inimigo
};

#endif
