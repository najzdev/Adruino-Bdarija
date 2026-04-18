const int LDR_PIN = A0;
const int LED_PWM_PIN = 9;

void setup() {
  pinMode(LED_PWM_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(LDR_PIN);

  // Invert mapping: darker -> brighter LED
  int pwm = map(lightValue, 0, 1023, 255, 0);
  pwm = constrain(pwm, 0, 255);

  analogWrite(LED_PWM_PIN, pwm);

  Serial.print("LDR: ");
  Serial.print(lightValue);
  Serial.print(" PWM: ");
  Serial.println(pwm);

  delay(120);
}
