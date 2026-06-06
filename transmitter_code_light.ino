// Inclusion des bibliotèques requises.
// Inclusion of the required libraries.
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
// Mise en place des bouttons and des variables utilisée
// Setup of the servo buttons and used variables 
#define button 4
#define button_2 3
RF24 radio(7, 8); 
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
  // Initialisation des composents utilisés
  // Initialisation of the components
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
  // Lit les états des bouttons
  // Reads the states of the buttons
  buttonState = digitalRead(button);
  buttonState_2 = digitalRead(button_2);
  delay(100);
  // Envoie les état des bouttons à l'autre module NRF 24L01
  // Send the states of the buttons to another NRF 24L01 module
  radio.write(&buttonState, sizeof(buttonState));
  radio.write(&buttonState_2, sizeof(buttonState_2));
}
