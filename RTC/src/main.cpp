#include <M5Core2.h>

RTC_DateTypeDef DateStruct;
void setup() {
  M5.begin();
  M5.Lcd.println("RTC Date TEST");
  DateStruct.WeekDay = 5;
  DateStruct.Month = 1;
  DateStruct.Date = 3;
  DateStruct.Year = 2023;
  M5.Rtc.SetDate(&DateStruct);
}

void loop() {
  M5.Rtc.GetDate(&DateStruct);    //Get the date of the real-time clock. 
  M5.Lcd.setCursor(0, 15);
  M5.Lcd.printf("Data: %04d-%02d-%02d/n",DateStruct.Year, DateStruct.Month,DateStruct.Date);    //Output the date of the current real-time clock on the screen. 
  M5.Lcd.printf("Week: %d/n",DateStruct.WeekDay);
  delay(500);
}
