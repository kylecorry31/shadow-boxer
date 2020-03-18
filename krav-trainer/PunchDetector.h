#ifndef Punch_Detector_h
#define Punch_Detector_h

#include "Arduino.h"

class PunchDetector {

  public:
    PunchDetector();
    bool detect(float acceleration);
  private:
    // Inspired by: https://create.arduino.cc/projecthub/Advanced/punch-activated-arm-flamethrowers-real-firebending-95bb80
    float accelerationThreshold_ = 20;
    float decelerationThreshold_ = -40;
    long maxDuration_ = 200L;
    unsigned long startTime_;
  
};

#endif
