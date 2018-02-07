/*
  AUTHOR: Hazim Bitar (techbitar)
  DATE: Aug 29, 2013
  LICENSE: Public domain (use at your own risk)
  CONTACT: techbitar at gmail dot com (techbitar.com)
  http://www.techbitar.com/modify-the-hc-05-bluetooth-module-defaults-using-at-commands.html
  Editor: Jimmy Hu
  DATE: Oct 30, 2016
*/
//***函式庫引用區***
#include  <SoftwareSerial.h>              //  引用<SoftwareSerial.h>函式庫
//***定義變數區***
#define Bluetooth_KEY 5
//  定義藍芽傳輸模組KEY接腳連接至arduino第接腳
#define Bluetooth_RxD 9
//  定義藍芽傳輸模組RxD接腳連接至arduino第9接腳
#define Bluetooth_TxD 6
//  定義藍芽傳輸模組TxD接腳連接至arduino第8接腳
#define GPS_RxD 11
//  定義GPS模組RxD接腳連接至arduino第11接腳
#define GPS_TxD 10
//  定義GPS模組TxD接腳連接至arduino第10接腳
SoftwareSerial BTSerial(Bluetooth_TxD, Bluetooth_RxD);
//  建立軟體定義串列埠BTSerial，用以控制藍芽模組
SoftwareSerial GPSSerial(GPS_TxD, GPS_RxD);
//  建立軟體定義串列埠GPSSerial，用以控制GPS模組

void setup()                             //  setup程式
{ //  進入setup程式
  pinMode(Bluetooth_KEY, OUTPUT);
  //  設定arduino連接藍芽傳輸模組KEY之接腳為輸出
  digitalWrite(Bluetooth_KEY, HIGH);
  //  設定藍芽傳輸模組KEY接腳為HIGH(進入AT command模式)
  Serial.begin(9600);
  //  開啟 Serial Port透過USB(uart)方式與電腦通信，鮑率為 38400bps (Bits Per Second)
  BTSerial.begin(9600);
  //  設定控制HC-05藍芽模組之串列埠BTSerial鮑率為38400bps，此亦為HC-05藍芽模組預設鮑率
  GPSSerial.begin(9600);
}                                      //  結束setup程式
void loop()                              //  loop程式
{
  if (GPSSerial.available())
  {
    char GPSSerial_read;
    GPSSerial_read = GPSSerial.read();
    //BTSerial.write(GPSSerial_read);
    Serial.write(GPSSerial_read);
  }                                    //  結束if敘述
  if (Serial.available())
  {
    char Serial_read;
     Serial_read = Serial.read();
     Serial.print(Serial_read);
     BTSerial.write(Serial_read);
  }                                    //  結束if敘述
}                                      //  結束loop程式
