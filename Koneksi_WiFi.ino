#if defined(ESP8266)
  #include <ESP8266WiFi.h>
#elif defined(ESP32)
  #include <WiFi.h>
#endif

#define WIFI_SSID "Wokwi-GUEST"      
#define WIFI_PASSWORD ""             
#define SERIAL_DEBUG_BAUD 115200
#define LED 15

int status = WL_IDLE_STATUS;

void InitWiFi() {
  Serial.println("Connecting to AP ...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nConnected to AP!");
  Serial.print("WiFi sudah terkoneksi dengan: ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address (DHCP): ");
  Serial.println(WiFi.localIP()); 
  Serial.println("==========================================");
}

void reconnect() {
  status = WiFi.status();
  if (status != WL_CONNECTED) {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("\nConnected to AP!");
    Serial.print("IP Address (DHCP): ");
    Serial.println(WiFi.localIP());
  }
}

void setup() {
  Serial.begin(SERIAL_DEBUG_BAUD);
  delay(1000);
  pinMode(LED, OUTPUT);
  
  InitWiFi();
}

void loop() {
  delay(1000);

  if (WiFi.status() != WL_CONNECTED) {
    reconnect();
  } else {
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
  }
}
