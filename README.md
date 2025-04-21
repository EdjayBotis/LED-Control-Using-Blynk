# LED Control with Blynk and ESP32

This project uses an **ESP32** to control an LED via the **Blynk IoT App**.  
You can:
-  Turn the LED **ON/OFF** manually
- Set a **Blink Interval** (LED blinks automatically)

Both features are controlled from the Blynk App using **virtual pins**.

---

## Components/Materials
- ESP32 development board
- Blynk IoT App (download from App Store or Google Play)
- A working WiFi connection
- 5mm LED
- Jumper wire/s (if needed)

---

## 📲 Blynk Setup

1. Create a **New Template** in Blynk.Console
2. Copy:
   - `Template ID`
   - `Template Name`
   - `Auth Token`
3. Create **2 Datastreams**:
   - **V0** (Integer) → for LED ON/OFF
   - **V1** (Integer) → for Blink Interval (ms)
4. Create a new **Web or Mobile Dashboard**:
   - Add a **Switch** widget → link to **V0**
   - Add a **Slider** widget → link to **V1**
     - Slider range: 0 to 2000 (milliseconds)

## 🔧 Code Configuration

Edit these lines with your own Blynk and WiFi information:

```cpp
#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_TEMPLATE_NAME "YourTemplateName"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";
```

---

## 🖥Serial Monitor

When powered, the ESP32 will:
- Try connecting to WiFi (shows dots `.....`)
- Once connected, shows local IP address
- Connects to Blynk Cloud automatically


# Important Notes
- ESP32 must have stable internet access.
- Your phone does **not** need to be on the same WiFi after setting up.
- Blink interval too fast (like 1ms) might cause buggy behavior — recommend **≥ 100ms**.

---
# Created By
Edjay
