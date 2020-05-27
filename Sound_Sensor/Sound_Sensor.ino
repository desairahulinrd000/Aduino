int input_pin=8; 
int output_pin=9; 
int i;
void setup()
{
  pinMode(input_pin,INPUT);
  pinMode(output_pin,OUTPUT);
}
void loop()
{
  i=digitalRead(input_pin);
  digitalWrite(output_pin,i);
}
