#include <TimerOne.h>

#define LED_PIN 9
#define POTI_PIN A0

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(POTI_PIN, INPUT);
  Timer1.initialize(40); // 122us => 8kHz; 40us => 25kHz=max H-Bridge
  Timer1.pwm(LED_PIN, 512);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t potiInput = analogRead(POTI_PIN);
  static uint16_t prevPotiInput = 0xFFFF;
  if (potiInput < 50) potiInput = 0;
  if (potiInput != prevPotiInput) { // 5% safe zone
    //analogWrite(LED_PIN, potiInput >> 3); // from 1024 -> 128 to limit motor from burning
    Timer1.setPwmDuty(LED_PIN, potiInput >> 1); // maximum is half
    prevPotiInput = potiInput;
  }
  
  delay(10);
}
