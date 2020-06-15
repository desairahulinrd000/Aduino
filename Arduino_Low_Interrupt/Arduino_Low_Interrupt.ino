const int ledPin = 12;
const int int_led_pin=10;
const int interruptPin = 2;
volatile byte state = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
   pinMode(10, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, LOW);
}

void loop() {
  digitalWrite(interruptPin, state);
  digitalWrite(ledPin,HIGH);
  delay(10000);
  digitalWrite(ledPin,LOW);
  delay(10000);
}

void blink() {
  state = !state;
}
