#include <Arduino.h>
unsigned long previousMillis1 = 0; // waktu terakhir LED berubah
const long interval1 = 1000; // interval kedip: 1000 ms
bool ledState1 = false; // status LED saat ini

unsigned long previousMillis2 = 0; // waktu terakhir LED berubah
const long interval2 = 500; // interval kedip: 1000 ms
bool ledState2 = false; // status LED saat ini

void setup() {
  pinMode(13, OUTPUT); // Pin 13 sebagai output
  pinMode(12, OUTPUT);
}

void loop() {
 // Ambil waktu saat ini
  unsigned long currentMillis = millis();
 // Cek apakah sudah melewati interval
  if(currentMillis - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis; // simpan waktu terakhir
    ledState1 = !ledState1; // toggle status LED
    digitalWrite(13, ledState1); // tulis ke pin LED
  }

  if(currentMillis - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis; // simpan waktu terakhir
    ledState2 = !ledState2; // toggle status LED
    digitalWrite(12, ledState2); // tulis ke pin LED
  }
}