void setup() {
  // put your setup code here, to run once:
  // Set pin 4 (ICP1) as an input
  pinMode(4, INPUT);
  // Optionally configure the output pin
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(PIND & (1<<PD4)){
    delayMicroseconds(25);
    PORTB ^= (1 << PORTB5);
    __asm__("nop\n\t");
    __asm__("nop\n\t");
    __asm__("nop\n\t");
    __asm__("nop\n\t");
    __asm__("nop\n\t");
    PORTB ^= (1 << PORTB5);
    delay(1);
  }
}
