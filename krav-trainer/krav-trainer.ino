#include <Adafruit_MPU6050.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 3); // RX | TX

Adafruit_MPU6050 left{};
Adafruit_MPU6050 right{};

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  while (!left.begin(0x69)){
    delay(10);
  }

  while (!right.begin()){
    delay(10);
  }

  left.setAccelerometerRange(MPU6050_RANGE_16_G);
  right.setAccelerometerRange(MPU6050_RANGE_16_G);

  left.setFilterBandwidth(MPU6050_BAND_44_HZ);
  right.setFilterBandwidth(MPU6050_BAND_44_HZ);
}

void loop() {

  sensors_event_t leftA, leftG, leftTemp;
  sensors_event_t rightA, rightG, rightTemp;

  left.getEvent(&leftA, &leftG, &leftTemp);
  right.getEvent(&rightA, &rightG, &rightTemp);

  bluetooth.print(0);
  bluetooth.print(',');
  bluetooth.print(leftA.acceleration.x);
  bluetooth.print(',');
  bluetooth.print(leftA.acceleration.y);
  bluetooth.print(',');
  bluetooth.println(leftA.acceleration.z);

  bluetooth.print(1);
  bluetooth.print(',');
  bluetooth.print(rightA.acceleration.x);
  bluetooth.print(',');
  bluetooth.print(-rightA.acceleration.y);
  bluetooth.print(',');
  bluetooth.println(rightA.acceleration.z);
}
