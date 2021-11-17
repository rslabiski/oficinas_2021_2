#ifndef H_VEICULO
#define H_VEICULO

class Veiculo
{
  protected:
    float x;
    float y;
    float vx;
    float vy;
    int id;
    int comprimento;

  public:
    Veiculo(float xi, float yi, float vxi, float vyi, int comprimento, int ident);
    ~Veiculo();
    
    // Sets e gets
    void setX(float x) {this->x = x;}
    void setY(float y) {this->y = y;}
    void setVX(float vx) {this->vx = vx;}
    void setVY(float vy) {this->vy = vy;}
    void setComprimento(int comprimento) {this->comprimento = comprimento;}
    void setId(int id) {this->id = id;}
    float getX() {return x;}
    float getY() {return y;}
    float getVX() {return vx;}
    float getVY() {return vy;}
    int getComprimento() {return comprimento;}
    int getId() {return id;}

    virtual void mover() = 0;
    virtual int colide(); /* Em inimigos->verifica se pode ser colocado em certa posição
                             Em jogador->retorna o id da posição onde foi colocado para fazer tratamento de dano
                             e de exclusão de inimigo, quando necessário, ou reposicionar se bater na pista */
};

#endif
