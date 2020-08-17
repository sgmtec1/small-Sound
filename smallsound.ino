// Open Source
// Trabalhando com Display LCD com I2C

#include <Wire.h> //INCLUSÃO DE BIBLIOTECA
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

#define pinoRele 7
#define pinoSom 4

bool rele;

void setup(){
  pinMode(pinoRele, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(pinoSom, INPUT); //DEFINE O PINO COMO ENTRADA

  rele=false;
  digitalWrite (pinoRele, rele);
  
  lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
  lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)

}

void loop(){
  Serial.print("COMANDO DE LUZ");
  lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
  lcd.print("COMANDO DE LUZ"); //IMPRIME O TEXTO NO DISPLAY LCD
  lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
  lcd.print("POR SOM"); //IMPRIME O TEXTO NO DISPLAY LCD

  if (digitalRead(pinoSom) == HIGH){ //SE A LEITURA DO PINO FOR IGUAL A HIGH, FAZ
      rele =! rele; //LÊ O ESTADO ATUAL DO PINO E ARMAZENA NA VARIÁVEL
  }
  digitalWrite(pinoRele, rele);
  
}
