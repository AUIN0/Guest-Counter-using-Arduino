#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the library with the I2C address and dimensions of the display
LiquidCrystal_I2C lcd(0x27, 16, 2);

int IR1 = 2;
int slot = 1;

void setup() {
  lcd.init();
  lcd.backlight();  // Turn on the backlight
  pinMode(IR1, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(IR1) == HIGH) {
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
    else if(digitalRead(IR1)==LOW){
      lcd.print(slot);
    }
    delay(5000);
  }
}
