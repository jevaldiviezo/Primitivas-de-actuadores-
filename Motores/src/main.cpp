#include <M5Core2.h>
const int in1=26;
const int in2=27;//adelante
const int in3=14;
const int in4=13;//adelante
int freqm= 100;
int ledChannelin1 = 1;
int ledChannelin2 = 2;
int ledChannelin3 = 3;
int ledChannelin4 = 4;
int resolution = 8;
void setup() {
  M5.begin();
    ledcSetup(ledChannelin1, freqm, resolution);
    ledcAttachPin(in1, ledChannelin1);
    ledcSetup(ledChannelin2, freqm, resolution);
    ledcAttachPin(in2, ledChannelin2);
    ledcSetup(ledChannelin3, freqm, resolution);
    ledcAttachPin(in3, ledChannelin3);
    ledcSetup(ledChannelin4, freqm, resolution);
    ledcAttachPin(in4, ledChannelin4);
  }

void loop() {
  ledcWrite(ledChannelin1, 0);
  delay(500);
  ledcWrite(ledChannelin2, 150);
  delay(500);
  ledcWrite(ledChannelin3, 0);
  delay(500);
  ledcWrite(ledChannelin4, 150);
  delay(500);
}