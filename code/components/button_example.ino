const int BUTTON_PIN = 2;
const int LED_PIN = 13;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  bool isPressed = digitalRead(BUTTON_PIN) == LOW;
  digitalWrite(LED_PIN, isPressed ? HIGH : LOW);
}
