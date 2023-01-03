#include <M5Core2.h>
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
void setup() {
    M5.begin();
    SerialBT.begin("Sumibot");}

void loop() {
  if (SerialBT.available())
  {
    char ch=SerialBT.read();
    if (ch=='A'|| ch=='a')
    {
    M5.Lcd.drawPngFile(SD, "/Face_21.png",60,82);
    delay(300);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.drawPngFile(SD, "/Face_22.png",60,82);
    delay(300);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.drawPngFile(SD, "/Face_23.png",60,82);
    delay(300);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.drawPngFile(SD, "/Face_24.png",60,82);
    delay(300);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.drawPngFile(SD, "/Artil2.png",100,65);
    delay(300);
    //if (mp3->isRunning()) {if (!mp3->loop())mp3->begin(id3, out);}}
    } 
    if (ch=='B'|| ch=='b')
    {
        M5.Lcd.drawPngFile(SD, "/Face_15.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Face_16.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Artil2.png",100,65);
        delay(300);
    }
    if (ch=='C'|| ch=='c')
    {
        M5.Lcd.drawPngFile(SD, "/Face_1.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Face_3.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Face_5.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Artil2.png",100,65);
        delay(300);
    }
    if (ch=='D'|| ch=='d')
    {
        M5.Lcd.drawPngFile(SD, "/Face_13.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Face_14.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Face_1.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Artil2.png",100,65);
        delay(300);
    }
    if (ch=='E'|| ch=='e')
    {
        M5.Lcd.drawPngFile(SD, "/Face_17.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Face_25.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Artil2.png",100,65);
        delay(300);
    }
    if (ch=='F'|| ch=='f')
    {
        M5.Lcd.drawPngFile(SD, "/Face_12.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Face_10.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Face_9.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Face_11.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Artil2.png",100,65);
        delay(300);
    }
    if (ch=='G'|| ch=='g')
    {
        M5.Lcd.drawPngFile(SD, "/Face_1.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Face_3.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Face_14.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Artil2.png",100,65);
        delay(300);
    }
    if (ch=='H'|| ch=='h')
    {
    M5.Lcd.drawPngFile(SD, "/Face_7.png",60,82);
    delay(300);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.drawPngFile(SD, "/Face_4.png",60,82);
    delay(300);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.drawPngFile(SD, "/Face_18.png",60,82);
    delay(300);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.drawPngFile(SD, "/Artil2.png",100,65);
    delay(300);
    }
    if (ch=='I'|| ch=='i')
    {
        M5.Lcd.drawPngFile(SD, "/Face_7.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Face_4.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Face_6.png",60,82);
        delay(300);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Artil2.png",100,65);
        delay(300);
    }
    if (ch=='J'|| ch=='j')
      {
          M5.Lcd.drawPngFile(SD, "/Face_7.png",60,82);
          delay(300);
          M5.Lcd.fillScreen(BLACK);
          M5.Lcd.drawPngFile(SD, "/Face_2.png",60,82);
          delay(300);
          M5.Lcd.fillScreen(BLACK);
          M5.Lcd.drawPngFile(SD, "/Face_8.png",60,82);
          delay(300);
          M5.Lcd.fillScreen(BLACK);
          M5.Lcd.drawPngFile(SD, "/Artil2.png",100,65);
          delay(300);
      }
  }
}