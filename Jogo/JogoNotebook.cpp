#include "JogoNotebook.h"

JogoNotebook::JogoNotebook() {
}

JogoNotebook::~JogoNotebook() {
}

void JogoNotebook::setup(){

    srand(time(NULL));
    /* Declarar jogador, matriz e inimigos iniciais */
    /* Qual será a primeira velocidade? */

    //jogador = new Jogador(4, 0, 30, 1); 

    int px, py;

    // posicionaVeiculo(jogador, meio, meio);

    /* Vou assumir que começamos por 5 kekeke*/
    int i =0;
    while (i < 5){
        px = rand()%16;
        py = rand()%8;
        Inimigo *x = geradorInimigo();
        if(varrerColuna(px, py, x->getComprimento())){
            posicionaVeiculo(x, px, py);
            i++;
        } 
    }

}

/* Tem algum problema com essa função, favor verificar depois. */
void JogoNotebook::posicionaVeiculo(Veiculo* v, int x, int y){
    
    int i,j, c = v->getComprimento();
    for(i = y, j = 0; j < c; j++, i--){
        m->setPosiMatriz(x, i, v->getIdentificador());
    }
}

bool JogoNotebook::varrerColuna(int x, int y, int comprimento){

    int i = y;
    while(i >= y - comprimento){
        if(i < 0 || m->getPosiMatriz(x, i) != 0) return false;
        i--;
    }

    return true;
}

bool JogoNotebook::encerrarPartida(){
    if( tempo <=0 ) return true;
    /**/
}