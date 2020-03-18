#include "PunchDetector.h"

PunchDetector::PunchDetector(){
  // TODO: Consume an accelerometer and use that to detect
  startTime_ = 0;
}

bool PunchDetector::detect(float acceleration){
  if (acceleration >= accelerationThreshold_){
    startTime_ = millis();  
  }

  if (acceleration <= decelerationThreshold_ && millis() - startTime_ <= maxDuration_){
    startTime_ = 0;
    return true;    
  }

  return false;
}
