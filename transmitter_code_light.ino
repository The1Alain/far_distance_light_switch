#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define button 4
#define button_2 3

RF24 radio(7, 8); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};
Servo myServo;
boolean buttonState = 0;
boolean buttonState_2 = 0;
void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(button_2, INPUT);
  radio.begin();
  radio.openWritingPipe(addresses[0]); // 00001
  radio.openReadingPipe(1, addresses[1]); // 00002
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  delay(5);
  buttonState = digitalRead(button);
  buttonState_2 = digitalRead(button_2);
  Serial.println(buttonState);
  Serial.println(buttonState_2);
  delay(100);
  radio.startListening();
  
  int angleV = 0;
  radio.read(&angleV, sizeof(angleV));
  myServo.write(angleV);
  delay(5);
  radio.stopListening();
  buttonState = digitalRead(button);
  buttonState_2 = digitalRead(button_2);
  delay(100);
  radio.write(&buttonState, sizeof(buttonState));
  radio.write(&buttonState_2, sizeof(buttonState_2));
}