void setup() {
  pinMode(2, OUTPUT);    // sets the digital pin 2 as output
}

void loop() {
  PORTD &= ~0x02;
  PORTD |= 0x02;
}