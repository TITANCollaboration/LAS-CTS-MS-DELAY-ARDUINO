void setup() {
  // Set pin 9 (PB5/OC1A) as output
  pinMode(9, OUTPUT);
  
  // Stop the timer
  TCCR1A = 0;
  TCCR1B = 0;

  // Set CTC mode
  TCCR1B |= (1 << WGM12);
  
  // Set the compare match register for a 1 kHz square wave
  OCR1A = 320; // (16 MHz / (2 * 1000)) - 1
  
  // 1<<CS10 Sets the clock prescaler to 1 (no prescaling)
  TCCR1B |= (1 << CS10);

  // Enable compare match A interrupt
  TIMSK1 |= (1 << OCIE1A);
}

ISR(TIMER1_COMPA_vect) {
  // Toggle the output pin
  PORTB ^= (1 << PORTB5);
  PORTB ^= (1 << PORTB5);
}

void loop() {
  // No code needed here
}
