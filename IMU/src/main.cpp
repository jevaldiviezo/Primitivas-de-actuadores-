#include <M5Core2.h>

float accX = 0.0F;  
float accY = 0.0F;  
float accZ = 0.0F;

float gyroX = 0.0F;
float gyroY = 0.0F;
float gyroZ = 0.0F;

float pitch = 0.0F;
float roll = 0.0F;
float yaw = 0.0F;

float temp = 0.0F;

void setup() {
  M5.begin();    
  M5.IMU.Init(); 
  M5.Lcd.fillScreen(
      BLACK);
  M5.Lcd.setTextColor(GREEN,BLACK);  
  M5.Lcd.setTextSize(2); 
}

void loop() {
  M5.IMU.getGyroData(&gyroX, &gyroY, &gyroZ);
  M5.IMU.getAccelData(&accX, &accY,&accZ);
  M5.IMU.getAhrsData(&pitch, &roll,&yaw);  
  M5.IMU.getTempData(&temp);
  M5.Lcd.setCursor(0, 20); 
  M5.Lcd.printf("gyroX,  gyroY, gyroZ"); 
  M5.Lcd.setCursor(0, 42);
  M5.Lcd.printf("%6.2f %6.2f%6.2f o/s", gyroX, gyroY, gyroZ);

  M5.Lcd.setCursor(0, 70);
  M5.Lcd.printf("accX,   accY,  accZ");
  M5.Lcd.setCursor(0, 92);
  M5.Lcd.printf("%5.2f  %5.2f  %5.2f G", accX, accY, accZ);

  M5.Lcd.setCursor(0, 120);
  M5.Lcd.printf("pitch,  roll,  yaw");
  M5.Lcd.setCursor(0, 142);
  M5.Lcd.printf("%5.2f  %5.2f  %5.2f deg", pitch, roll, yaw);
  M5.Lcd.setCursor(0, 175);
  M5.Lcd.printf("Temperature : %.2f C", temp);

  delay(10);  
}