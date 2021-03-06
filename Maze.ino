#include <Servo.h>

#define E1 11 // Enable Pin for motor 1
#define E2 3 // Enable Pin for motor 2

#define I1 10 // control Pin 1 for motor 1
#define I2 9 // control Pin 2 for motor 1
#define I3 5 // control Pin 1 for motor 2
#define I4 6 // control Pin 2 for motor 2
char key; 

int photocellPin = 0;
int photocellReading; 

//Servo myservo; 
//int servopos = 0; 

void setup() {
  
  //connect to the arduino board
  Serial.begin(9600);
  //Connecting motors with arduino 
   pinMode(E1, OUTPUT);
   pinMode(E2, OUTPUT);
   
   pinMode(I1, OUTPUT);
   pinMode(I2, OUTPUT);
   pinMode(I3, OUTPUT);
   pinMode(I4, OUTPUT);

   //myservo.attach(8);  
}

void loop() {
  if (Serial.available() > 0){
   /* photocellReading = analogRead(photocellPin); 
    if (photocellReading < 200){
      for ( servopos = 0; servopos >=90; servopos++)
         myservo.write(90); 
      delay(5000); 
      for (servopos = 90; servopos >= 0; servopos--)
         myservo.write(0);
      delay(100); 
    }*/
    key = Serial.read();
    // front tilts
    if (key == 'w') {    
      analogWrite(E1, 255); // Run forward low speed.
      digitalWrite(I1, HIGH);
      digitalWrite(I2, LOW);
      delay(200);
    }
    // back tilts
    else if (key == 's') {    
      digitalWrite(E1, LOW); //reverse direction.
      analogWrite(E1,255); // run backward low speed.
      digitalWrite(I1, LOW);
      digitalWrite(I2, HIGH);
      delay(200); 
      Serial.println("titls backward");   
    }
    //left tilts
    else if (key == 'd') {
      digitalWrite(E2, LOW); //reverse direction.
      analogWrite(E2,255); // run backward low speed.
      digitalWrite(I3, LOW);
      digitalWrite(I4, HIGH);
      delay(200);
      }
      //right tilts
    else if (key == 'a') {
      analogWrite(E2, 255); // Run forward low speed.
      digitalWrite(I3, HIGH);
      digitalWrite(I4, LOW);
      delay(200);
      }
  }

}
