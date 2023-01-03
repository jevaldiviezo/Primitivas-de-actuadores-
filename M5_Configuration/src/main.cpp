//*************************************LIBRERIAS**********************
#include <M5Core2.h>
#include <ESP32MotorControl.h>
#include <WiFi.h>
#include "AudioFileSourceID3.h"
#include "AudioFileSourceSD.h"
#include "AudioGeneratorMP3.h"
#include "AudioOutputI2S.h"
#include "AXP192.h"
#include "driver/ledc.h"
#include "string.h"
//***********bluetooth**********
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

//***********************************BATERIA********************
//float voltage = M5.Axp.GetBatPower();
//*************************************IMU******************************

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
//************************************MOTOR*PWM***********************
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
//************************************SERVO***************************
const int servo=19;
int freq = 50;
int ledChannel = 0;
//int resolution = 8;
//*************************************SPEAKER************************
AudioGeneratorMP3 *mp3;
AudioFileSourceSD *file;
AudioOutputI2S *out;
AudioFileSourceID3 *id3;
//**********************************
void setup() {
    M5.begin();
    M5.IMU.Init();
    //********bluetooth******
    SerialBT.begin("Sumibot");
    //***************************************MOTOR*PWM**********************
    ledcSetup(ledChannelin1, freqm, resolution);
    ledcAttachPin(in1, ledChannelin1);
    ledcSetup(ledChannelin2, freqm, resolution);
    ledcAttachPin(in2, ledChannelin2);
    ledcSetup(ledChannelin3, freqm, resolution);
    ledcAttachPin(in3, ledChannelin3);
    ledcSetup(ledChannelin4, freqm, resolution);
    ledcAttachPin(in4, ledChannelin4);
    //***************************************SERVO**************************
    ledcSetup(ledChannel, freq, resolution);
    ledcAttachPin(servo, ledChannel);
    //**************************************SENSOR PROXIMIDAD***************
    pinMode(35,INPUT);
    pinMode(34,INPUT);
    //*******************************************SPEAKER*******************************
    file = new AudioFileSourceSD("/Sorprendido.mp3");
    id3  = new AudioFileSourceID3(file);
    out  = new AudioOutputI2S(0,2,8,0);  // Output to builtInDAC
    out->SetOutputModeMono(true);
    mp3 = new AudioGeneratorMP3();
    mp3->begin(id3, out);
    //*******************************************DISPLAY***************
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setBrightness(240);
    M5.Axp.SetLcdVoltage(3000);
    M5.Lcd.drawPngFile(SD, "/Artil2.png",100,65);

}
void loop() {
    //if (mp3->isRunning()) {if (!mp3->loop())mp3->stop();}
    int buttonA = M5.BtnA.read();
    Serial.println(buttonA);
    TouchPoint_t coordinate;
    coordinate = M5.Touch.getPressPoint();
    M5.Lcd.drawPngFile(SD, "/Artil2.png",100,65);
    if (coordinate.x>100 & coordinate.y>90 & coordinate.x<=220 & coordinate.y<=145)
    {
        M5.Lcd.fillRoundRect(20,20,50,50,10,GREENYELLOW);
        M5.Lcd.drawString("Asustado", 20, 35, 2);
        M5.Lcd.fillRoundRect(100,20,50,50,10,GREENYELLOW);
        M5.Lcd.drawString("Dormilon", 100, 35, 2);
        M5.Lcd.fillRoundRect(175,20,50,50,10,GREENYELLOW);
        M5.Lcd.drawString("Coqueto", 175, 35, 2);
        M5.Lcd.fillRoundRect(255,20,50,50,10,GREENYELLOW);
        M5.Lcd.drawString("Despertando", 245, 35, 2);
        M5.Lcd.fillRoundRect(20,90,50,50,10,GREENYELLOW);
        M5.Lcd.drawString("Enamorado", 15, 105, 2);
        M5.Lcd.fillRoundRect(255,90,50,50,10,GREENYELLOW);
        M5.Lcd.drawString("Enojado", 255, 105, 2);
        M5.Lcd.fillRoundRect(20,170,50,50,10,GREENYELLOW);
        M5.Lcd.drawString("Feliz", 25, 185, 2);
        M5.Lcd.fillRoundRect(100,170,50,50,10,GREENYELLOW);
        M5.Lcd.drawString("Molesto", 100, 185, 2);
        M5.Lcd.fillRoundRect(175,170,50,50,10,GREENYELLOW);
        M5.Lcd.drawString("Sorprendido", 165, 185, 2);
        M5.Lcd.fillRoundRect(255,170,50,50,10,GREENYELLOW);
        M5.Lcd.drawString("Triste", 260, 185, 2);
        delay(4000);
        M5.Lcd.fillScreen(BLACK);
        //M5.Lcd.drawPngFile(SD, "/Artil2.png",100,65);
        //M5.Lcd.drawPngFile(SD, "/Face_5.png",60,82);
        TouchPoint_t coordinate;
        coordinate = M5.Touch.getPressPoint();
        delay(500);
        //****************************ASUSTADO*******************************
        if (coordinate.x>20 & coordinate.y>20 & coordinate.x<=70 & coordinate.y<=70){
            delay(300);
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
        }
        //****************************DORMILON*******************************
        if (coordinate.x>100 & coordinate.y>20 & coordinate.x<=150 & coordinate.y<=70){
            delay(300);
            M5.Lcd.drawPngFile(SD, "/Face_15.png",60,82);
            delay(300);
            M5.Lcd.fillScreen(BLACK);
            M5.Lcd.drawPngFile(SD, "/Face_16.png",60,82);
            delay(300);
            M5.Lcd.fillScreen(BLACK);
            M5.Lcd.drawPngFile(SD, "/Artil2.png",100,65);
            delay(300);
        }
        //****************************COQUETO*******************************
        if (coordinate.x>175 & coordinate.y>20 & coordinate.x<=225 & coordinate.y<=70){
            delay(300);
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
        //****************************DESPERTANDO*******************************
        if (coordinate.x>255 & coordinate.y>20 & coordinate.x<=305 & coordinate.y<=70){
            delay(300);
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
        //****************************ENAMORADO*******************************
        if (coordinate.x>20 & coordinate.y>90 & coordinate.x<=70 & coordinate.y<=140){
            delay(300);
            M5.Lcd.drawPngFile(SD, "/Face_17.png",60,82);
            delay(300);
            M5.Lcd.fillScreen(BLACK);
            M5.Lcd.drawPngFile(SD, "/Face_25.png",60,82);
            delay(300);
            M5.Lcd.fillScreen(BLACK);
            M5.Lcd.drawPngFile(SD, "/Artil2.png",100,65);
            delay(300);
        }
        //****************************ENOJADO*******************************
        if (coordinate.x>255 & coordinate.y>90 & coordinate.x<=305 & coordinate.y<=140){
            delay(300);
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
        //****************************FELIZ*******************************
        if (coordinate.x>20 & coordinate.y>170 & coordinate.x<=70 & coordinate.y<=220){
            delay(300);
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
        //****************************MOLESTO*******************************
        if (coordinate.x>100 & coordinate.y>170 & coordinate.x<=150 & coordinate.y<=220){
            delay(300);
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
        //****************************SORPRENDIDO*******************************
        if (coordinate.x>175 & coordinate.y>170 & coordinate.x<=225 & coordinate.y<=220){
            delay(300);
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
        //****************************TRISTE*******************************
        if (coordinate.x>255 & coordinate.y>170 & coordinate.x<=305 & coordinate.y<=220){
            delay(300);
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
    
    //************************************MOTOR*****************
    if (digitalRead(34)==1){
        ledcWrite(ledChannelin1, 0);
        delay(500);
        ledcWrite(ledChannelin2, 150);
        delay(500);
        ledcWrite(ledChannelin3, 0);
        delay(500);
        ledcWrite(ledChannelin4, 150);
        delay(500);
    }
    if (digitalRead(34)==0){
        ledcWrite(ledChannelin1, 0);
        delay(500);
        ledcWrite(ledChannelin2, 150);
        delay(500);
        ledcWrite(ledChannelin4, 0);
        delay(500);
        ledcWrite(ledChannelin3, 150);
        delay(2000);
        //*********************************servo
        /*ledcWrite(ledChannel, 18);//90°
        delay(500);
        ledcWrite(ledChannel, 6);//180°
        delay(500);*/
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Face_13.png",60,106);
        delay(400);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Face_14.png",60,81);
        delay(400);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.drawPngFile(SD, "/Face_1.png",60,93);
        delay(400);
        M5.Lcd.fillScreen(BLACK);
    }
    if (digitalRead(35)==0){
        if (mp3->isRunning()) {if (!mp3->loop())mp3->begin(id3, out);}
        ledcWrite(ledChannelin2, 0);
        delay(500);
        ledcWrite(ledChannelin1, 150);
        delay(500);
        ledcWrite(ledChannelin3, 150);
        delay(500);
        ledcWrite(ledChannelin4, 0);
        delay(500);
    }
    M5.IMU.getGyroData(&gyroX, &gyroY, &gyroZ);
    M5.IMU.getAccelData(&accX, &accY,&accZ);  //Stores the triaxial accelerometer.  存储三轴加速度计数据
    M5.IMU.getAhrsData(&pitch, &roll,&yaw);  //Stores the inertial sensor attitude.  存储惯性传感器的姿态
    M5.IMU.getTempData(&temp);
    //Serial.println(accY);
    delay(1000);
    if(accY<=0.60){
        //**********************MOLESTO****************/ SE CAE
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
        //****************** SE LEVANTA CON SERVO
        ledcWrite(ledChannel, 30);//180°
        delay(500);
        ledcWrite(ledChannel, 22);//0°
        delay(500);
    }
    if(accZ<=-0.10){
        //**********************ASUSTADO****************/ SE CAE ADELANTE
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
        /****************** SE LEVANTA CON SERVO
        ledcWrite(ledChannel, 30);//180°
        delay(2000);
        ledcWrite(ledChannel, 20);//0°
        delay(500);*/
    }
//******************************BLUETOOTH
    if (SerialBT.available())
    {
        char ch=SerialBT.read();
        if (ch=='Asustado'|| ch=='asustado')
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
        if (ch=='Dormilon'|| ch=='dormilon')
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
        if (ch=='Coqueto'|| ch=='coqueto')
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
        if (ch=='Despertando'|| ch=='despertando')
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
        if (ch=='Enamorado'|| ch=='enamorado')
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
        if (ch=='Enojado'|| ch=='enojado')
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
        if (ch=='Feliz'|| ch=='feliz')
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
        if (ch=='Molesto'|| ch=='molesto')
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
        if (ch=='Sorprendido'|| ch=='sorprendido')
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
        if (ch=='Triste'|| ch=='triste')
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