#include  "Veiculo.hpp"

Veiculo::Veiculo(int xi, int yi, int vxi, int vyi, int comprimento) {
    inicializar(xi,yi,vxi,vyi);
    setComprimento(comprimento);
    visivel = true;
}

Veiculo::~Veiculo() {

}

void Veiculo::inicializar(int xi, int yi, int vxi, int vyi) {
    setX(xi);
    setY(yi);
    setVX(vxi);
    setVY(vyi);
    setComprimento(comprimento);
}