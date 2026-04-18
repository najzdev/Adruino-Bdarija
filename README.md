# Arduino Bdarija - Beginner Friendly Learning Repo 

Made by MSc Hamza Labbaalli and supervised by PhD Amine Rghioui


---

## 1) Introduction

### Chno howa Arduino?
Arduino huwa open-source platform (hardware + software) bach t9dar tprogrami microcontroller b tariqa sahla.

B Arduino t9dar t9ra sensors, tch3el LEDs, motors, buzzer, w tbni smart projects.

### Why use Arduino?
- Easy for beginners
- Cheap and available
- Big community + tutorials
- Great for embedded systems basics
- Good portfolio for internships and jobs

---

## 2) Setup

### Install Arduino IDE
1. Download Arduino IDE from official Arduino website.
2. Install IDE (normal next-next-finish).
3. Open IDE.

### Connect board
1. Connect Arduino board with USB cable.
2. In IDE: Tools > Board > select your board (example: Arduino Uno).
3. Tools > Port > select COM port.
4. Test with Blink example.

If upload fails:
- Check USB cable (some cables are power only)
- Check board + port settings
- Close Serial Monitor before upload

---

## 3) Basics

### Digital vs Analog
- Digital: only 2 states (LOW = 0V, HIGH = 5V)
- Analog input: value from 0 to 1023 (ADC on Uno)

### Core functions

#### `pinMode(pin, mode)`
Short explanation:
- Defines pin direction (`INPUT`, `OUTPUT`, or `INPUT_PULLUP`).

Code:
```cpp
pinMode(13, OUTPUT);
pinMode(2, INPUT_PULLUP);
```

What happens:
- Pin 13 can control LED.
- Pin 2 reads button without external pull-up resistor (internal resistor is enabled).

#### `digitalWrite(pin, value)`
Short explanation:
- Writes digital state to output pin.

Code:
```cpp
digitalWrite(13, HIGH);
digitalWrite(13, LOW);
```

What happens:
- HIGH turns LED ON (usually).
- LOW turns LED OFF.

#### `digitalRead(pin)`
Short explanation:
- Reads digital state from input pin.

Code:
```cpp
int state = digitalRead(2);
```

What happens:
- `state` becomes HIGH or LOW depending on button/signal.

---

## 4) Components Guide

### 4.1 LED
Short explanation:
- LED = Light Emitting Diode. Kat3ti light mlli current ydoz.

How it works:
- Current passes from anode (+) to cathode (-).
- Always use resistor to limit current.

Wiring:
- LED anode -> resistor (220 ohm) -> Arduino pin 8
- LED cathode -> GND

