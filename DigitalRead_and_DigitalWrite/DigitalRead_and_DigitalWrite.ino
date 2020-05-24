int input_pin=8;
int output_pin=9;
int val;
void setup()
{
  pinMode(8,OUTPUT);
  pinMode(9,INPUT);
}
void loop()
{
  val=digitalRead(input_pin);
  digitalWrite(output_pin,val);
}
