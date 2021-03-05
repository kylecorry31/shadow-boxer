#include <Adafruit_MPU6050.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(11, 10); // RX | TX

Adafruit_MPU6050 mpu{};

void setup() {
  bluetooth.begin(9600);

  while (!mpu.begin()){
    delay(10);
  }


  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpu.setFilterBandwidth(MPU6050_BAND_44_HZ);
}

void loop() {

  sensors_event_t mpuA, mpuG, mpuTemp;

  mpu.getEvent(&mpuA, &mpuG, &mpuTemp);
  bluetooth.print(mpuA.acceleration.x);
  bluetooth.print(',');
  bluetooth.print(mpuA.acceleration.y);
  bluetooth.print(',');
  bluetooth.println(mpuA.acceleration.z);
}
