// Example sketch for UIAPduino pin 11.
// On UIAPduino, pin 11 cannot be used as a normal GPIO pin
// until its debug function is disconnected first.
// This sketch shows the required initialization and then verifies
// pin 11 output by writing HIGH/LOW and reading the state back.

#define PIN_11 PD1   // Arduino D11 = PD1
                      // UIAPduino pin 11 is mapped to PD1.
                      // This pin needs debug-disconnect initialization
                      // before it can be used as a normal I/O pin.

void setup() {
  HIDuiap.begin();
  delay(5000);

  pinV32_DisconnectDebug(PD1);  // Release pin 11 from debug function first
  pinMode(PIN_11, OUTPUT);
  HIDuiap.write((const uint8_t*)"setup ok\n", 9);
}

void loop() {
  digitalWrite(PIN_11, HIGH);
  int rh = digitalRead(PIN_11);

  digitalWrite(PIN_11, LOW);
  int rl = digitalRead(PIN_11);

  if (rh == HIGH && rl == LOW) {
    HIDuiap.write((const uint8_t*)"Pin11 OK\n", 9);
  } else {
    HIDuiap.write((const uint8_t*)"Pin11 NG\n", 9);
  }
  delay(2500);
}