#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int umidade=0;
int led= 10;
int buzzer= 9;
int motorcc=7;
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  pinMode(motorcc,OUTPUT);
  lcd.begin(16,2);
}
void loop()
{
  digitalWrite(A0, HIGH);
  delay(10);
  umidade= analogRead(A1);
  digitalWrite(A0, LOW);
  Serial.println(umidade);
  if(umidade<600){
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(200);
    digitalWrite(motorcc, HIGH);
   for(int i=1;i<=3;i++)
   {
      digitalWrite(buzzer, HIGH);
      lcd.print("Umidade Baixa");
      delay(1000);
      digitalWrite(buzzer, LOW);
      lcd.clear();
      delay(1000);
    }
  }if(umidade>=600){
    digitalWrite(motorcc, LOW);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    for(int a=1;a<=3;a++)
    {
      lcd.print("Umidade OK!");
      delay(1000);
      lcd.clear();
      delay(1000);
    }
  }
}
