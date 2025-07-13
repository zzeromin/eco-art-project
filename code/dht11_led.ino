#include <DHT11.h>

DHT11 dht11(4);

#define DHT11_PIN 4   // DHT11 데이터 핀
#define LEDR_PIN 13     // LED 핀
#define LEDG_PIN 12     // LED 핀
#define TEMP_THRESHOLD 28.0  // 임계 온도 (28도)

void setup() {
  pinMode(LEDR_PIN, OUTPUT);
  pinMode(LEDG_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float temperature = dht11.readTemperature();
  float humidity = dht11.readHumidity();
  Serial.print("Temperature: ");
  Serial.println(temperature);
  //Serial.print("Humidity: ");
  //Serial.print(humidity);
  //Serial.println(" %");

  if (temperature >= TEMP_THRESHOLD) {
    // LED 깜빡임
    digitalWrite(LEDG_PIN, LOW);
    digitalWrite(LEDR_PIN, HIGH);
    delay(500);
    digitalWrite(LEDR_PIN, LOW);
    delay(500);
  } else {
    // LEDG 켜짐
    digitalWrite(LEDG_PIN, HIGH);
    delay(1000); // 1초마다 온도 갱신
  }
}
