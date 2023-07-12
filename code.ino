#include <TinyGPS++.h> // library for GPS module
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
TinyGPSPlus gps;  // The TinyGPS++ object
SoftwareSerial ss(2,0); // The serial connection to the GPS device connect 2(d4) with tx of gps

float latitude , longitude;
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
WiFiServer server(80);

#define REPORTING_PERIOD_MS     1000
MAX30100 sensor;
// PulseOximeter is the higher level interface to the sensor
// it offers:
//  * beat detection reporting
//  * heart rate calculation
//  * SpO2 (oxidation level) calculation

int d,f=0;
//FOR OLED
#include "Adafruit_GFX.h"
#include "OakOLED.h"
OakOLED oled;

#define BLYNK_TEMPLATE_ID "TMPLvALjhhFZ"
#define BLYNK_DEVICE_NAME "Rock Climber2"
#define BLYNK_AUTH_TOKEN "d7C4uNf1B0aZ-wAZu2kh1xHx2X-PYCeH"
char auth[] = BLYNK_AUTH_TOKEN;             // Authentication Token Sent by Blynk
char ssid[] = "Redmi9";        //WiFi SSID
char pass[] = "coffee39";        //WiFi Password
WidgetLED led(V0);
// Connections : SCL PIN - D1 , SDA PIN - D2 , INT PIN - D0
PulseOximeter pox;
String temp_str,heart,spo,lng_str,lat_str;
float BPM, SpO2,temp;
uint32_t tsLastReport = 0;
uint32_t tsLastReading = 0;
// Callback (registered below) fired when a pulse is detected
 
void onBeatDetected()
{
    Serial.println("Beat!");
}
 
void setup()
{
    Serial.begin(9600);
    pinMode(D5,INPUT);
  Serial.begin(9600);
  d=0;
  
  ss.begin(9600);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
    //pinMode(16, OUTPUT);
    Blynk.begin(auth, ssid, pass,"blr1.blynk.cloud");
 oled.begin();
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(1);
  oled.setCursor(0, 0);

  while (WiFi.status() != WL_CONNECTED)// while wifi not connected
  {
    delay(500);
    Serial.print("."); //print "...."
  }
  Serial.println("");
  Serial.println("WiFi connected");
  server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());  // Print the IP address
  
    Serial.print("Initializing Pulse Oximeter..");
    // Initialize the PulseOximeter instance
    // Failures are generally due to an improper I2C wiring, missing power supply
    // or wrong target chip
 
    if (!pox.begin()) {
        Serial.println("FAILED");
        for(;;);
    } else {
        Serial.println("SUCCESS");
    }
    pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
    pox.setOnBeatDetectedCallback(onBeatDetected);
 
}
 
void loop()
{
  pox.update();
    Blynk.run();
    d=digitalRead(D5);
 //MAX30100
    BPM = pox.getHeartRate();
    SpO2 = pox.getSpO2();
    heart=String(BPM);
    spo=String(SpO2);
   if (millis() - tsLastReport > REPORTING_PERIOD_MS)
    {
        Serial.print("Heart rate:");
        Serial.print(BPM);
        Serial.print(" bpm / SpO2:");
        Serial.print(SpO2);
        Serial.println(" %");
 
        Blynk.virtualWrite(V1, BPM);
        Blynk.virtualWrite(V2, SpO2);
        tsLastReport = millis();
    }
    sensor.update();

  if (millis() - tsLastReading > REPORTING_PERIOD_MS) {
    sensor.startTemperatureSampling();
    if (sensor.isTemperatureReady()) {
      float temp = sensor.retrieveTemperature();
      Blynk.virtualWrite(V3, temp);
      temp_str=String(temp);
      Serial.print("Temperature = ");
      Serial.print(temp);
      Serial.print("*C | ");
      Serial.print((temp * 9.0) / 5.0 + 32.0);//print the temperature in Fahrenheit
      Serial.println("*F");
    }
    tsLastReading = millis();
  }
  while (ss.available() > 0){ //while data is available
    if (gps.encode(ss.read())) //read gps data
    {
      if (gps.location.isValid()) //check whether gps location is valid
      {
        latitude = gps.location.lat();
        lat_str = String(latitude , 6); // latitude location is stored in a string
        longitude = gps.location.lng();
        lng_str = String(longitude , 6); //longitude location is stored in a string
        }
    }
  }
  //OLED
  oled.clearDisplay();oled.setTextSize(1);oled.setTextColor(1);
      oled.setCursor(0, 0);oled.print("Heart BPM: ");oled.println(heart);
      oled.setCursor(0,16);oled.print("Spo2: ");oled.println(spo);
      oled.setCursor(0,32);oled.print("Temp: ");oled.println(temp_str);
      //oled.setCursor(0,64);oled.print("lat: ");oled.println(lat_str);
      //oled.setCursor(32,32);oled.print("long: ");oled.println(lng_str);
      oled.display();
if(d==1 && f==0)
    led.off();
else if(d==0 && f<1)
  {
    f=1;
    led.on();
    Serial.println("BUTTON PRESSED");
    oled.clearDisplay();
    oled.setTextSize(2);
    oled.setTextColor(1);
    oled.setCursor(0, 0);oled.print("SOS SIGNAL SENT!");
    oled.display();
    delay(2000);
  
  
}
void configureMax30100() {
  sensor.setMode(MAX30100_MODE_SPO2_HR);
  sensor.setLedsCurrent(MAX30100_LED_CURR_50MA, MAX30100_LED_CURR_27_1MA);
  sensor.setLedsPulseWidth(MAX30100_SPC_PW_1600US_16BITS);
  sensor.setSamplingRate(MAX30100_SAMPRATE_100HZ);
  sensor.setHighresModeEnabled(true);
}
