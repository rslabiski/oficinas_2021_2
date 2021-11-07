#ifndef H_VEICULO
#define H_VEICULO

#include <stdio.h>

class Veiculo
{
protected:
    int x;
    int y;
    int v;
    int id;
    int comprimento;

public:
    Veiculo(int xi, int yi, int vxi, int comprimento);
    ~Veiculo();

    void inicializar(int xi, int yi, int v);

    virtual void mover() = 0;
    
    void setCoordenadas(int x, int y) { this->x = x; this->y = y;}
    void setVelocidade(int vy) {this->v = v;}
    void setComprimento(int c) {this->comprimento = c;}

    int getCoordenadaX() {return x;}
    int getCoordenadaY() {return y;}
    int getVelocidade() {return v;}
    int getComprimento() {return comprimento;}

    int getIdentificador(){ return id; }

};

#endif