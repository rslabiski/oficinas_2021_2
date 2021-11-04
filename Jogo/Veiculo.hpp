#ifndef H_VEICULO
#define H_VEICULO

#include <stdio.h>

class Veiculo
{
protected:
    int x;
    int y;
    int v;
    int comprimento;
    bool visivel; //Variavel de controle para alterar no atualizar e remover ou nao o elemento
    /*-- ANDREA: Não sei se há necessidade deste bool. --*/

public:
    Veiculo(int xi, int yi, int vxi, int comprimento);
    ~Veiculo();

    void inicializar(int xi, int yi, int v);

    virtual void mover() = 0;

    //Sets e Gets
    void setCoordenadas(int x, int y) { this->x = x; this->y = y;}
    void setVelocidade(int vy) {this->v = v;}
    void setComprimento(int c) {this->comprimento = c;}

    int getCoordenadaX() {return x;}
    int getCoordenadaY() {return y;}
    int getVelocidade() {return v;}
    int getComprimento() {return comprimento;}

    //Temporario para teste
    void imprimir(int id)
    {
        printf("\nID: %d", id);
        printf("\nX: %d", x);
        printf("\nY: %d", y);
        printf("\nVY: %d", v);
        printf("\nComprimento: %d", comprimento);
    }

    /* ANDREA: Sugestão */
    void imprimirMatriz(int** m);

};

#endif