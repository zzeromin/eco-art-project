void setup() {
  pinMode(13, OUTPUT);   // 빨간색 LED를 연결한 핀
  pinMode(12, OUTPUT);   // 초록색 LED를 연결한 핀
}

void loop() {
  digitalWrite(13, HIGH);  // 빨간 LED 켜기
  digitalWrite(12, LOW);   // 초록 LED 끄기
  delay(1000);            // 1초 기다리기

  digitalWrite(13, LOW);   // 빨간 LED 끄기
  digitalWrite(12, HIGH);  // 초록 LED 켜기
  delay(1000);            // 1초 기다리기
}