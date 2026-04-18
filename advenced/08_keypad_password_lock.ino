#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int GREEN_LED = 10;
const int RED_LED = 11;
const int BUZZER_PIN = 12;

String entered = "";
const String PASSWORD = "2580";

void okSignal() {
  digitalWrite(GREEN_LED, HIGH);
  tone(BUZZER_PIN, 1200, 120);
  delay(300);
  digitalWrite(GREEN_LED, LOW);
}

void failSignal() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(RED_LED, HIGH);
    tone(BUZZER_PIN, 400, 180);
    delay(220);
    digitalWrite(RED_LED, LOW);
    delay(120);
  }
}

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  if (!key) {
    return;
  }

  if (key == '#') {
    if (entered == PASSWORD) {
      Serial.println("Password OK");
      okSignal();
    } else {
      Serial.println("Password wrong");
      failSignal();
    }
    entered = "";
    return;
  }

  if (key == '*') {
    entered = "";
    Serial.println("Input cleared");
    return;
  }

  entered += key;
  Serial.print("Input: ");
  Serial.println(entered);
}
