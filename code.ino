#include <LiquidCrystal.h> //LCD library 
#define trigPin 7
#define echoPin 6
#define buzzerPin 8
int time;
int distance;
int rs=12, en=11, d4=5 ,d5=4 ,d6=3 ,d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


void setup() {
  pinMode(buzzerPin,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  lcd.begin(16,2);

}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  time=pulseIn(echoPin,HIGH,11600); 
  distance=time*0.0345/2;   // prosses is convertion of the distance.
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("distance:");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print("cm");

  if(distance<=5){
    digitalWrite(buzzerPin,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("DANGER");
  }
  if(distance>5){
    digitalWrite(buzzerPin,LOW);
  }

}
