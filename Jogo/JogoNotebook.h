#ifndef H_JOGONOTEBOOK
#define H_JOGONOTEBOOK

#include <iostream>
#include <stdlib.h>
#include <vector>

#define FACIL 1
#define MEDIO 2
#define DIFICIL 3

#include <Jogador.h>
#include <Inimigo.h>
#include <time.h>
class Matriz;
class Veiculo;

class JogoNotebook 
{
private:
    int dificuldade; // Variavel de controle para criação dos elementos
    bool fimDoJogo; //Variavel de controle do loop do jogo
    bool vitoria; //Variavel de controle da vitoria do jogador
    Jogador *jogador;
    Matriz *m;
    vector<Inimigo> *inimigos;
    float tempo; /* temporário */

public:
    JogoNotebook();
    ~JogoNotebook();
    /* Função para inserir o inimigo nas 3 primeiras linhas */

    void setDificuldade(); /* Função com interação com o Display LCD e Joystick */
    int getDificuldade() { return dificuldade; }; 

    void setup(); /* Declarar jogador, matriz e inimigos iniciais */
    bool varrerColuna(int x, int y, int comprimento); /* Evita colisão de inimigos após criação (varrer coluna tamanho + 1) */ 
    void atualizador(); /* Chama o atualizaMatriz e cria inimigos (3 linhas iniciais matriz, chama varrerColuna),  */
    bool encerrarPartida(); /* verifica tempo, pontuacao e posicao do jogador */

    void posicionaVeiculo(Veiculo* v, int x, int y);
    // void re_interacao();
    Inimigo* geradorInimigo(); /* Função provisória */
};

#endif