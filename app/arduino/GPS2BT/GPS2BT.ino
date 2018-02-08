/*
  AUTHOR: Hazim Bitar (techbitar)
  DATE: Aug 29, 2013
  LICENSE: Public domain (use at your own risk)
  CONTACT: techbitar at gmail dot com (techbitar.com)
  http://www.techbitar.com/modify-the-hc-05-bluetooth-module-defaults-using-at-commands.html
  Editor: Jimmy Hu
  DATE: Feb 8, 2018
*/
//***函式庫引用區***
#include  <SoftwareSerial.h>              //  引用<SoftwareSerial.h>函式庫
#include "cy_queue.c"

//***定義變數區***
#define Bluetooth_KEY 5
//  定義藍芽傳輸模組KEY接腳連接至arduino第5接腳
#define Bluetooth_RxD 7
//  定義藍芽傳輸模組RxD接腳連接至arduino第7接腳
#define Bluetooth_TxD 6
//  定義藍芽傳輸模組TxD接腳連接至arduino第6接腳
#define GPS_RxD 9
//  定義GPS模組RxD接腳連接至arduino第9接腳
#define GPS_TxD 8
//  定義GPS模組TxD接腳連接至arduino第8接腳
SoftwareSerial BTSerial(Bluetooth_TxD, Bluetooth_RxD);
//  建立軟體定義串列埠BTSerial，用以控制藍芽模組
SoftwareSerial GPSSerial(GPS_TxD, GPS_RxD);
//  建立軟體定義串列埠GPSSerial，用以控制GPS模組
cy_queue queue;

void setup()                             //  setup程式
{ //  進入setup程式
    cy_queue_init(&queue);
    //
    pinMode(Bluetooth_KEY, OUTPUT);
    //  設定arduino連接藍芽傳輸模組KEY之接腳為輸出
    digitalWrite(Bluetooth_KEY, HIGH);
    //  設定藍芽傳輸模組KEY接腳為HIGH(進入AT command模式)
    Serial.begin(9600);
    //  開啟 Serial Port透過USB(uart)方式與電腦通信，鮑率為 38400bps (Bits Per Second)
    BTSerial.begin(9600);
    //  設定控制HC-05藍芽模組之串列埠BTSerial鮑率為38400bps，此亦為HC-05藍芽模組預設鮑率
    GPSSerial.begin(9600);
}

void loop()
{
     delay(10);
     GPSSerial.listen();
     if (GPSSerial.available() > 0)
     {
          char GPSSerial_read;
          GPSSerial_read = GPSSerial.read();
          cy_queue_push(&queue, GPSSerial_read);
     }
     else {
          delay(10);
          while (!cy_queue_is_empty(&queue)) {
               BTSerial.write(cy_queue_pop(&queue));
          }
     }
     if (Serial.available())
     {
          char Serial_read;
          Serial_read = Serial.read();
          Serial.print(Serial_read);
          BTSerial.write(Serial_read);
     }
}
