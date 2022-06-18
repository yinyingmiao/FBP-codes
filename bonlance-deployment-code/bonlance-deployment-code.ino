#include <Servo.h>

Servo Motor;

int servoPin = 10;


long triggerMovementTime = 0;

long minDelayTime = 28800000; //8 hours 

long maxDelayTime = 72000000; //20 hours

long delayTime = random (minDelayTime, maxDelayTime); //3 hours to 6 hours 




void setup() {

  
  Motor.attach (servoPin);

  Motor.writeMicroseconds (1500); // stopped motor 

  Serial.begin (9600);

  delay (6000);
  
}


void loop () { 

  long currentTime = millis ();  

  Serial.println ("current time: ");

  Serial.print (currentTime); 

  Serial.println (" ");

  if (currentTime > triggerMovementTime) {

    Serial.println ("Motor triggered");

    motor (); //35 seconds 

    Serial.println ("Motor off");
    
    delay (1000);

    triggerMovementTime = currentTime + delayTime; 

    Serial.println ("trigger movement time: ");

    Serial.print (triggerMovementTime);
    
  }

}


void motor () {

  long currentTime = millis ();
  
  Motor.writeMicroseconds (1420); //one direction; speed for, to the right from the better side at the front; direction & speed DO NOT CHANGE, clockwise  
  //the delay is the time for moving; 7.5 seconds is the most to go, and when move 
  delay (5500); // the max; travelling to one direction and the back has to be with the same speed: speed A + speed B = 3000; if using a timer for counting the direction of going, then it could never be higher than 7.5 sec
  Serial.println ("current time right");
  Serial.print (currentTime);
  
  Motor.writeMicroseconds (1500);
  delay (9000); //the motor stops
  Serial.println ("stop");
  Serial.print (currentTime);
  
  Motor.writeMicroseconds (1580); //the other direction
  delay(3800);
  Serial.println ("current time left");
  Serial.print (currentTime);

  Motor.writeMicroseconds(1500); //stop
  delay (6000); //the motor stops
  Serial.println ("stop");
  Serial.print (currentTime);

  delay (2000);
}
