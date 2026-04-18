const int TEMP_PIN = A1;
const int RED_PIN = 3;
const int GREEN_PIN = 5;
const int BLUE_PIN = 6;

float readTempC() {
  int raw = analogRead(TEMP_PIN);
  float voltage = raw * (5.0 / 1023.0);
  return voltage * 100.0;
}

void setColor(int r, int g, int b) {
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
}

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float tempC = readTempC();
  Serial.print("Temp C: ");
  Serial.println(tempC);

  if (tempC < 24.0) {
    setColor(0, 0, 255);   // blue = cold
  } else if (tempC <= 30.0) {
    setColor(0, 255, 0);   // green = normal
  } else {
    setColor(255, 0, 0);   // red = hot
  }

  delay(400);
}
