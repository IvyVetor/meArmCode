#include <Servo.h>

const int servo1 = 3;       // first servo
const int servo2 = 7;       // second servo
const int servo3 = 9;
const int servo4 = 13;

const int joyH = 3;        // L/R Parallax Thumbstick
const int joyV = 4;        // U/D Parallax Thumbstick
const int joyH2 = 2;
const int joyV2 = 5;

int servoVal;           // variable to read the value from the analog pin

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;
Servo myservo4;

int servoVal1 = 90; // sets initial location of servo to halfway (range is 0 to 180)
int servoVal2 = 90;
int servoVal3 = 90;
int servoVal4 = 90;

void setup() {

  // Servo
  myservo1.attach(servo1);  // attaches the servo
  myservo2.attach(servo2);  // attaches the servo
  myservo3.attach(servo3);
  myservo4.attach(servo4);

  // Inizialize Serial
  Serial.begin(115200);
  myservo1.write(servoVal1);
  myservo2.write(servoVal2);
  myservo3.write(servoVal3);
  myservo4.write(servoVal4);
}

void loop() {
  
  servoVal = analogRead(joyH);
  if (servoVal > 1000)
    servoVal2--;
  else if (servoVal < 200)
    servoVal2++;

  if (servoVal2 > 180)
    servoVal2 = 180;
  if (servoVal2 < 0)
    servoVal2 = 0;
  myservo2.write(servoVal2);


  servoVal = analogRead(joyV);
  if (servoVal > 1000)
    servoVal1--;
  else if (servoVal < 200)
    servoVal1++;

  if (servoVal1 > 180)
    servoVal1 = 180;
  if (servoVal1 < 0)
    servoVal1 = 0;
  myservo1.write(servoVal1);

  servoVal = analogRead(joyH2);
  if (servoVal > 1000)
    servoVal4--;
  else if (servoVal < 200)
    servoVal4++;

  if (servoVal4 > 180)
    servoVal4 = 180;
  if (servoVal4 < 0)
    servoVal4 = 0;
  myservo4.write(servoVal4);


  servoVal = analogRead(joyV2); 
  if (servoVal > 1000)
    servoVal3--;
  else if (servoVal < 200)
    servoVal3++;

  if (servoVal3 > 180)
    servoVal3 = 180;
  if (servoVal3 < 0)
    servoVal3 = 0;
  myservo3.write(servoVal3);

  delay(15);

}
