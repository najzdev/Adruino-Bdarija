const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int LED_NEAR = 2;
const int LED_MID = 3;
const int LED_FAR = 4;

float readDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 25000);
  if (duration == 0) {
    return -1.0;
  }

  return duration * 0.0343 / 2.0;
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_NEAR, OUTPUT);
  pinMode(LED_MID, OUTPUT);
  pinMode(LED_FAR, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float distance = readDistanceCm();

  digitalWrite(LED_NEAR, LOW);
  digitalWrite(LED_MID, LOW);
  digitalWrite(LED_FAR, LOW);

  if (distance > 0) {
    if (distance < 10) {
      digitalWrite(LED_NEAR, HIGH);
    } else if (distance < 25) {
      digitalWrite(LED_MID, HIGH);
    } else {
      digitalWrite(LED_FAR, HIGH);
    }

    Serial.print("Distance cm: ");
    Serial.println(distance);
  } else {
    Serial.println("No echo");
  }

  delay(120);
}
