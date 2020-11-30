# code-lua
 Primeiro repositório 
#include<LiquidCrystal.h>
const int rs = 8;
const int e = 9;
const int d4 = 4;
const int d5 = 5;
const int d6 = 6;
const int d7 = 7;
LiquidCrystal lcd (rs, e, d4, d5, d6, d7);

//**************DECLARAÇÃO DAS VARIÁVEIS*************
bool posicao = 0;
bool ledA = 0;
bool ledB = 0;
int valorAnterior = 1023;


void setup()
{
  lcd.begin(16, 2); //inicia o display
  lcd.home();
  lcd.print ("> LED A OFF");
  lcd.setCursor(0, 1);
  lcd.print ("  LED B OFF");

  pinMode (22, OUTPUT);
  pinMode (26, OUTPUT);
}

void loop()
{


  //************TRATAMENTO DOS BOTÕES***************
  int valor = analogRead(A0); //A (ZER0)

  if (valor > 100 && valor < 200) //botão cima
  {
    posicao = 0;
  }
  if (valor > 300 && valor < 400) //botão baixo
  {
    posicao = 1;
  }
  if (valor > 700 && valor < 800 && valorAnterior > 1000) //botão SELECT
  {
    if (posicao == 0)
    {
      ledA = !ledA;
    }
    if (posicao == 1)
    {
      ledB = !ledB;
    }
  }
  valorAnterior = valor;

  //***************FIM DO TRATAMENTO*************


  //************INDICAÇÃO DAS LINHAS*************
  if (posicao == 0)
  {
    lcd.home();
    lcd.print (">");
    lcd.setCursor(0, 1);
    lcd.print (" ");
  }
  if (posicao == 1)
  {
    lcd.setCursor(0, 1);
    lcd.print (">");
    lcd.home();
    lcd.print (" ");
  }
  //********STATUS DO LED NO DISPLAY**************
  if (ledA == LOW)
  {
    lcd.setCursor (8, 0);
    lcd.print("OFF");
  }
  else
  {
    lcd.setCursor (8, 0);
    lcd.print("ON ");
  }
  if (ledB == LOW)
  {
    lcd.setCursor (8, 1);
    lcd.print("OFF");
  }
  else
  {
    lcd.setCursor (8, 1);
    lcd.print("ON ");
  }

  //****************ATUALIZA OS LEDS***************
  digitalWrite(22, ledA);
  digitalWrite(26, ledB);

}
