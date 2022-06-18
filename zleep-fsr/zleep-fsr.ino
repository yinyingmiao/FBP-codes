#include "Arduino.h"

const byte fsr1 = A0;
const byte fsr2 = A1;
const byte fsr3 = A2;

int fsrR1;
int fsrR2; 
int fsrR3; 


void setup() {
  
  Serial.begin(9600);   
  
}

 
void loop() {
  
  fsrR1 = analogRead(fsr1);  
  fsrR2 = analogRead(fsr2);  
  fsrR3 = analogRead(fsr3);  
  
  Serial.print("fsr1 = ");
  Serial.print(fsrR1);  
  Serial.print("fsr2 = ");
  Serial.print(fsrR2);  
  Serial.print("fsr3 = ");
  Serial.print(fsrR3);  
 
  delay(1000);
  
}
