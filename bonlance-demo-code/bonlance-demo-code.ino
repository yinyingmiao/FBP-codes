#include <Servo.h>

Servo Motor;

int servoPin = 10;


long triggerMovementTime = 0;

// long minMotorTime = 2000;

// long maxMotorTime = 4000;

long minDelayTime = 300000;

long maxDelayTime = 600000;

long delayTime = random (minDelayTime, maxDelayTime); //10-20 seconds




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

  //MOTOR LINES CANNOT BE CHANGED!!
  //ONLY DELAY LINES COULD BE CHANGED; BUT SHOULD BE LESS THAN 7500
  //from the good side
  
  Motor.writeMicroseconds (1200); //one direction; speed for, to the right from the better side at the front; direction & speed DO NOT CHANGE, clockwise  
  //the delay is the time for moving; 7.5 seconds is the most to go, and when move 
  delay (7700); // the max; travelling to one direction and the back has to be with the same speed: speed A + speed B = 3000; if using a timer for counting the direction of going, then it could never be higher than 7.5 sec
  Serial.println ("current time right");
  Serial.print (currentTime);
  
  Motor.writeMicroseconds (1500);
  delay (9000); //the motor stops
  Serial.println ("stop");
  Serial.print (currentTime);
  
  Motor.writeMicroseconds (1800); //the other direction
  delay(7700);
  Serial.println ("current time left");
  Serial.print (currentTime);

  Motor.writeMicroseconds(1500); //stop
  delay (4000); //the motor stops
  Serial.println ("stop");
  Serial.print (currentTime);
  
// the other side
//
//  Motor.writeMicroseconds (1800); //one direction; speed for, to the right from the better side at the front; direction & speed DO NOT CHANGE, clockwise  
//  //the delay is the time for moving; 7.5 seconds is the most to go, and when move 
//  delay (7500); // the max; travelling to one direction and the back has to be with the same speed: speed A + speed B = 3000; if using a timer for counting the direction of going, then it could never be higher than 7.5 sec
//  Serial.println ("current time left");
//  Serial.print (currentTime);
//  
//  Motor.writeMicroseconds (1500);
//  delay (9000); //the motor stops
//  Serial.println ("stop");
//  Serial.print (currentTime);
//  
//  Motor.writeMicroseconds (1200); //the other direction
//  delay(7500);
//  Serial.println ("current time right");
//  Serial.print (currentTime);
//
//  Motor.writeMicroseconds(1500); //stop
//  delay (4000); //the motor stops
//  Serial.println ("stop");
//  Serial.print (currentTime);

  delay (2000);
}
