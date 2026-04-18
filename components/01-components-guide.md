# Components Guide

This file gives fast practical notes for common Arduino components.

## LED
1. Short explanation: diode emits light.
2. Code: use `pinMode` + `digitalWrite`.
3. What happens: ON/OFF or blink.

## Resistor
1. Short explanation: limits current.
2. Code: no special code; hardware protection.
3. What happens: components stay safe.

## Button
1. Short explanation: user input switch.
2. Code: read pin with `digitalRead`.
3. What happens: Arduino detects press/release.

## Buzzer
1. Short explanation: sound output.
2. Code: `tone()` and `noTone()`.
3. What happens: beep alerts.

## LDR
1. Short explanation: light-dependent resistor.
2. Code: `analogRead(A0)`.
3. What happens: value changes with light level.

## LM35
1. Short explanation: analog temperature sensor.
2. Code: read ADC then convert to Celsius.
3. What happens: real-time temperature reading.

Open `code/components` for runnable examples.