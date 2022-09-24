// C++ code

//Inclusao da biblioteca
#include <Adafruit_NeoPixel.h>

//Pino de dados da fita
#define PIN 5

//Número de leds na fita
#define NUM_LEDS 6

//Potenciometro para controle de tempo
#define POTENCIOMETRO A0

//Botao para definir funcao
#define BOTAO 2

Adafruit_NeoPixel pixels(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

//Criacao da variavel de tempo que sera controlada pelo potenciometro
float TEMPO1 = 0;

//Variáveis das cores RGB
int COLOR_R = 0;
int COLOR_G = 0;
int COLOR_B = 0;

void setup()
{
  pixels.begin();
  pixels2.begin();
  pinMode(POTENCIOMETRO, INPUT); //Configura pino como "entrada" de sinal
  pinMode(BOTAO, INPUT); //Configura pino como "entrada" de sinal
  pinMode(PIN, OUTPUT); //Configura pino como "saida"
}

//Escolha aleatória de cores
void SET_COLOR()
{
  COLOR_R = random(0,255);
  COLOR_G = random(0,255);
  COLOR_B = random(0,255);
}

void loop()
{
  pixels.clear();
  SET_COLOR();
  TEMPO1 = map(analogRead(POTENCIOMETRO),0,1023,1000,50); //Transforma o valor de entrada do potenciometro para o minimo (lento) de 1s e maximo (rapido) de 0,05s
  if(digitalRead(2) == LOW)
  {
    for(int i=0;i<NUM_LEDS;i++) //Laco para acendimento de cada LED
      {
       pixels.setPixelColor(i,pixels.Color(COLOR_R, COLOR_G, COLOR_B)); //pixels.Color inclui valores de 0 a 255 para o RGB
       pixels.show();
       delay(TEMPO1); //Tempo de acendimento entre cada LED
       if(i==NUM_LEDS)
         {
         i=0;
         SET_COLOR();
         }
       }
  }
  else
  {
    for(int i=0;i<NUM_LEDS;i++) //Laco para acendimento de cada LED
      {
       pixels.setPixelColor(0,pixels.Color(255, 0, 0)); //Vermelho no LED 1
       pixels.show();
       delay(TEMPO1); //Tempo de acendimento entre cada LED
       pixels.setPixelColor(1,pixels.Color(0, 255, 0)); //Verde no LED 2
       pixels.show();
       delay(TEMPO1); //Tempo de acendimento entre cada LED
       pixels.setPixelColor(2,pixels.Color(0, 0, 255)); //Azul no LED 3
       pixels.show();
       delay(TEMPO1); //Tempo de acendimento entre cada LED
       pixels.setPixelColor(3,pixels.Color(255, 0, 0)); //Vermelho no LED 4
       pixels.show();
       delay(TEMPO1); //Tempo de acendimento entre cada LED
       pixels.setPixelColor(4,pixels.Color(0, 255, 0)); //Verde no LED 5
       pixels.show();
       delay(TEMPO1); //Tempo de acendimento entre cada LED
       pixels.setPixelColor(5,pixels.Color(0, 0, 255)); //Azul no LED 6
       pixels.show();
       delay(TEMPO1); //Tempo de acendimento entre cada LED
       pixels.clear();
       if(i==NUM_LEDS)
         {
         i=0;
         SET_COLOR();
       }
    }
  }
}