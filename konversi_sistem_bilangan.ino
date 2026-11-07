/*
 * Program Konversi Bilangan Desimal ke Biner, Heksadesimal, dan Oktal
 * Berjalan langsung di Simulator Wokwi (ESP32 / ESP8266)
 */

int nilai = 175; 

void setup() {
  Serial.begin(115200);
  delay(1000); 

  Serial.println("\n==========================================");
  Serial.println("  Konversi Sistem Bilangan pada ESP32");
  Serial.println("==========================================");

  Serial.print("Nilai Asli (Desimal)     : ");
  Serial.println(nilai, DEC);

  Serial.print("Nilai Biner (BIN)         : ");
  Serial.println(nilai, BIN);

  Serial.print("Nilai Heksadesimal (HEX)  : 0x");
  Serial.println(nilai, HEX);

  Serial.print("Nilai Oktal (OCT)         : ");
  Serial.println(nilai, OCT);

  Serial.println("==========================================");
}

void loop() {
}
