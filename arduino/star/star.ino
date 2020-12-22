const int purple = 1;
const int white = 0;

void setup() {
  pinMode(purple, OUTPUT);
  pinMode(white, OUTPUT);
}

void loop() {
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(purple, fadeValue);
    analogWrite(white, 255 - fadeValue);
    delay(100);
  }

  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(purple, fadeValue);
    analogWrite(white, 255 - fadeValue);
    delay(100);
  }
}
