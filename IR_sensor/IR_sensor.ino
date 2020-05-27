int ir_sns=10;
int val;
void setup()
{
  Serial.begin(9600);
  pinMode(ir_sns,INPUT);
}
void loop()
{
  val=digitalRead(ir_sns);
  if(val)
  {
    Serial.println("Object Detected");
  }
  else
  {
    Serial.println("No objected Detected");
  }
}
