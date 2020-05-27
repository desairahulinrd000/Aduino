#include <DHT.h>
int gas_sns=A0,buzz_pin=13,snd_sns=2,ac_relay=12,light_relay=11,dht11_pin=8;
int i,snd_sns_val,temp=LOW,gas_sns_val,gas_sns_thr=700,temp_thr=35.00;
DHT dht(dht11_pin,DHT11);
float temperature,humidity;
void setup()
{
  pinMode(gas_sns,INPUT);
  pinMode(snd_sns,INPUT_PULLUP);
  pinMode(ac_relay,OUTPUT);
  pinMode(light_relay,OUTPUT);
  pinMode(buzz_pin,OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(snd_sns),light,CHANGE);
}
void loop()
{
  temperature=dht.readTemperature();
  humidity=dht.readHumidity();
  digitalWrite(light_relay,temp);
  if(temp)
  {
   Serial.println("Light is ONN");
  }
  else
  {
    Serial.println("Light is OFF");
  }
  gas_sns_val=analogRead(gas_sns);
  if(gas_sns_val>gas_sns_thr)
  {
    buzzer();
  }
  if(temperature>temp_thr)
  {
    digitalWrite(ac_relay,HIGH);
    Serial.println("AC is ON");
  }
  else
  {
    Serial.println("AC is OFF");
  }
}
void light()
{
  temp=!temp;
}
void buzzer()
{
  for(i=0;i<5;i++)
  {
    digitalWrite(buzz_pin,HIGH);
    delay(1000);
    digitalWrite(buzz_pin,LOW);
    delay(1000);
  }
}
