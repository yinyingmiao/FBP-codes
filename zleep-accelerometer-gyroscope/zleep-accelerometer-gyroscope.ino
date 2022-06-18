// This code is for the midterm prototype ZLEEP of the project Slow Technology in Personal Health by Yinying Miao 

// This code is largely based on: https://lastminuteengineers.com/mpu6050-accel-gyro-arduino-tutorial/


#include <MPU6500_WE.h>
#include <Wire.h>
#define MPU6500_ADDR 0x68

MPU6500_WE accegyro = MPU6500_WE(MPU6500_ADDR);

void setup() {
  Serial.begin(9600);
  
  Wire.begin();
  
  if(!accegyro.init()){
    Serial.println("the sensor is not connected");
  }
  else{
    Serial.println("the sensor is connected");
  }
  
  Serial.println("Position the sensor flat and don't move it - calibrating...");
  
  delay(1000);
  
  accegyro.autoOffsets();
  
  Serial.println("Done!");
  
  accegyro.enableGyrDLPF();

  accegyro.setGyrDLPF(MPU6500_DLPF_6);

  accegyro.setSampleRateDivider(5);

  accegyro.setGyrRange(MPU6500_GYRO_RANGE_250);

  accegyro.setAccRange(MPU6500_ACC_RANGE_2G);

  accegyro.enableAccDLPF(true);

  accegyro.setAccDLPF(MPU6500_DLPF_6);

  delay(200);
}

void loop() {
  xyzFloat gValue = accegyro.getGValues();
  
  xyzFloat gyr = accegyro.getGyrValues();
  
  float temp = accegyro.getTemperature();
  
  float resultantG = accegyro.getResultantG(gValue);

  Serial.println("Acceleration in g (x,y,z):");
  Serial.print(gValue.x);
  Serial.print("   ");
  Serial.print(gValue.y);
  Serial.print("   ");
  Serial.println(gValue.z);
  Serial.print("Resultant g: ");
  Serial.println(resultantG);

  Serial.println("Gyroscope data in degrees/s: ");
  Serial.print(gyr.x);
  Serial.print("   ");
  Serial.print(gyr.y);
  Serial.print("   ");
  Serial.println(gyr.z);

  Serial.print("Temperature in °C: ");
  Serial.println(temp);

  Serial.println("********************************************");

  delay(1000);
}
