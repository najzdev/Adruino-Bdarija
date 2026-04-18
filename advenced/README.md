# Advenced Arduino Practice (10 Examples)

Hna kayn advanced practice set bach t7ssen level dyalk f Arduino.

Each example has:
- sensor(s)
- actuator(s)
- clear logic
- ready .ino sketch

## List

1. `01_ultrasonic_led_bar.ino` - Distance indicator with 3 LEDs (HC-SR04)
2. `02_ir_obstacle_alarm.ino` - Obstacle alarm (IR sensor + buzzer + LED)
3. `03_servo_pot_control.ino` - Servo angle control with potentiometer
4. `04_dht11_relay_fan_control.ino` - Temperature fan control (DHT11 + relay)
5. `05_soil_moisture_pump_control.ino` - Auto watering logic (soil sensor + relay)
6. `06_ldr_auto_dimmer_pwm.ino` - Auto LED dimmer using PWM
7. `07_rfid_servo_door_lock.ino` - RFID access control (MFRC522 + servo)
8. `08_keypad_password_lock.ino` - Keypad password lock with LEDs + buzzer
9. `09_pir_motion_light_timer.ino` - Motion activated light with timeout
10. `10_lm35_temp_rgb_indicator.ino` - Temperature status using RGB LED

## Notes

- Some examples require extra libraries:
  - DHT sensor library
  - MFRC522
  - Servo (built-in with Arduino IDE)
  - Keypad
- For relay modules, verify if your relay is active LOW or active HIGH.
- Always connect GND of all modules together.

## Try this

- Add Serial logs to every project.
- Replace delays with millis-based timing.
- Add calibration variables and save them later in EEPROM.
