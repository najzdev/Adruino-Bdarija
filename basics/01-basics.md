# Basics - Arduino Start

## 1) Short explanation

Hna kat3lm core basics li khassek:
- digital vs analog
- pinMode
- digitalWrite
- digitalRead

Digital = LOW/HIGH only.
Analog (input) = value mn 0 tal 1023.

## 2) Code

### Example 1: Blink LED
```cpp
const int LED_PIN = 13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
```

### Example 2: Read button
```cpp
const int BUTTON_PIN = 2;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  int state = digitalRead(BUTTON_PIN);
  Serial.println(state); // LOW when pressed
  delay(100);
}
```

## 3) What happens

- Blink code: LED kaych3el w kaytfa b duration fixed.
- Button code: Serial kaybayan state dyal button.

## Quick exercise

Bdel delay f blink men 500 l 100 w chouf result.