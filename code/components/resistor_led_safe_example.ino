const int LED_PIN = 8;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Wire LED in series with 220 ohm resistor to protect LED.
  digitalWrite(LED_PIN, HIGH);
  delay(700);
  digitalWrite(LED_PIN, LOW);
  delay(700);
}
