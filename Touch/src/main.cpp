#include <M5Core2.h>

void setup() {
    M5.begin();
}

void loop() {
    TouchPoint_t coordinate;
    coordinate = M5.Touch.getPressPoint();
    Serial.printf("x:%d, y:%d \r\n", coordinate.x, coordinate.y);
}