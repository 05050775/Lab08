#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int trig = 7;
const int echo = 6;
int inter_time = 1000;
int time = 0;

void setup() {
  Serial.begin(9600);  
  lcd.begin(16, 2);
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
}

void loop() {
  float duration, distance;
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);
  duration = pulseIn (echo, HIGH);
  distance = (duration/50);
  lcd.setCursor (0,0);
  lcd.print("Data No.");
  lcd.print (time);
  time = time +1;
  lcd.setCursor(0, 1);  
  lcd.print ("Distance:");   
  lcd.print(distance);
  lcd.print ("cm");
  delay(900);
  lcd.clear();
  delay(100); 
}
