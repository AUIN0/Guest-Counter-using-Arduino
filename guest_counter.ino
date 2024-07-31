#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int PIR = 2;
int slot = 1;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(PIR, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(PIR) == HIGH) {
    if (slot > 0) {
      slot++;
      lcd.setCursor(0, 0);
      lcd.print("  WELCOME  ");
      lcd.setCursor(0, 1);
      lcd.print(" Guest: ");
      lcd.print(slot);
      Serial.print("Detected: ");
      Serial.println(slot);
    }
    else if(digitalRead(PIR)==LOW){
      lcd.print(slot);
    }
    delay(5000);
  }
}
