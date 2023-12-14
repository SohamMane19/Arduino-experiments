#define BLYNK_TEMPLATE_ID "TMPL3Y5Hqs0fQ"
#define BLYNK_TEMPLATE_NAME "medicine"
#define BLYNK_AUTH_TOKEN "0n36v5e0Hoor7Ox74l-rfl4Oc8TmviZ2"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[]=BLYNK_AUTH_TOKEN;
const int ldrPin = A0;
const int led = D1;
int threshold = 150;
bool flag = false;

void setup()
{
  // put your setup code here, to run once:
  // In general, the resistance of an LDR decreases as the light intensity increases and vice versa.
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
  if(flag)
  {
    delay(10000);
    flag = false;
  }
  if (rawData > threshold)
  {
    flag = true;
    digitalWrite(led,HIGH);
    Blynk.logEvent("medicine_alert","Take medicines");
  }
  else
  {
    digitalWrite(led,LOW);
  }
  delay(100);
}