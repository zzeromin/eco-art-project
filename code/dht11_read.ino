#include <DHT11.h>

DHT11 dht11(4);

#define DHT11_PIN 4   // DHT11 데이터 핀

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float temperature = dht11.readTemperature();
  Serial.print("Temperature: ");
  Serial.println(temperature);
  delay(1000);
}
