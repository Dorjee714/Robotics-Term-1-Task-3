#include <Wire.h>
#include <LiquidCrystal_I2C.h>
long randNumber;


LiquidCrystal_I2C lcd(0x27, 16, 2);

const int btn = 7;
const int reedSwitch1 = A0;
const int reedSwitch2 = A1;
const int reedSwitch3 = A2;
const int reedSwitch4 = A3;
const int led1 = 13;
const int led2 = 12;
const int led3 = 4;
const int led4 = 2;

void setup() {
  lcd.begin();
  lcd.backlight();

  pinMode(btn, INPUT_PULLUP);
  Serial.begin(9600);

  randomSeed(analogRead(0));

  pinMode(reedSwitch1, INPUT_PULLUP);
  pinMode(reedSwitch2, INPUT_PULLUP);
  pinMode(reedSwitch3, INPUT_PULLUP);
  pinMode(reedSwitch4, INPUT_PULLUP);

}
void loop() {

int btnValue = digitalRead(btn);
int reedValue1 = digitalRead(reedSwitch1);
int reedValue2 = digitalRead(reedSwitch2);
int reedValue3 = digitalRead(reedSwitch3);
int reedValue4 = digitalRead(reedSwitch4);
randNumber = random(1,6);

if (btnValue == HIGH) {
    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.print(randNumber);
    delay(1500);
 }else if(btnValue == LOW){
   lcd.setCursor(0, 0);
   lcd.clear();
   delay(10);
   lcd.print("Waiting...     ");
   delay(500);
 }else{
  lcd.clear();
 }

if (reedValue1 == LOW) {
    digitalWrite(led1, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Red Token ");
    lcd.setCursor(0, 1);
    lcd.print("Reached Home!");
    delay(500);
  }
  else if (reedValue2 == LOW){
    digitalWrite(led2, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Green Token ");
    lcd.setCursor(0, 1);
    lcd.print("Reached Home!");
    delay(500);
  }
 else if (reedValue3 == LOW){
    digitalWrite(led3, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Yellow Token ");
    lcd.setCursor(0, 1);
    lcd.print("Reached Home!");
    delay(500);
 }
 else if (reedValue4 == LOW){
    digitalWrite(led4, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Blue Token ");
    lcd.setCursor(0, 1);
    lcd.print("Reached Home!");
    delay(500);
 }
 else{
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
        
 }

}
