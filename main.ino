#include <Wire.h>
#include <LiquidCrystal_I2C.h>
long diceValue;


LiquidCrystal_I2C lcd(0x27, 16, 2);

const int btn = 7;
int buttonState = HIGH;
int lastButtonState = digitalRead(btn);;

const int buzzer = 8;

const int reed1 = A0;
const int reed2 = A1;
const int reed3 = A2;
const int reed4 = A3;

const int LED1 = 13;
const int LED2 = 12;
const int LED3 = 4;
const int LED4 = 2;

int currentPlayer = 1;

void setup() {

  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();

  pinMode(btn, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  

  randomSeed(analogRead(0));

  pinMode(reed1, INPUT_PULLUP);
  pinMode(reed2, INPUT_PULLUP);
  pinMode(reed3, INPUT_PULLUP);
  pinMode(reed4, INPUT_PULLUP);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("Electronic");
  lcd.setCursor(0, 1);
  lcd.print("Ludo Game");

  delay(5000);

  displayTurn();

}

void loop() {

  buttonState = digitalRead(btn);

  if (lastButtonState == HIGH && buttonState == LOW) {
    delay(50);
    rollDice();
    delay(2000);
    nextPlayer();
  }

  lastButtonState = buttonState;

  checkHomeSensors();
}

void rollDice(){
  diceValue = random(1,7);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Player ");
  lcd.print(currentPlayer);

  lcd.setCursor(0, 1);
  lcd.print("Dice: ");
  lcd.print(diceValue);

  tone(buzzer, 2500);
  delay(100);

  tone(buzzer, 2700);
  delay(100);

  noTone(buzzer);

  delay(1500);
}

void nextPlayer() {
  currentPlayer++;

  if (currentPlayer > 4){
    currentPlayer = 1;
  }

  displayTurn();
}

void displayTurn() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Player ");
  lcd.print(currentPlayer);
  lcd.print("'S");

  lcd.setCursor(0, 1);
  lcd.print("Turn");
}
void checkHomeSensors() {
  if (digitalRead(reed1) == LOW) {

    digitalWrite(LED1, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Player 1");

    lcd.setCursor(0, 1);
    lcd.print("Reached Home!");

    victorySound();

    delay(200);
  }else if (digitalRead(reed2) == LOW) {

    digitalWrite(LED2, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Player 2");

    lcd.setCursor(0, 1);
    lcd.print("Reached Home!");

    victorySound();

    delay(200);
  }else if (digitalRead(reed3) == LOW) {

    digitalWrite(LED3, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Player 3");

    lcd.setCursor(0, 1);
    lcd.print("Reached Home!");

    victorySound();

    delay(200);
  }else if (digitalRead(reed4) == LOW) {

    digitalWrite(LED4, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Player 4");

    lcd.setCursor(0, 1);
    lcd.print("Reached Home!");

    victorySound();

    delay(200);
  }else{ 
     digitalWrite(LED1, LOW);
     digitalWrite(LED2, LOW);
     digitalWrite(LED3, LOW);
     digitalWrite(LED4, LOW);
     delay(50);
     displayTurn();
  }
  
}
void victorySound() {
  tone(buzzer, 2000);
  delay(150);

  tone(buzzer, 2200);
  delay(150);

  tone(buzzer, 2500);
  delay(200);

  noTone(buzzer);
}
