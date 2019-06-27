#include "EmonLib.h"
#include <DHT.h>
#include <DS1302.h>
#include <SD.h>
#include <SPI.h>
File myFile;
DS1302 rtc(8,7,6);
Time t;
int pinCS = 10;
int contador = 0;
EnergyMonitor energyMonitor;
DHT dht(4, DHT11);
void setup()
{
delay(1000);
Serial.begin(9600);
pinMode(pinCS,OUTPUT);
if(SD.begin()){
    Serial.println("contador,fecha,hora,corriente,temperatura,radiacion");
  }
  else{
    Serial.print("SD card no pudo iniciar correctamente");
    return;
  }
energyMonitor.current(0, 100);
dht.begin();
}
void loop()
{
  contador = contador+1;
  t = rtc.getTime();
  myFile=SD.open("es_7.txt", FILE_WRITE);
  if(contador==1){
    myFile.println("contador,fecha,hora,corriente,temperatura,radiacion");
  }
double Irms = energyMonitor.calcIrms(1484);

  myFile.print(contador);
  myFile.print(",");
  myFile.print(t.date);
  myFile.print("-");
  myFile.print(t.mon,DEC);
  myFile.print("-");
  myFile.print(t.year);
  myFile.print(",");
  myFile.print(t.hour);
  myFile.print(":");
  myFile.print(t.min);
  myFile.print(":");
  myFile.print(t.sec);
  myFile.print(",");
  myFile.print(Irms*1000);
  myFile.print(",");
  myFile.print(dht.readHumidity());
  myFile.print(",");
  myFile.print(dht.readTemperature());
  myFile.print(",");
  myFile.println(analogRead(A1));
  myFile.close();
Serial.print(contador);
Serial.print(",");
Serial.print(t.date);
Serial.print("-");
Serial.print(t.mon,DEC);
Serial.print("-");
Serial.print(t.year);
Serial.print(",");
Serial.print(t.hour);
Serial.print(":");
Serial.print(t.min);
Serial.print(":");
Serial.print(t.sec);
Serial.print(",");
Serial.print(Irms*1000);
Serial.print(",");
Serial.print(dht.readHumidity());
Serial.print(",");
Serial.print(dht.readTemperature());
Serial.print(",");
Serial.println(analogRead(A1));
delay(1000);
}
