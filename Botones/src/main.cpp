#include <M5Core2.h>
void setup() {
  M5.begin();
  M5.Lcd.println("Please pressed Button A.");
}

void loop() {
  M5.update();
  if (M5.BtnA.wasPressed()) {    //If the key is pressed. 
    M5.Lcd.println("Button is pressed.");
  } 
  delay(20);
}