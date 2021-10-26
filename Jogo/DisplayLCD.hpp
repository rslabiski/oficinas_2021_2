#ifndef H_DISPLAY_LCD
#define H_DISPLAY_LCD

class DisplayLCD
{
public:
    DisplayLCD();
    ~DisplayLCD();

    void reset();
    void renderizar(); //RENDERIZA O JOGO DE ACORDO COM O PLAYER e TEMPO
};

#endif