Code:
```cpp
const int LED_PIN = 8;

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

What happens:
- LED blinks every 500 ms.

---

### 4.2 Resistor
Short explanation:
- Resistor kayna9es current, kayhmi components (especially LED).

How it works:
- Creates voltage/current drop according to Ohm law.

Wiring:
- Put resistor in series with LED (Arduino pin -> resistor -> LED -> GND).

Code:
```cpp
// Same LED code as above, resistor is in hardware wiring.
```

What happens:
- LED works safely without damage.

---

### 4.3 Button
Short explanation:
- Push button kay3ti press/release input.

How it works:
- We use `INPUT_PULLUP`, so pin is normally HIGH.
- When pressed, pin goes LOW (connected to GND).

Wiring:
- One side of button -> pin 2
- Other side -> GND
- No external resistor needed (internal pull-up)

Code:
```cpp
const int BUTTON_PIN = 2;
const int LED_PIN = 13;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int pressed = digitalRead(BUTTON_PIN) == LOW;
  digitalWrite(LED_PIN, pressed ? HIGH : LOW);
}
```

What happens:
- LED ON only while button is pressed.

---

### 4.4 Buzzer
Short explanation:
- Buzzer kaydir sound alert.

How it works:
- Passive buzzer can use `tone()` to generate frequency.

Wiring:
- Buzzer + -> pin 9
- Buzzer - -> GND

Code:
```cpp
const int BUZZER_PIN = 9;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  tone(BUZZER_PIN, 1000); // 1 kHz
  delay(200);
  noTone(BUZZER_PIN);
  delay(800);
}
```

What happens:
- Short beep every second.

---

### 4.5 LDR (Light Sensor)
Short explanation:
- LDR resistance changes with light.

How it works:
- More light => lower resistance.
- Read through voltage divider on analog pin.

Wiring:
- LDR one side -> 5V
- LDR other side -> A0 and resistor (10k)
- Other side of resistor -> GND

Code:
```cpp
const int LDR_PIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(LDR_PIN);
  Serial.println(lightValue);
  delay(500);
}
```

What happens:
- Serial Monitor shows light level from 0 to 1023.

---

### 4.6 Temperature Sensor (LM35)
Short explanation:
- LM35 gives analog voltage proportional to temperature.

How it works:
- Output is 10 mV per degree Celsius.

Wiring:
- LM35 VCC -> 5V
- LM35 OUT -> A1
- LM35 GND -> GND

Code:
```cpp
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
```

What happens:
- Serial Monitor shows approximate room temperature.

---

## 5) Mini Projects (3 Required)

## Project 1: LED Control (Blink + Button Control)
Goal:
- Learn output (LED blink) + input (button) in one project.

Components list:
- Arduino board
- 1 LED
- 1 resistor 220 ohm
- 1 push button
- Jumper wires
- Breadboard

Wiring:
- LED anode -> resistor -> pin 8
- LED cathode -> GND
- Button between pin 2 and GND
- Use `INPUT_PULLUP` for button pin

Full code:
```cpp
const int LED_PIN = 8;
const int BUTTON_PIN = 2;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    digitalWrite(LED_PIN, HIGH); // hold ON when pressed
  } else {
    digitalWrite(LED_PIN, HIGH);
    delay(300);
    digitalWrite(LED_PIN, LOW);
    delay(300);
  }
}
```

What happens:
- No press => LED blinks.
- Press button => LED stays ON.

---

## Project 2: Smart Light (LDR Auto LED)
Goal:
- Turn LED ON automatically in darkness.

Components list:
- Arduino board
- 1 LED
- 1 resistor 220 ohm for LED
- 1 LDR
- 1 resistor 10k for voltage divider
- Jumper wires
- Breadboard

Wiring:
- LDR divider output -> A0
- LED anode -> resistor -> pin 8
- LED cathode -> GND

Full code:
```cpp
const int LDR_PIN = A0;
const int LED_PIN = 8;
const int THRESHOLD = 500; // tune this

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(LDR_PIN);
  Serial.println(lightValue);

  if (lightValue < THRESHOLD) {
    digitalWrite(LED_PIN, HIGH); // dark => LED ON
  } else {
    digitalWrite(LED_PIN, LOW);  // bright => LED OFF
  }

  delay(200);
}
```

What happens:
- In dark area, LED turns ON.
- In bright area, LED turns OFF.

---

## Project 3: Temperature Alert (Sensor + Buzzer)
Goal:
- Make buzzer alert if temperature is higher than limit.

Components list:
- Arduino board
- LM35 sensor
- Buzzer
- Jumper wires
- Breadboard

Wiring:
- LM35 OUT -> A1
- Buzzer + -> pin 9
- Buzzer - -> GND

Full code:
```cpp
const int TEMP_PIN = A1;
const int BUZZER_PIN = 9;
const float TEMP_LIMIT = 30.0; // Celsius

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
```

What happens:
- If temp >= limit, buzzer sounds.
- If temp < limit, buzzer is silent.

---

## 6) Repo Structure

```text
arduino Bdarija/
├─ README.md
├─ advenced/
│  ├─ README.md
│  ├─ 01_ultrasonic_led_bar.ino
│  ├─ 02_ir_obstacle_alarm.ino
│  ├─ 03_servo_pot_control.ino
│  ├─ 04_dht11_relay_fan_control.ino
│  ├─ 05_soil_moisture_pump_control.ino
│  ├─ 06_ldr_auto_dimmer_pwm.ino
│  ├─ 07_rfid_servo_door_lock.ino
│  ├─ 08_keypad_password_lock.ino
│  ├─ 09_pir_motion_light_timer.ino
│  └─ 10_lm35_temp_rgb_indicator.ino
├─ basics/
│  └─ 01-basics.md
├─ components/
│  └─ 01-components-guide.md
├─ projects/
│  └─ 01-mini-projects.md
└─ code/
   ├─ basics/
   │  ├─ 01_blink.ino
   │  └─ 02_button_read.ino
   ├─ components/
   │  ├─ led_example.ino
   │  ├─ resistor_led_safe_example.ino
   │  ├─ button_example.ino
   │  ├─ buzzer_example.ino
   │  ├─ ldr_example.ino
   │  └─ temperature_lm35_example.ino
   └─ projects/
      ├─ project1_led_button_control.ino
      ├─ project2_smart_light_ldr.ino
      └─ project3_temperature_alert.ino
```

---

## 7) Small Exercises

1. Change blink speed (100 ms, 500 ms, 1000 ms).
2. In button project, make long press (2s) toggle LED mode.
3. In smart light project, print text: "Dark" or "Bright".
4. In temperature project, add 2 levels:
   - Warning at 30 C
   - Danger at 35 C (faster beep)

---

## 8) Try This

- Replace one LED with 3 LEDs (red/yellow/green) as temperature levels.
- Add second LDR and compare right side vs left side light.
- Send sensor values to Serial Plotter and observe curves.

---

## 9) Tips

- Always connect GND correctly.
- Start with simple test code before full project.
- Use `Serial.print()` for debugging.
- Avoid long `delay()` in bigger projects; later learn `millis()`.
- Keep wires organized and name your pins in code constants.

---

## 10) Final Message

Ila bditi b had repo step by step, ghadi tfham Arduino basics mzyan, w ghadi ykoun 3ndek practical mini portfolio.

This project is designed to be beginner friendly and recruiter friendly:
- clear structure
- real hardware examples
- complete code
- progressive learning path

Happy building!
