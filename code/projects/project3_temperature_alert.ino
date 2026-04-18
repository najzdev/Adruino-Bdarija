const int TEMP_PIN = A1;
const int BUZZER_PIN = 9;
const float TEMP_LIMIT = 30.0;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int raw = analogRead(TEMP_PIN);
  float voltage = raw * (5.0 / 1023.0);
  float tempC = voltage * 100.0;

  Serial.print("Temp: ");
  Serial.print(tempC);
  Serial.println(" C");

  if (tempC >= TEMP_LIMIT) {
    tone(BUZZER_PIN, 1200);
  } else {
    noTone(BUZZER_PIN);
  }

  delay(500);
}
