#include  "Veiculo.hpp"

Veiculo::Veiculo(int xi, int yi, int vxi, int comprimento) {
    inicializar(xi,yi,vxi);
    setComprimento(comprimento);
    visivel = true;
}

Veiculo::~Veiculo() {

}

void Veiculo::inicializar(int xi, int yi, int v) {
    setCoordenadas(xi, yi);
    setVelocidade(v);
    setComprimento(comprimento);
}