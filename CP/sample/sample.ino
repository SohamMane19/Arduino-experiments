#define BLYNK_TEMPLATE_ID "TMPL39lPL_Vf9"
#define BLYNK_TEMPLATE_NAME "LDR Notification"
#define BLYNK_AUTH_TOKEN "h9PnTEDJpAapUcZ3e0gyG5nHk6a9MDLi"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[]=BLYNK_AUTH_TOKEN;
const int ldrPin = A0;
const int led = D1;
int threshold = 100;


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth,"Soham","iambatman");
  pinMode(ldrPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  Blynk.run();
  // put your main code here, to run repeatedly:
  int rawData = analogRead(ldrPin);
  Serial.println(rawData);
  if (rawData < threshold)
  {
    digitalWrite(led,HIGH);
    Blynk.logEvent("ldr_alert","Take medicines");
  }
  else
  {
    digitalWrite(led,LOW);
  }
  delay(100);
}