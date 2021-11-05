#include "JogoNotebook.h"

JogoNotebook::JogoNotebook() {
}

JogoNotebook::~JogoNotebook() {
}

void JogoNotebook::executar() {

    
    printf("Executou o jogo!\n"); //TEMPORARIO

    //loop do jogo
    /* fimDoJogo = true; //NECESSARIO ALTERAR PARA FALSE PARA QUE O JOGO ENTRE EM LOOP
    vitoria = true;
    do {
        capturaEntrada();
        atualizar();
        renderizar();
    } while(!fimDoJogo);
    
    //Executa acao de vitoria ou derrota
    if(vitoria)
        acoesVitoria();
    else
        acoesDerrota(); */
}

void JogoNotebook::capturaEntrada() {
    //Altera velocidade do jogador de acordo com a entrada do joystick
    printf("Capturou\n"); //TEMPORARIO
}

void JogoNotebook::atualizar() {
    //Movimenta
    //Verifica colisao
    //Remove elemento caso tenha colidido
    //Insere novo elemento se houver espaço no cenario
    
    //NAO ESQUECER DE ALTERAR AS VARIAVEIS FIM DE JOGO E VITORIA CASO OCORRA O FIM DO JOGO OU
    //NAO IRA SAIR DO LOOP!
    printf("Atualizou\n"); //TEMPORARIO
}

void JogoNotebook::acoesVitoria() {
    //LCD mostra pontos
    printf("Jogador Venceu\n"); //TEMPORARIO
}

/*teeeeeeeeeeeeeeeeeeste*/

void JogoNotebook::acoesDerrota() {
    //LCD Mostra Game Over
    printf("Jogador Perdeu\n"); //TEMPORARIO
}
