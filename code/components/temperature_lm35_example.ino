const int TEMP_PIN = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int raw = analogRead(TEMP_PIN);
  float voltage = raw * (5.0 / 1023.0);
  float tempC = voltage * 100.0;

  Serial.print("Temp: ");
  Serial.print(tempC);
  Serial.println(" C");

  delay(1000);
}
