#include <DHT.h>

const int DHT_PIN = 2;
const int RELAY_PIN = 8;
const int TEMP_LIMIT = 30;

DHT dht(DHT_PIN, DHT11);

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // default OFF for active-LOW relay
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  float tempC = dht.readTemperature();

  if (isnan(tempC)) {
    Serial.println("DHT read error");
    delay(1000);
    return;
  }

  Serial.print("Temp C: ");
  Serial.println(tempC);

  if (tempC >= TEMP_LIMIT) {
    digitalWrite(RELAY_PIN, LOW);  // ON for active-LOW relay
  } else {
    digitalWrite(RELAY_PIN, HIGH); // OFF
  }

  delay(1200);
}
