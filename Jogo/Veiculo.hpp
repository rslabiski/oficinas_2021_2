#ifndef H_VEICULO
#define H_VEICULO

#include <stdio.h>

class Veiculo
{
protected:
    int x;
    int y;
    int vx;
    int vy;
    int comprimento;
    bool visivel; //Variavel de controle para alterar no atualizar e remover ou nao o elemento

public:
    Veiculo(int xi, int yi, int vxi, int vyi, int comprimento);
    ~Veiculo();

    void inicializar(int xi, int yi, int vxi, int vyi);

    virtual void mover() = 0;

    //Sets e Gets
    void setX(int x) {this->x = x;}
    void setY(int y) {this->y = y;}
    void setVX(int vx) {this->vx = vx;}
    void setVY(int vy) {this->vy = vy;}
    void setComprimento(int c) {this->comprimento = c;}

    int getX() {return x;}
    int getY() {return y;}
    int getVX() {return vx;}
    int getVY() {return vy;}
    int getComprimento() {return comprimento;}

    //Temporario para teste
    void imprimir(int id)
    {
        printf("\nID: %d", id);
        printf("\nX: %d", x);
        printf("\nY: %d", y);
        printf("\nVY: %d", vy);
        printf("\nComprimento: %d", comprimento);
    }
};

#endif