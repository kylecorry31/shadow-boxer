#include "PunchDetector.h"

PunchDetector leftPunch {};
PunchDetector rightPunch {};

void setup() {
  Serial.begin(9600);
  
}

void loop() {

  float leftAcceleration = 0;
  float rightAcceleration = 0;

  if (leftPunch.detect(leftAcceleration)){
    Serial.println("Left punch");  
  }

  if (rightPunch.detect(rightAcceleration)){
    Serial.println("Right punch");  
  }
}
