int pir_sns=10;
int val;
void setup()
{
  Serial.begin(9600);
  pinMode(pir_sns,INPUT);
}
void loop()
{
  val=digitalRead(pir_sns);
  if(val)
  {
    Serial.println("Object Detected");
  }
  else
  {
    Serial.println("No objected Detected");
  }
}
