/*Just a test so please ignore it, otherwise please test in the test folder*/
#include <ESP32Servo.h>
Servo ESC;
Servo ESC2;
int btnPin = 33;
int potPin  = 4;

// Volatile var
volatile int val;
volatile boolean flag = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ESC.attach(13,1000,2000);
  ESC2.attach(18,1000,2000);
  pinMode(btnPin, INPUT_PULLUP);
  attachInterrupt(btnPin, ISR, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(flag) {
    val = 50;
    Serial.println(val);
    flag = false;
  }
  else {
    val = analogRead(potPin);
    val = map(val, 0, 4095, 0, 180);
    Serial.println(val);
    ESC.write(val);
    ESC2.write(val);
  }
  delay(100);
}

void IRAM_ATTR ISR() {
  flag = true;
}