const int IR_PIN = 7;
const int BUZZER_PIN = 6;
const int LED_PIN = 13;

void setup() {
  pinMode(IR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int obstacle = digitalRead(IR_PIN); // often LOW = obstacle, depends on module

  if (obstacle == LOW) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1400);
    Serial.println("Obstacle detected");
  } else {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
    Serial.println("Clear");
  }

  delay(100);
}
