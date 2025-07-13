// 핀 정의
int LED_PIN = 12;         // LED가 연결된 디지털 핀 번호
int LIGHT_SENSOR_PIN = A0; // 조도 센서가 연결된 아날로그 핀 번호

// 조도 센서 임계값 (이 값을 조절하여 어둠의 기준을 설정하세요)
// 값이 작을수록 더 어두워져야 LED가 켜집니다.
// 주변 환경에 따라 이 값을 조절해야 합니다.
int LIGHT_THRESHOLD = 300; // 예시 값 (0-1023 범위)

void setup() {
  // 시리얼 통신을 시작하여 센서 값을 모니터링할 수 있도록 합니다.
  Serial.begin(9600);

  // LED 핀을 출력 모드로 설정합니다.
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // 조도 센서의 아날로그 값을 읽습니다.
  // 이 값은 0 (매우 어두움)에서 1023 (매우 밝음) 사이의 값을 가집니다.
  int lightValue = analogRead(LIGHT_SENSOR_PIN);

  // 시리얼 모니터로 현재 조도 센서 값을 출력합니다.
  Serial.print("Current Light Value: ");
  Serial.println(lightValue);

  // 조도 센서 값이 임계값보다 작으면 (어두우면) LED를 고,
  // 그렇지 않으면 (밝으면) LED를 끕니다.
  if (lightValue < LIGHT_THRESHOLD) {
    // 주변이 어두우므로 LED를 켬
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED ON");
  } else {
    // 주변이 밝으므로 LED를 끔
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED OFF");
  }

  // 100밀리초(0.1초) 대기하여 안정적인 동작을 유지합니다.
  delay(100);
}