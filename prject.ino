
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<DHT.h>
#define BLYNK_TEMPLATE_ID "TMPLL5Izfrym"
#define BLYNK_DEVICE_NAME "project2"
#define BLYNK_AUTH_TOKEN "gefpuKTVThk7QinjLDxKWYdlSZJtwwPQ"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "def";
char pass[] = "12345678";

WidgetLED led(V0);
int ir=D1,rel1=D3,rel2=D4;
int a;
int DHTPIN=D2;
int DHTTYPE=DHT11;
DHT dht(DHTPIN, DHTTYPE);
float h;
float t;

void setup()
{
  Serial.begin(9600);
  pinMode(ir,INPUT);
  pinMode(rel1,OUTPUT);
  pinMode(rel2,OUTPUT);
  dht.begin();
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}
void loop()
{
  Blynk.run();
  int a=digitalRead(ir);
  Serial.println(a);
  if(a==0)
  {
     led.on();
     Blynk.virtualWrite(V9,"person entered");
     //Blynk.notify("person entered");
     
  }
  else
  {
    led.off();
    Blynk.virtualWrite(V9,"no person entered");
  
  }
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  Serial.print("humidity= ");
  Serial.println(h);
  Blynk.virtualWrite(V7,h);
  
  Serial.print("temperature= ");
  Serial.println(t);
  Blynk.virtualWrite(V8,t);
  
  delay(500);
  
}
BLYNK_WRITE(V4)
{
  int b=param.asInt();
  digitalWrite(D3,b);
}
BLYNK_WRITE(V2)
{
  int a=param.asInt();
  digitalWrite(D4,a);
}
