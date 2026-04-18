const int SOIL_PIN = A0;
const int RELAY_PIN = 8;
const int DRY_THRESHOLD = 450; // tune for your sensor

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // pump OFF for active-LOW relay
  Serial.begin(9600);
}

void loop() {
  int soilValue = analogRead(SOIL_PIN);
  Serial.print("Soil value: ");
  Serial.println(soilValue);

  if (soilValue > DRY_THRESHOLD) {
    digitalWrite(RELAY_PIN, LOW);  // pump ON
    Serial.println("Soil dry -> Pump ON");
  } else {
    digitalWrite(RELAY_PIN, HIGH); // pump OFF
    Serial.println("Soil wet -> Pump OFF");
  }

  delay(1000);
}
