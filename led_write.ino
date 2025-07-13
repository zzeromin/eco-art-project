void setup() {
  // setup() 함수는 코드가 시작될 때 '한 번만' 실행됩니다.
  // 13번 핀을 '출력(OUTPUT)' 모드로 설정합니다.
  pinMode(13, OUTPUT);
}
void loop() {
  // loop() 함수는 setup()이 끝난 후 '무한 반복' 실행됩니다.
  digitalWrite(13, HIGH);  // 13번 핀에 전기를 보냅니다. (LED 켜짐)
  delay(1000);             // 1000밀리초 = 1초 동안 기다립니다
  digitalWrite(13, LOW);   // 13번 핀에 전기를 끊습니다. (LED 꺼짐)
  delay(1000);             // 1초 동안 기다립니다
}
