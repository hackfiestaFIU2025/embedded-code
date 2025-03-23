#include "Arduino.h"
#include "Wifi.h"
#include "HttpClient.h"
#include "ArduinoJson.h"

#define output 34
#define lowMinus 2
#define lowPlus 4


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  Serial.println("EKG demo");
  pinMode(lowMinus, INPUT);
  pinMode(lowPlus, INPUT);

  WiFi.begin("SimonD@19", "Kowsilla$55$66");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
}

void loop() {

    StaticJsonDocument<2048> doc;
    JsonArray data = doc.to<JsonArray>();
    int start = millis();
    int i = 0;
    while(millis() - start < 10000){
        JsonObject entry = data.createNestedObject();
        if((digitalRead(lowMinus) == 1)||(digitalRead(lowPlus) == 1)){
        entry["voltage"] = 0;
        entry["time"] = millis() - start;
        }
        else{
        // send the value of analog input 0:
        entry["voltage"] = analogRead(output) * (3.3 / 4095.0);
        entry["time"] = millis() - start;
        Serial.println(analogRead(output) * (3.3 / 4095.0));
        }
        delay(25);
        i++;
    }
    String buffer = "";
    serializeJson(doc, buffer);

    if(WiFi.status() == WL_CONNECTED){
        HTTPClient http;
        http.begin("https://beatai-bc460-default-rtdb.firebaseio.com/heart_risk/session/raw_data.json");
        http.addHeader("Content-Type", "application/json");
        http.addHeader("User-Agent", "curl/7.47.0");
        http.addHeader("Cache-Control", "no-cache");
        http.addHeader("Accept", "*/*");
        http.addHeader("Connection", "keep-alive"); 
        int code = http.PUT(buffer);
        String payload = http.getString();  
        http.end();
    }
    delay(5000);

}