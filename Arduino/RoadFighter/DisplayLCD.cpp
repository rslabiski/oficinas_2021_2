#include "DisplayLCD.hpp"

DisplayLCD::DisplayLCD() :
  LiquidCrystal_I2C(DISP_ENDERECO, DISP_COLUNAS, DISP_LINHAS)
{

}

DisplayLCD::~DisplayLCD()
{

}

void DisplayLCD::Setup()
{
  init(); // Inicializa
  backlight(); // Liga luz do Fundo
  clear(); // Limpa a tela
}

void DisplayLCD::imprimeCentralizado(String texto, int linha)
{
  int qntLetras = texto.length();
  String textoFinal = "";
  int qntVazio = (16 - qntLetras) / 2;

  setCursor(0, linha);

  if (qntLetras > 16)
    imprimeCentralizado("QNT LETRAS >16", linha);
  else {
    for (int i = 0; i < qntVazio; i++) {
      textoFinal += " ";
    }
    textoFinal += texto;

    for (int i = qntVazio + qntLetras - 1; i < 16; i++) {
      textoFinal += " ";
    }
    print(textoFinal);
  }
}

void DisplayLCD::imprimeStatusFase(int pontos, int segundos, float progressoCorrida)
{
  int progressoCheio;

  //Imprime pontuacao
  setCursor(0, 0);
  print("Pts:    ");
  setCursor(4, 0);
  print(pontos);

  //Imprime tempo
  setCursor(8, 0);
  print("Tmp:    ");

  setCursor(12, 0);
  if (segundos > 999)
    print(999);
  else
    print(segundos);

  if (segundos > 99)
    setCursor(15, 0);
  else if (segundos > 9)
    setCursor(14, 0);
  else
    setCursor(13, 0);
  print("s");

  //Imprime progresso
  setCursor(0, 1);

  progressoCheio = 16 * progressoCorrida;

  if (progressoCheio > 16)
    progressoCheio = 16;

  for (int i = 0; i < progressoCheio; i++)
    print(char(255));
  for (int i = progressoCheio; i < 16; i++)
    print(" ");
}
