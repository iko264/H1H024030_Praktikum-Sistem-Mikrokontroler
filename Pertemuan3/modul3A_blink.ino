#include <Arduino.h>

const int PIN_LED = 12;
char mode = '0'; 

void setup() {
  Serial.begin(9600);
  Serial.println("Ketik '1' untuk menyalakan LED, '0' untuk mematikan LED, '2' untuk LED blink");
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  
  if (Serial.available() > 0) {
    char inputBaru = Serial.read();

    
    if (inputBaru != '\n' && inputBaru != '\r') {
      mode = inputBaru; 
      
      if (mode == '1') {
        digitalWrite(PIN_LED, HIGH);
        Serial.println("Mode: LED ON");
      } 
      else if (mode == '0') {
        digitalWrite(PIN_LED, LOW);
        Serial.println("Mode: LED OFF");
      } 
      else if (mode == '2') {
        Serial.println("Mode: LED BLINKING");
      } 
      else {
        Serial.println("Perintah tidak dikenal");
      }
    }
  }

  if (mode == '2') {
    digitalWrite(PIN_LED, HIGH);
    delay(100);
    digitalWrite(PIN_LED, LOW);
    delay(500);
  }
}