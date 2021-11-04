#ifndef H_MATRIZ_LED
#define H_MATRIZ_LED

class MatrizLED
{
public:
    MatrizLED();
    ~MatrizLED();

    void reset();
    void renderizar(); //Renderiza os elementos de acordo com a matriz do jogo
};

#endif