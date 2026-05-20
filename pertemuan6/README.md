# 6.5.4 Pertanyaan Praktikum
1. Jelaskan proses bagaimana tombol dapat mengubah kondisi LED menggunakan
interrupt!
2. Apa fungsi attachInterrupt() pada program tersebut?
3. Mengapa pada ISR tidak disarankan menggunakan delay() dan Serial.print()?
4. Apa fungsi keyword volatile pada variabel ledState?
5. Pada percobaan digunakan mode interrupt FALLING. Modifikasikan program
menggunakan mode interrupt lain (RISING, CHANGE, atau LOW) kemudian:
- Jelaskan perbedaan cara kerja masing-masing mode interrupt tersebut
- Analisis perubahan perilaku LED yang terjadi pada setiap mode
- Sertakan source code dan penjelasan program dalam bentuk README.md

## jawab
1. Saat tombol ditekan, mikrokontroler menghentikan sementara program utama. Sistem lalu menjalankan fungsi ISR untuk mengubah status LED, kemudian melanjutkan program utama kembali.
2. Berfungsi untuk menghubungkan pin interrupt dengan fungsi ISR yang akan dijalankan.
3. SR harus dibuat sesingkat mungkin karena selama ISR berjalan, program utama akan berhenti sementara. Fungsi seperti delay() dan Serial.print() memakan waktu lama.
4. Memberitahu compiler bahwa nilai variabel tersebut dapat berubah sewaktu-waktu di luar alur normal program.
5. kodenya tinggal ganti FALLING menjadi RISING, CHANGE, atau LOW 
- RISING: ISR dipicu saat sinyal berubah dari LOW ke HIGH (LED toggle saat tombol dilepas).
- CHANGE: ISR dipicu setiap ada perubahan sinyal (LED toggle dua kali: saat ditekan dan dilepas).
- LOW: ISR terus dipicu selama tombol ditahan (sinyal LOW), membuat LED toggle sangat cepat/tidak menentu.

# 6.6.4 Pertanyaan Praktikum
1. Jelaskan bagaimana fungsi millis() bekerja pada program tersebut!
2. Apa perbedaan utama antara delay() dan millis()?
3. Mengapa metode millis() disebut non-blocking?
4. Modifikasi program agar:
• LED pertama berkedip setiap 1 detik
• LED kedua berkedip setiap 500 ms
• Tanpa menggunakan delay()
Berikan penjelasan setiap baris program dalam bentuk README.md.

## jawab
1. Fungsi ini mengembalikan waktu sejak Arduino menyala dalam satuan milidetik. Program membandingkan selisih waktu saat ini dengan waktu sebelumnya untuk memicu perubahan pada LED.
2. delay() menyebabkan program berhenti sementara sehingga tugas lain tertahan. millis() adalah metode non-blocking yang membiarkan program tetap berjalan.
3. Karena penggunaan millis() memungkinkan program utama tetap berjalan dan dapat mengeksekusi beberapa tugas sekaligus tanpa menghentikan mikrokontroler.

```cpp
#include <Arduino.h>
unsigned long previousMillis1 = 0; // waktu terakhir LED berubah
const long interval1 = 1000; // interval1 kedip: 1000 ms
bool ledState1 = false; // status LED saat ini

unsigned long previousMillis2 = 0; // waktu terakhir LED berubah
const long interval2 = 500; // interval2 kedip: 500 ms
bool ledState2 = false; // status LED saat ini

void setup() {
  pinMode(13, OUTPUT); // Pin 13 sebagai output
  pinMode(12, OUTPUT); //pin 12 sebagai output
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
```