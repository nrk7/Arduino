/*
 Connects Arduino to Raspberry Pi
 Arduino: SoftSerial
 Raspberry Pi: GPIO UART 
 Just connect pin 10(Arduino) to pin 8(Raspberry)  
              pin 11(Arduino) to pin 10(Raspberry)  
 */

#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11); // RX, TX

Servo myservo1;  // create servo object to control a servo
Servo myservo2;// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10); // attaches the servo on pin 8 to the servo object
}

void loop() {
// if Arduino receives positive signal from Raspberry Pi
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    delay(150); // Wait 15 seconds to lock door again
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo2.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
 //   
}
