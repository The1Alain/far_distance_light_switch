#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
Servo monServo;  
Servo monServo_2;
int servo_position = 0;
int servo_position_2 = 0;
RF24 radio(7, 8); 
const byte addresses[][6] = {"00001", "00002"};
boolean buttonState = 0;
boolean buttonState_2 = 0;

void setup() {
  pinMode(2, OUTPUT);
  
  radio.begin();
  radio.openWritingPipe(addresses[1]); 
  radio.openReadingPipe(1, addresses[0]); 
  radio.setPALevel(RF24_PA_MIN);
  Serial.begin(9600);
  monServo.attach(2);
  monServo_2.attach(3);
}

void loop() {
  delay(5);
  monServo.write(servo_position);
  monServo_2.write(servo_position_2);
  radio.stopListening();
  int potValue = analogRead(A0);
  int angleValue = map(potValue, 0, 1023, 0, 180);
  radio.write(&angleValue, sizeof(angleValue));


  radio.startListening();
  radio.read(&buttonState, sizeof(buttonState));;
  
  if (buttonState == HIGH) {
    servo_position = 70; // angle to change if you need to / angle à modifier si vous avez besoin
    monServo.write(servo_position);
    delay(2000);
    
  }
  if (buttonState == LOW) { 
    servo_position = 180; // angle to change if you need to / angle à modifier si vous avez besoin
    monServo.write(servo_position);
  }
  radio.read(&buttonState_2, sizeof(buttonState_2));;
  if (buttonState_2 == HIGH) {
    servo_position_2 = 150; // angle to change if you need to / angle à modifier si vous avez besoin
    monServo_2.write(servo_position_2);
    delay(2000);


  }
  if (buttonState_2 == LOW) { 
    servo_position_2 = 0 ; // angle to change if you need to / angle à modifier si vous avez besoin
    monServo_2.write(servo_position_2);
  }
  Serial.println(buttonState);
  Serial.println(buttonState_2);
  Serial.println(servo_position);
  Serial.println(servo_position_2);
}
