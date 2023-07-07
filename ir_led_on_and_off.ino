#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_TEMPLATE_ID "TMPLjbx8_Ctw"
#define BLYNK_DEVICE_NAME "project1"
#define BLYNK_AUTH_TOKEN "CAClng3rOrq-5w-ns8TlOb_F-C6rHDag"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "xyz";
char pass[] = "12345678";

WidgetLED led(V0);
int ir=D1;
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  pinMode(ir,INPUT);
  
}
void loop()
{
  Blynk.run();
  int a=digitalRead(ir);
  Serial.println(a);
  if(a==0)
  {
     led.on();
     delay(100);
  }
  else
  {
    led.off();
    delay(100);
  }
  
}
