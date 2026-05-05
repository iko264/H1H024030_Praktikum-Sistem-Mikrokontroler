# Pertanyaan praktikum percobaan 1
1. Apa fungsi perintah analogRead() pada rangkaian praktikum ini?
2. Mengapa diperlukan fungsi map() dalam program tersebut?
3. Modifikasi program berikut agar servo hanya bergerak dalam rentang 30° hingga 150°, meskipun potensiometer tetap memiliki rentang ADC 0–1023. Jelaskan program pada file README.md

# JAWABAN

1. fungsi perintah analogRead() digunakan untuk membaca tegangan dari pin analog dan merubahnya menjadi data digital atau adc
2. karena adc memiliki nilai 0-1023 sedangkan servo hanya menerima sudut nah fungsi map ini untuk merubah nilai sudut menjadi adc
3. modifikasi program

```cpp
#include <Servo.h> // library untuk servo motor

Servo myservo; // membuat objek servo

// ===================== PIN SETUP =====================
// Tentukan pin yang digunakan untuk potensiometer dan servo
const int potensioPin = A0;   // isi pin analog input (contoh A0)
const int servoPin = 9;      // isi pin digital untuk servo (PWM)

// ===================== VARIABEL =====================
// Variabel untuk menyimpan data ADC dan sudut servo
int pos = 0; // isi dengan tipe data dan inisialisasi awal
int val = 0; // isi dengan tipe data dan inisialisasi awal

void setup() {

  // Hubungkan servo ke pin yang sudah ditentukan
  myservo.attach(servoPin); // isi dengan servoPin

  // Aktifkan komunikasi serial untuk monitoring
  Serial.begin(9600); // isi baud rate (contoh 9600)

}

void loop() {

  // ===================== PEMBACAAN ADC =====================
  // Baca nilai dari potensiometer (rentang 0–1023)
  val = analogRead(potensioPin); // isi dengan potensioPin

  // ===================== KONVERSI DATA =====================
  // Ubah nilai ADC menjadi sudut servo (0–180 derajat)
  pos = map(val,
             0,   // isi nilai minimum ADC
             1023,   // isi nilai maksimum ADC
             30,   // isi sudut minimum servo
             150);  // isi sudut maksimum servo

  // ===================== OUTPUT SERVO =====================
  // Gerakkan servo sesuai hasil mapping
  myservo.write(pos); // isi dengan variabel sudut

  // ===================== MONITORING DATA =====================
  // Tampilkan data ADC dan sudut servo ke Serial Monitor
  Serial.print("ADC Potensio: ");
  Serial.print(val); // isi variabel ADC

  Serial.print(" | Sudut Servo: ");
  Serial.println(pos); // isi variabel sudut

  // ===================== STABILISASI =====================
  // Delay untuk memberi waktu servo bergerak stabil
  delay(20); // isi dalam milidetik
}
```

perbedaan program hanya terletak di maping sudut untuk servo nya dirubah menjadi map(val, 0, 1023, 30, 150); utnuk membatasi sudut servo

# Pertanyaan praktikum percobaan 2
1. Jelaskan mengapa LED dapat diatur kecerahannya menggunakan fungsi analogWrite()!
2. Apa hubungan antara nilai ADC (0–1023) dan nilai PWM (0–255)?
3. Modifikasilah program berikut agar LED hanya menyala pada rentang kecerahan sedang, yaitu hanya ketika nilai PWM berada pada rentang 50 sampai 200. Jelaskan program pada file README.md.

# jawaban

1. Fungsi analogRead() digunakan untuk membaca nilai tegangan analog dari potensiometer dan mengubahnya menjadi data digital dalam rentang 0 hingga 1023. Nilai ini kemudian digunakan sebagai input untuk mengontrol perangkat lain seperti servo atau LED.
2. Fungsi analogRead() digunakan untuk membaca nilai tegangan analog dari potensiometer dan mengubahnya menjadi data digital dalam rentang 0 hingga 1023. Nilai ini kemudian digunakan sebagai input untuk mengontrol perangkat lain seperti servo atau LED.

```cpp


// ===================== PIN SETUP =====================
// Tentukan pin yang digunakan untuk potensiometer dan LED PWM
const int potPin = A0;   // isi dengan pin analog (contoh A0)
const int ledPin = 9;   // isi dengan pin digital PWM (contoh 9)

// ===================== VARIABEL =====================
// Variabel untuk menyimpan hasil pembacaan dan konversi PWM
int nilaiADC = 0;  // isi dengan nilai awal (default 0)
int pwm = 0;       // isi dengan nilai awal (default 0)

void setup() {

  // ===================== OUTPUT SETUP =====================
  // Atur pin LED sebagai output
  pinMode(ledPin,OUTPUT);

  // ===================== SERIAL MONITOR =====================
  // Aktifkan komunikasi serial untuk melihat data pembacaan
  Serial.begin(9600); // isi baud rate (contoh 9600)
}

void loop() {

  // ===================== PEMBACAAN SENSOR =====================
  // Baca nilai analog dari potensiometer (rentang 0–1023)
  nilaiADC = analogRead(potPin); // isi dengan potPin

  // ===================== PEMROSESAN DATA (SCALING) =====================
  // Ubah nilai ADC (0–1023) menjadi nilai PWM (0–255)
  pwm = map(nilaiADC,
            0,   // isi nilai minimum ADC
            1023,   // isi nilai maksimum ADC
            50,   // isi PWM minimum
            200);  // isi PWM maksimum

  // ===================== OUTPUT PWM =====================
  // Kirim sinyal PWM ke LED (mengatur kecerahan)
 if (pwm >= 50 && pwm <= 200) {
    analogWrite(ledPin, pwm); // LED nyala normal
  } else {
    analogWrite(ledPin, 0);   // LED mati
  }

  // ===================== MONITORING DATA =====================
  // Tampilkan data ADC dan PWM ke Serial Monitor
  Serial.print("ADC: ");
  Serial.print(nilaiADC); // isi variabel ADC

  Serial.print(" | PWM: ");
  Serial.println(pwm); // isi variabel PWM

  // ===================== STABILISASI SISTEM =====================
  // Delay untuk menstabilkan pembacaan dan tampilan data
  delay(50); // isi dalam milidetik (contoh 50)
}
```
disini saya menggunkan percabagan untuk membuat jika pwm diantara 50 dan 200 maka led akan nyala dan jika selain itu maka akan mati 