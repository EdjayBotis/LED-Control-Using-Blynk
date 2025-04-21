#define BLYNK_TEMPLATE_ID "Enter Template ID here"
#define BLYNK_TEMPLATE_NAME "Enter Template Name here"
#define BLYNK_AUTH_TOKEN "Enter authentication Token here"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Enter your wifi id here";
char pass[] = "Enter your wifi password here";

#define LED_PIN 2

int ledEnabled = 0;
int blinkInterval = 0; // in ms
unsigned long lastBlinkTime = 0;
bool ledState = false;

BLYNK_WRITE(V0) {
  ledEnabled = param.asInt(); // 0 = OFF, 1 = ON
  if (blinkInterval == 0) {
    digitalWrite(LED_PIN, ledEnabled);
  }
}

BLYNK_WRITE(V1) {
  blinkInterval = param.asInt(); // 0 to 2000 ms
  if (blinkInterval == 0) {
    digitalWrite(LED_PIN, ledEnabled); // solid on/off
  }
}

void connectToWiFi() {
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to Wi-Fi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200); // Useful for debugging on first power-up

  connectToWiFi(); // Optional: monitor Wi-Fi connection manually
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); // Reconnects to Blynk with stored creds
}

void loop() {
  Blynk.run();

  if (ledEnabled && blinkInterval > 0) {
    unsigned long currentMillis = millis();
    if (currentMillis - lastBlinkTime >= blinkInterval) {
      lastBlinkTime = currentMillis;
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
    }
  }
}
