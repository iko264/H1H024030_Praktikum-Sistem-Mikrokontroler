#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

// Inisialisasi LCD I2C (Alamat 0x27, 16 kolom, 2 baris)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pinPot = A0; 

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int nilaiADC = analogRead(pinPot);

  // Kalkulasi Volt (0.00 - 5.00V) dan Persentase
  float volt = (nilaiADC / 1023.0) * 5.0;
  int persen = map(nilaiADC, 0, 1023, 0, 100);

  // 1. Output ke Serial Monitor (Sesuai format tabel yang diminta)
  Serial.print("ADC: ");
  Serial.print(nilaiADC);
  Serial.print(" Volt: ");
  Serial.print(volt);
  Serial.print(" V Persen: ");
  Serial.print(persen);
  Serial.println("%");

  // 2. Output ke LCD (I2C)
  // Baris 1: ADC, Volt, dan Persen
  lcd.setCursor(0, 0);
  lcd.print(nilaiADC);
  lcd.print(" ");
  lcd.print(volt, 1); // Menampilkan 1 angka di belakang koma (misal 5.0)
  lcd.print("V ");
  lcd.print(persen);
  lcd.print("%   "); // Spasi untuk clear sisa karakter

  // Baris 2: Progress Bar (Level)
  lcd.setCursor(0, 1);
  int panjangBar = map(nilaiADC, 0, 1023, 0, 16);
  for (int i = 0; i < 16; i++) {
    if (i < panjangBar) {
      lcd.print((char)255); 
    } else {
      lcd.print(" "); 
    }
  }

  delay(200); 
}