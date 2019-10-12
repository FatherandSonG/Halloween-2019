/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int led =13;
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
pinMode(led,OUTPUT);
}

void loop() {
  
    myservo.write(5);
    digitalWrite(led,HIGH);// tell servo to go to position in variable 'pos'
    delay(1000);                       // waits 15ms for the servo to reach the position
    digitalWrite(led,LOW);
    myservo.write(45);              // tell servo to go to position in variable 'pos'
    delay(1000);                       // waits 15ms for the servo to reach the position
    myservo.write(90);              // tell servo to go to position in variable 'pos'
    delay(1000);                       // waits 15ms for the servo to reach the position
    myservo.write(135);              // tell servo to go to position in variable 'pos'
    delay(1000);                       // waits 15ms for the servo to reach the position
    myservo.write(180);              // tell servo to go to position in variable 'pos'
    delay(1000);                       // waits 15ms for the servo to reach the position
  myservo.write(200);              // tell servo to go to position in variable 'pos'
    delay(1000);                       // waits 15ms for the servo to reach the position
}
