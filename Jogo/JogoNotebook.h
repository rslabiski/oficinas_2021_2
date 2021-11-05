#ifndef H_JOGONOTEBOOK
#define H_JOGONOTEBOOK

#include <stdio.h>

#define FACIL 1
#define MEDIO 2
#define DIFICIL 3

class JogoNotebook 
{
private:
    int dificuldade; // Variavel de controle para criação dos elementos
    bool fimDoJogo; //Variavel de controle do loop do jogo
    bool vitoria; //Variavel de controle da vitoria do jogador

public:
    JogoNotebook();
    ~JogoNotebook();
    /* Função para inserir o inimigo nas 3 primeiras linhas */

    void setDificuldade(); /* Função com interação com o Display LCD e Joystick */
    int getDificuldade(); 

    void setup(); /* Declarar jogador, matriz e inimigos iniciais */
    bool varrerColuna(); /* Evita colisão de inimigos após criação (varrer coluna tamanho + 1) */ 
    void atualizador(); /* Chama o atualizaMatriz e cria inimigos (3 linhas iniciais matriz, chama varrerColuna),  */
    void encerrarPartida(); /* verifica tempo, pontuacao e posicao do jogador */

    // void re_interacao();
};

#endif