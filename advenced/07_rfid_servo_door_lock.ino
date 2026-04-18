#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

const int SS_PIN = 10;
const int RST_PIN = 9;
const int SERVO_PIN = 3;
const int GREEN_LED = 5;
const int RED_LED = 6;

MFRC522 rfid(SS_PIN, RST_PIN);
Servo lockServo;

byte allowedUID[4] = {0xDE, 0xAD, 0xBE, 0xEF};

bool uidMatch(const MFRC522::Uid &uid) {
  if (uid.size != 4) {
    return false;
  }
  for (byte i = 0; i < 4; i++) {
    if (uid.uidByte[i] != allowedUID[i]) {
      return false;
    }
  }
  return true;
}

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  lockServo.attach(SERVO_PIN);
  lockServo.write(0); // locked position
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  if (uidMatch(rfid.uid)) {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    lockServo.write(90); // unlock
    Serial.println("Access granted");
    delay(2500);
    lockServo.write(0); // lock again
    digitalWrite(GREEN_LED, LOW);
  } else {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    Serial.println("Access denied");
    delay(1200);
    digitalWrite(RED_LED, LOW);
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
