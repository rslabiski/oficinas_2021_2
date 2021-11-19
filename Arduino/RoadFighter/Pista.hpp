#ifndef PISTA_H
#define PISTA_H

class Pista
{
private:
    int xi;
    int xf;
    int yi; // 0 Leds
    int yf; // 50 Leds (50 - 0) = 50 LEDS

public:
    Pista(int xi = 0, int xf = 7, int yi = 0, int yf = 15);
    ~Pista();

    int getXi() {return this->xi;}
    int getXf() {return this->xf;}
    int getYi() {return this->yi;}
    int getYf() {return this->yf;}
    int getTamanho(){ return this->getYf - this->getYi; }
};

#endif
