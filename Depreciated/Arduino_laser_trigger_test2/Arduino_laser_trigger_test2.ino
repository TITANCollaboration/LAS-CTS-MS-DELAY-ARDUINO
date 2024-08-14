void setup() {
  // Set pin 4 (ICP1) as an input
  pinMode(4, INPUT);

  // Configure Timer1 in Normal mode or CTC mode
  TCCR1A = 0;  // Normal port operation
  TCCR1B = 0;  // Default settings, no clock source

  // Set the compare match register for a 1 kHz square wave
  OCR1A = 200; // (16 MHz / (2 * 1000)) - 1

  // Optionally configure the output pin
  pinMode(9, OUTPUT);

  // Stop Timer1 initially
  stopTimer();
}

void stopTimer() {
  // Stop Timer1 by clearing the clock select bits
  TCCR1B &= ~(1 << CS12);  // Clear the prescaler bits
  TCCR1B &= ~(1 << CS11);
  TCCR1B &= ~(1 << CS10);
}

void startTimer() {
  // Restart Timer1 with a prescaler (for example, 1024)
  TCCR1B |= (1 << CS11);
}


ISR(TIMER1_COMPA_vect) {
  // Toggle the output pin
  digitalWrite(9, HIGH);
  digitalWrite(9,LOW);
}

void loop() {
  // Main loop can contain other code
  if (digitalRead(4)){
    startTimer();
  }
}
