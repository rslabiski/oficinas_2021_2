/*

ESTA VERSÃO É ESPECIFICAMENTE PARA TESTAR O JOGO NO COMPUTADOR USANDO MATRIZES.

*/

#ifndef H_JOGONOTEBOOK
#define H_JOGONOTEBOOK

#include <stdio.h>

#define FACIL 'f'
#define MEDIO 'm'
#define DIFICIL 'd'

class JogoNotebook 
{
private:
    char dificuldade; // Variavel de controle para criação dos elementos
    bool fimDoJogo; //Variavel de controle do loop do jogo
    bool vitoria; //Variavel de controle da vitoria do jogador
    int **percorrido;

public:
    JogoNotebook();
    ~JogoNotebook();

    void setup();
    void executar(); //Execução do jogo
    void capturaEntrada(); //Captura entrada do joystick e altera velocidade do jogador
    void atualizar(); //Atualiza os elementos do jogo
    void renderizar(); //Renderiza no Display e Matriz
    void acoesVitoria(); //Acoes quando o jogador Vencer
    void acoesDerrota(); //Acoes quadno o jogador Perder

    void loop();
};

#endif