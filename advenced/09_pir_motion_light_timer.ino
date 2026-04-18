const int PIR_PIN = 2;
const int LED_PIN = 8;
const int BUZZER_PIN = 9;
const unsigned long LIGHT_HOLD_MS = 10000;

unsigned long lastMotionTime = 0;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH) {
    lastMotionTime = millis();
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1800, 80);
    Serial.println("Motion detected");
  }

  if (millis() - lastMotionTime > LIGHT_HOLD_MS) {
    digitalWrite(LED_PIN, LOW);
  }

  delay(50);
}
