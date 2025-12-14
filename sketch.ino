/* * Project: IoT Weather Station with Edge Computing
 * Hardware: ESP32, DHT22, SSD1306 OLED, Potentiometer (Rain)
 * Cloud: ThingSpeak
 */

#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// --- USER CONFIGURATION ---
// PASTE YOUR API KEY INSIDE THE QUOTES BELOW
String apiKey = "L62H0VS4C38F1RO7";
const char *server = "http://api.thingspeak.com";

// --- PIN DEFINITIONS (Must match diagram.json) ---
#define DHTPIN 15     // Digital Pin for Temp/Hum
#define DHTTYPE DHT22 // Sensor Model
#define RAINPIN 34    // Analog Pin for Rain Sensor
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// --- OBJECT INITIALIZATION ---
DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup()
{
    Serial.begin(115200); // Start Serial Monitor for debugging

    // 1. Initialize Sensors
    dht.begin();
    pinMode(RAINPIN, INPUT);

    // 2. Initialize Display
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ; // Don't proceed, loop forever
    }
    display.clearDisplay();
    display.setTextColor(WHITE);

    // 3. Connect to Virtual WiFi
    // Wokwi provides a virtual network named "Wokwi-GUEST"
    Serial.print("Connecting to WiFi");
    WiFi.begin("Wokwi-GUEST", "", 6);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println(" Connected!");
}

void loop()
{
    // ==========================================
    // LAYER 1: DATA ACQUISITION (Perception) TODO
    // ==========================================
    

    // ==========================================
    // LAYER 2: EDGE COMPUTING (Decision Making) TODO
    // ==========================================
    // We process data LOCALLY to make fast decisions before sending to cloud.


    // ==========================================
    // LAYER 3: SYSTEM INTERFACE (Visualization) TODO
    // ==========================================
    

    // ==========================================
    // LAYER 4: CLOUD COMMUNICATION (Reporting) TODO
    // ==========================================
    

    // ThingSpeak Free Tier allows updates every 15 seconds
    // This delay also helps "Power Consumption" (Source 83) by sleeping the radio
    delay(15000);
}