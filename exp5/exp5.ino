#include<ESP8266WiFi.h>
#include "ThingSpeak.h"
int outputpin = A0;
WiFiClient client;
unsigned long myChannelNumber=2323252;
const char myWriteAPIKey[]="265WX6WTYNVGRX1A";
void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  WiFi.begin("Soham","iambatman");
  while(WiFi.status()!=WL_CONNECTED)
  { 
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("NodeMCU is Connected");
  Serial.println(WiFi.localIP());

  ThingSpeak.begin(client);
}

void loop()
{
  int analogValue = analogRead(outputpin);
  float millivolts = (analogValue/1024.0) * 3300; //3300 is the voltage provided by NodeMCU
  float celsius = millivolts/10;
  float fahrenheit = ((celsius * 9)/5 + 32);
  Serial.print("Degree Celsius=   ");
  Serial.println(celsius);
  Serial.print("Degree Farenheit=   ");
  Serial.println(fahrenheit);
  delay(1000);
  ThingSpeak.writeField(myChannelNumber,1,celsius,myWriteAPIKey);
  delay(1000);
  ThingSpeak.writeField(myChannelNumber,2,fahrenheit,myWriteAPIKey);
  delay(1000);
  // put your main code here, to run repeatedly:
}
